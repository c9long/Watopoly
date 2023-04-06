#include "board.h"
#include "brown.h"
#include "ltblue.h"
#include "pink.h"
#include "orange.h"
#include "red.h"
#include "yellow.h"
#include "green.h"
#include "blue.h"
#include "residence.h"
#include "gym.h"
#include "slc.h"
#include "needles.h"
#include "tuition.h"
#include "goose.h"
#include "gototims.h"
#include "dctims.h"
#include "coopfee.h"
#include "osap.h"
#include "textdisplay.h"

using namespace std;

Board::Board(vector<Player*> players) : players{players} {
    theBoard.emplace_back(new OSAP{});
    theBoard.emplace_back(new Brown{40, "AL"});
    theBoard.emplace_back(new SLC{});
    theBoard.emplace_back(new Brown{60, "ML"});
    theBoard.emplace_back(new Tuition{});
    theBoard.emplace_back(new Residence{});
    theBoard.emplace_back(new LtBlue{100, "ECH"});
    theBoard.emplace_back(new Needles{});
    theBoard.emplace_back(new LtBlue{100, "PAS"});
    theBoard.emplace_back(new LtBlue{120, "HH"});
    theBoard.emplace_back(new DCTims{});
    theBoard.emplace_back(new Pink{140, "RCH"});
    theBoard.emplace_back(new Gym{});
    theBoard.emplace_back(new Pink{140, "DWE"});
    theBoard.emplace_back(new Pink{160, "CPH"});
    theBoard.emplace_back(new Residence{});
    theBoard.emplace_back(new Orange{180, "LHI"});
    theBoard.emplace_back(new SLC{});
    theBoard.emplace_back(new Orange{180, "BMH"});
    theBoard.emplace_back(new Orange{200, "OPT"});
    theBoard.emplace_back(new Goose{});
    theBoard.emplace_back(new Red{220, "EV1"});
    theBoard.emplace_back(new Needles{});
    theBoard.emplace_back(new Red{220, "EV2"});
    theBoard.emplace_back(new Red{240, "EV3"});
    theBoard.emplace_back(new Residence{});
    theBoard.emplace_back(new Yellow{260, "PHYS"});
    theBoard.emplace_back(new Yellow{260, "B1"});
    theBoard.emplace_back(new Gym{});
    theBoard.emplace_back(new Yellow{280, "B2"});
    theBoard.emplace_back(new GoToTims{});
    theBoard.emplace_back(new Green{300, "EIT"});
    theBoard.emplace_back(new Green{300, "ESC"});
    theBoard.emplace_back(new SLC{});
    theBoard.emplace_back(new Green{320, "C2"});
    theBoard.emplace_back(new Residence{});
    theBoard.emplace_back(new Needles{});
    theBoard.emplace_back(new Blue{350, "MC"});
    theBoard.emplace_back(new CoopFee{});
    theBoard.emplace_back(new Blue{400, "DC"});

    setPropertyMap(); 

    td = new Textdisplay{};
}

void Board::updateTD() {
    
}

void Board::trade(Player& other) {
    int itemGiven = -1;
    int itemReceived = -1;

    // Check if trading with self
    if (currPlayer->name == other.name) {
        throw invalid_argument("You cannot trade with yourself!");
    }

    string give, receive;
    cin >> give; cin >> receive;


    // Store amount if either trading items are money
    try {
        itemGiven = stoi(give);
    } catch (exception& e) {
    }

    try {
        itemReceived = stoi(receive);
    } catch (exception& e) {
    }

    // Check if trading money for money
    if ((itemGiven >= 0) && (itemReceived >= 0)) {
        throw invalid_argument("You cannot trade money with money!");
    }

    if (itemGiven == -1) {  // Is a property
        // Check if property being given has improvements
        if (hasImprovements(give)) {
            throw invalid_argument("You cannot trade a property in a monopoly that has improvements!");
        }

        // Check if player owns property being given
        auto it = propertyMap.find(give);
        if (it == propertyMap.end() || owners[it->second] != currPlayer) {
            throw invalid_argument("You cannot trade a property you don't own!");
        }
    }

    // Check if property being received has improvements
    if (itemReceived == -1) {
        if (hasImprovements(receive)) {
            throw invalid_argument("You cannot trade a property in a monopoly that has improvements!");
        }
    }

    // Check if player has enough balance
    if (itemGiven >= 0 && currPlayer->balance < itemGiven) {
        throw invalid_argument("You do not have enough money to do this trade!");
    }
    if (itemReceived >= 0 && other.balance < itemReceived) {
        throw invalid_argument("You do not have enough money to do this trade!");
    }

    cout << other.name << ", would you like to accept this trade? (Y/N)" << endl;

    char c;

    cin >> c;
    if (c == 'Y' || c == 'y') {

    } else {
        
    }
}

bool Board::hasImprovements(string propertyName) {

    if (propertyMap[propertyName]->getNumImps() > 0) return true;

    return false;
}

void Board::setPropertyMap() {
    propertyMap["AL"] = theBoard.at(1);
    propertyMap["ML"] = theBoard.at(3);
    propertyMap["ECH"] = theBoard.at(6);
    propertyMap["PAS"] = theBoard.at(8);
    propertyMap["HH"] = theBoard.at(9);
    propertyMap["RCH"] = theBoard.at(11);
    propertyMap["DWE"] = theBoard.at(13);
    propertyMap["CPH"] = theBoard.at(14);
    propertyMap["LHI"] = theBoard.at(16);
    propertyMap["MBH"] = theBoard.at(18);
    propertyMap["OPT"] = theBoard.at(19);
    propertyMap["EV1"] = theBoard.at(21);
    propertyMap["EV2"] = theBoard.at(23);
    propertyMap["EV3"] = theBoard.at(24);
    propertyMap["PHYS"] = theBoard.at(26);
    propertyMap["B1"] = theBoard.at(27);
    propertyMap["B2"] = theBoard.at(29);
    propertyMap["EIT"] = theBoard.at(31);
    propertyMap["ESC"] = theBoard.at(32);
    propertyMap["C2"] = theBoard.at(34);
    propertyMap["MC"] = theBoard.at(37);
    propertyMap["DC"] = theBoard.at(39);
}

Board::~Board() {
    currPlayer = nullptr;
    theBoard.clear();
    owners.clear();
    players.clear();
    propertyMap.clear();
    delete td;
}

ostream &operator<<(std::ostream &out, const Board &b) {
    out << *(b.td);
    return out;
}