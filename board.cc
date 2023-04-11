#include "board.h"

#include <iostream>

#include "blue.h"
#include "brown.h"
#include "coopfee.h"
#include "dctims.h"
#include "goose.h"
#include "gototims.h"
#include "green.h"
#include "gym.h"
#include "ltblue.h"
#include "needles.h"
#include "orange.h"
#include "osap.h"
#include "pink.h"
#include "red.h"
#include "residence.h"
#include "slc.h"
#include "textdisplay.h"
#include "tuition.h"
#include "yellow.h"

using namespace std;

Board::Board(vector<Player *> players, int numPlayers) : players{players}, numPieces{numPlayers}
{
    theBoard.emplace_back(new OSAP{});
    theBoard.emplace_back(new Brown{40, "AL"});
    theBoard.emplace_back(new SLC{});
    theBoard.emplace_back(new Brown{60, "ML"});
    theBoard.emplace_back(new Tuition{});
    theBoard.emplace_back(new Residence{200, "MKV"});
    theBoard.emplace_back(new LtBlue{100, "ECH"});
    theBoard.emplace_back(new Needles{});
    theBoard.emplace_back(new LtBlue{100, "PAS"});
    theBoard.emplace_back(new LtBlue{120, "HH"});
    theBoard.emplace_back(new DCTims{});
    theBoard.emplace_back(new Pink{140, "RCH"});
    theBoard.emplace_back(new Gym{150, "PAC"});
    theBoard.emplace_back(new Pink{140, "DWE"});
    theBoard.emplace_back(new Pink{160, "CPH"});
    theBoard.emplace_back(new Residence{200, "UWP"});
    theBoard.emplace_back(new Orange{180, "LHI"});
    theBoard.emplace_back(new SLC{});
    theBoard.emplace_back(new Orange{180, "BMH"});
    theBoard.emplace_back(new Orange{200, "OPT"});
    theBoard.emplace_back(new Goose{});
    theBoard.emplace_back(new Red{220, "EV1"});
    theBoard.emplace_back(new Needles{});
    theBoard.emplace_back(new Red{220, "EV2"});
    theBoard.emplace_back(new Red{240, "EV3"});
    theBoard.emplace_back(new Residence{200, "V1"});
    theBoard.emplace_back(new Yellow{260, "PHYS"});
    theBoard.emplace_back(new Yellow{260, "B1"});
    theBoard.emplace_back(new Gym{150, "CIF"});
    theBoard.emplace_back(new Yellow{280, "B2"});
    theBoard.emplace_back(new GoToTims{});
    theBoard.emplace_back(new Green{300, "EIT"});
    theBoard.emplace_back(new Green{300, "ESC"});
    theBoard.emplace_back(new SLC{});
    theBoard.emplace_back(new Green{320, "C2"});
    theBoard.emplace_back(new Residence{200, "REV"});
    theBoard.emplace_back(new Needles{});
    theBoard.emplace_back(new Blue{350, "MC"});
    theBoard.emplace_back(new CoopFee{});
    theBoard.emplace_back(new Blue{400, "DC"});

    setPropertyMap();

    td = new Textdisplay{};
    td->notify(*this);
    currPlayerNum = 0;
    currPlayer = players[currPlayerNum];
}

void Board::improve(string name) {
    Square* prop = propertyMap[name];
    if (owners[prop] == currPlayer) {
        prop->addImprovement(currPlayer);
    } else {
        cout << "You cannot improve a property you don't own" << endl;
    }
}

void Board::bankrupt() {
    for (auto it : owners) {
        if (it.second == currPlayer) {
            auction(it.first);
        }
    }
    players.erase(players.begin() + currPlayerNum);
}

void Board::move(bool newRoll)
{
    if (!currPlayer->getCanRollAgain()) {
        cout << "You cannot roll again" << endl;
        return;
    } 
    if (newRoll)
    {
        currPlayer->roll();
    }
    if (currPlayer->getInJail() && currPlayer->getNumJailRolls() > 0) {
        next();
        return;
    }
    currPlayer->oldLocId = currPlayer->locId;
    if (currPlayer->getNumDoubleRolls() == 3) {
        cout << "You rolled 3 doubles in a row, so you're going to the DC Tims Line" << endl;
        currPlayer->locId = 10;
        currPlayer->toggleInJail();
    } else {
        currPlayer->locId = (currPlayer->locId + currPlayer->rollSum) % 40;
    }
    int index = currPlayer->locId;
    updateTD();
    if (isProperty[index])
    {
        Square *currProperty = theBoard[index];
        if (!owners[currProperty])
        {
            // we need a function that calculates the amount owed for the property you're on
            // makes it easier to have bankrupt in board, rather than in each property
            int propertyPrice = currProperty->getPrice();
            cout << "You landed on an unowned property. Would you like to purchase " << currProperty->getName() << " for $" << propertyPrice << "? Your balance is $" << currPlayer->balance << " [y/n]" << endl;
            // input decision -> purchase or auction
            char buying;
            cin >> buying;

            if (buying == 'y')
            {
                // Check if able to pay
                if (currPlayer->balance >= propertyPrice)
                {
                    // Update player balance
                    try
                    {
                        currProperty->purchase(*currPlayer);
                        addOwner(currProperty, currPlayer);
                        cout << "You purchased " << currProperty->getName() << ". Your new balance is $" << currPlayer->balance << endl;
                    }
                    catch (invalid_argument &)
                    {
                    }
                }
            }
            else
            {
                auction(currProperty);
            }
        }
        else if (owners[theBoard[index]] != currPlayer)
        {
            cout << "You landed on someone else's property. You owe " << owners[theBoard[index]]->getName() << " $" << theBoard[index]->getTuition() << "!" << endl;
            while (currPlayer->balance < theBoard[index]->getTuition())
            {
                cout << "You must achieve a balance that will allow you to pay your tuition. Your current balance is $" << currPlayer->balance << endl;
                cout << "Would you like to mortgage a property, sell improvements, or trade with another player?" << endl;
                string cmd;
                cin >> cmd;
                if (cmd == "mortgage")
                {
                }
                else if (cmd == "sell")
                {
                }
                else if (cmd == "trade")
                {
                }
            }
        }
    }
    else
    {
        // if landed on slc, need to move again, without rolling, using the changed rollSum value
        if (index == 2 || index == 17 || index == 33)
        {
            cout << "You landed on SLC" << endl;
            theBoard[index]->payOut(*currPlayer);
            move(false);
        }
        else if (index == 7 || index == 22 || index == 36)
        {
            cout << "You landed on Needles Hall" << endl;
            theBoard[index]->payOut(*currPlayer);
        } 
        else if (index == 30) {
            cout << "You landed on Go To Tims" << endl;
            theBoard[index]->payOut(*currPlayer);
            move(false);
        }
        else if (index == 10) {
            if (currPlayer->getInJail()) {
                cout << "You're in the DC Tims Line" << endl;
                currPlayer->numDoubleRolls = 0;
                currPlayer->numJailRolls = 0;
                next();
                return;
            }
            else {
                cout << "You're visiting the DC Tims Line" << endl;
            }
        } 
        else {
            theBoard[index]->payOut(*currPlayer);
        }
    }
    // need to implement rolling doubles
    if (currPlayer->getNumDoubleRolls() > 0 && !currPlayer->getInJail()) {
        currPlayer->canRollAgain = true;
        cout << "You rolled doubles, so you're able to roll again" << endl;
    } else {
        currPlayer->canRollAgain = false;
    }
}

void Board::next()
{
    currPlayer->canRollAgain = true;
    currPlayer->numDoubleRolls = 0;
    currPlayerNum = (currPlayerNum + 1) % numPieces;
    currPlayer = players[currPlayerNum];
    cout << "Player " << currPlayerNum + 1 << " turn!" << endl;
    // this->updateTD();
}

void Board::updateTD()
{
    td->notify(*this);
}

bool Board::gameOver()
{
    return (players.size() == 1);
}

void Board::trade(Player &other)
{
    int itemGiven = -1;
    int itemReceived = -1;

    // Check if trading with self
    if (currPlayer->name == other.name)
    {
        throw invalid_argument("You cannot trade with yourself!");
    }

    string give, receive;
    cin >> give;
    cin >> receive;

    // Store amount if either trading items are money
    try
    {
        itemGiven = stoi(give);
    }
    catch (exception &e)
    {
    }

    try
    {
        itemReceived = stoi(receive);
    }
    catch (exception &e)
    {
    }

    // Check if trading money for money
    if ((itemGiven >= 0) && (itemReceived >= 0))
    {
        throw invalid_argument("You cannot trade money with money!");
    }

    if (itemGiven == -1)
    { // Is a property
        // Check if property being given has improvements
        if (hasImprovements(give))
        {
            throw invalid_argument("You cannot trade a property in a monopoly that has improvements!");
        }

        // Check if player owns property being given
        auto it = propertyMap.find(give);
        if (it == propertyMap.end() || owners[it->second] != currPlayer)
        {
            throw invalid_argument("You cannot trade a property you don't own!");
        }
    }

    // Check if property being received has improvements
    if (itemReceived == -1)
    {
        if (hasImprovements(receive))
        {
            throw invalid_argument("You cannot trade a property in a monopoly that has improvements!");
        }
    }

    // Check if player has enough balance
    if (itemGiven >= 0 && currPlayer->balance < itemGiven)
    {
        throw invalid_argument("You do not have enough money to do this trade!");
    }
    if (itemReceived >= 0 && other.balance < itemReceived)
    {
        throw invalid_argument("You do not have enough money to do this trade!");
    }

    cout << other.name << ", would you like to accept this trade? (y/n)" << endl;

    char c;

    cin >> c;
    if (c == 'Y' || c == 'y')
    {
    }
    else
    {
    }
}

bool Board::hasImprovements(string propertyName)
{
    if (propertyMap[propertyName]->getNumImps() > 0)
        return true;

    return false;
}

vector<Player *> Board::getPlayers()
{
    return players;
}

void Board::setPropertyMap()
{
    propertyMap["AL"] = theBoard.at(1);
    propertyMap["ML"] = theBoard.at(3);
    propertyMap["MKV"] = theBoard.at(5);
    propertyMap["ECH"] = theBoard.at(6);
    propertyMap["PAS"] = theBoard.at(8);
    propertyMap["HH"] = theBoard.at(9);
    propertyMap["RCH"] = theBoard.at(11);
    propertyMap["PAC"] = theBoard.at(12);
    propertyMap["DWE"] = theBoard.at(13);
    propertyMap["CPH"] = theBoard.at(14);
    propertyMap["UWP"] = theBoard.at(15);
    propertyMap["LHI"] = theBoard.at(16);
    propertyMap["BMH"] = theBoard.at(18);
    propertyMap["OPT"] = theBoard.at(19);
    propertyMap["EV1"] = theBoard.at(21);
    propertyMap["EV2"] = theBoard.at(23);
    propertyMap["EV3"] = theBoard.at(24);
    propertyMap["V1"] = theBoard.at(25);
    propertyMap["PHYS"] = theBoard.at(26);
    propertyMap["B1"] = theBoard.at(27);
    propertyMap["CIF"] = theBoard.at(28);
    propertyMap["B2"] = theBoard.at(29);
    propertyMap["EIT"] = theBoard.at(31);
    propertyMap["ESC"] = theBoard.at(32);
    propertyMap["C2"] = theBoard.at(34);
    propertyMap["REV"] = theBoard.at(35);
    propertyMap["MC"] = theBoard.at(37);
    propertyMap["DC"] = theBoard.at(39);
}

Square *Board::getPropertyFromMap(std::string propertyName)
{
    return propertyMap[propertyName];
}

std::map<Square *, Player *> Board::getOwners()
{
    return owners;
}

void Board::addOwner(Square *square, Player *player)
{
    owners[square] = player;
}

void Board::auction(Square *property)
{
    /* cout << "You did not buy this property" << endl;  change to auction */
    vector<bool> inAuction;
    int numParticipants = 0;
    int bid = 0;
    for (int i = 0; i < players.size(); ++i)
    {
        cout << players.at(i)->getName() << ", would you like to place a bid? (y/n)" << endl;
        char c;
        cin >> c;
        while (c != 'y' && c != 'n')
        {
            cout << "Please indicate whether you would like to participate in the auction or not (y/n)" << endl;
            cin >> c;
        }
        if (c == 'y')
        {
            inAuction.emplace_back(true);
            ++numParticipants;
            cout << "What is your bid? Existing bid is $" << bid << endl;
            int input = 0;
            cin >> input;
            while (input <= bid || input > players.at(i)->balance)
            {
                cout << "Your bid is invalid. You must either bid higher than the existing bid, or you do not have the funds to support this bid." << endl;
                cin >> input;
            }
            bid = input;
        }
        else
        {
            inAuction.emplace_back(false);
        }
    }
    while (numParticipants > 1)
    {
        for (int i = 0; i < inAuction.size(); ++i)
        {
            if (inAuction.at(i) && players.at(i)->balance <= bid)
            {
                cout << "You no longer have the means to continue bidding. You have been withdrawn from the auction." << endl;
                --numParticipants;
                inAuction.at(i) = !inAuction.at(i);
            }
            else if (inAuction.at(i))
            {
                cout << players.at(i)->getName() << ", would you like to place a bid? (y/n)" << endl;
                char c;
                cin >> c;
                while (c != 'y' && c != 'n')
                {
                    cout << "Please indicate whether you would like to continue in the auction or not (y/n)" << endl;
                    cin >> c;
                }
                if (c == 'y')
                {
                    cout << "What is your bid? Existing bid is $" << bid << endl;
                    int input = 0;
                    cin >> input;
                    while (input <= bid || input > players.at(i)->balance)
                    {
                        cout << "Your bid is invalid. You must either bid higher than the existing bid, or you do not have the funds to support this bid." << endl;
                        cin >> input;
                    }
                    bid = input;
                }
                else
                {
                    cout << "You have withdrawn from this auction." << endl;
                    --numParticipants;
                    inAuction.at(i) = !inAuction.at(i);
                    if (numParticipants == 1)
                        break;
                }
            }
        }
    }

    for (int i = 0; i < inAuction.size(); ++i)
    {
        if (inAuction.at(i))
        {
            players.at(i)->changeBalance(-bid);
            cout << "Congratulations on winning the auction, " << players.at(i)->getName() << "! You have purchased " << property->getName() << " for $" << bid << endl;
            owners[property] = players.at(i);
        }
    }
}

Board::~Board()
{
    currPlayer = nullptr;
    theBoard.clear();
    owners.clear();
    players.clear();
    propertyMap.clear();
    delete td;
}

ostream &operator<<(std::ostream &out, const Board &b)
{
    out << *(b.td);
    return out;
}
