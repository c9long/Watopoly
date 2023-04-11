#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "board.h"
#include "square.h"  // can be changed to forward declaration
#include "textdisplay.h"

using namespace std;

int main(int argc, char *argv[]) {
    int numPlayers = 0;
    vector<Player *> players;
    map<char, Player *> pieces;
    map<Player *, char> playerToChar;
    pieces['G'] = nullptr;
    pieces['B'] = nullptr;
    pieces['D'] = nullptr;
    pieces['P'] = nullptr;
    pieces['S'] = nullptr;
    pieces['$'] = nullptr;
    pieces['L'] = nullptr;
    pieces['T'] = nullptr;

    if (argc > 1) {
        string arg = argv[1];
        if (arg == "-load") {
            ifstream ifs{argv[2]};
            string s;
            if (ifs >> s) {
                numPlayers = stoi(s);
                for (int i = 0; i < numPlayers; ++i) {
                    string name = "";
                    char piece = '\0';
                    int timsCups = 0;
                    int balance = 0;
                    int location = 0;
                    int timsLinePos = 0;
                    int turnsInLine = 0;
                    int playerNum = i;
                    ifs >> name;
                    cout << "Name " << name << endl;
                    ifs >> s;
                    piece = s[0];
                    cout << "Piece " << piece << endl;  // good
                    ifs >> s;
                    // cout << "s is nwo " << s << endl;
                    // timsCups = stoi(s);
                    try {
                        timsCups = stoi(s);
                    } catch (const std::invalid_argument &e) {
                        // handle the error
                        cout << "can't convert " << s << " using stoi !!" << endl;
                    }
                    ifs >> s;
                    balance = stoi(s);
                    cout << "balance is " << balance << endl;
                    ifs >> s;
                    location = stoi(s);
                    char c;
                    ifs.get(c);
                    // getline(ifs, location);
                    /* cout << name << endl;
                    cout << piece << endl;
                    cout << timsCups << endl;
                    cout << balance << endl; */

                    cout << "location " << location << endl;
                    Player *p;
                    if (location == 10) {  // Player may be in DC Tims line
                        cout << "player position at 10 " << endl;
                        ifs >> timsLinePos;
                        // stringstream ss(location);
                        // ss >> timsLinePos;
                        if (timsLinePos > 0) {  // Player is in Tims line, otherwise at DC Tims Line but they are not in the DC Tims Line
                            // ss >> turnsInLine;
                            ifs >> turnsInLine;

                            if (turnsInLine >= 0 && turnsInLine <= 2) {
                                // string name, int balance, char piece, bool inJail, int numJailRolls, int locId, int numCups
                                p = new Player{name, balance, piece, true, turnsInLine, location, timsCups, playerNum};
                            }
                        }
                    } else {
                        p = new Player{name, balance, piece, false, 0, 0, timsCups, playerNum};
                    }

                    players.emplace_back(p);
                    cout << "PLAYER PLACED BACK" << endl;
                }
                Board b{players, numPlayers};

                // Set each property and its owner and improvements
                // ifs >> s;
                // cout << "ahhh" << s << endl;
                char c;

                string currLine;
                while (getline(ifs, currLine)) {
                    cout << "INSIDE WHILE HERE " << endl;
                    stringstream ss(currLine);
                    string property = "";
                    string ownerName = "";
                    string tmpImpsStr = "";
                    int numImps = 0;

                    // cout << "-----------" << currLine << endl;

                    ss >> property >> ownerName >> tmpImpsStr;
                    // ss >> property;
                    // cout << "property:"  << property << endl;
                    // ss >> ownerName;
                    // ss >> tmpImpsStr;
                    cout << "Send help " << property << " " << ownerName << " " << tmpImpsStr << endl;
                    numImps = stoi(tmpImpsStr);

                    // cout << "after numImps " << endl;

                    Square *square = b.getPropertyFromMap(property);
                    Player *owner = nullptr;

                    // Find player from player vector and set owner to Player
                    if (ownerName != "BANK") {
                        for (auto p : b.getPlayers()) {
                            if (ownerName == p->getName()) {
                                owner = p;
                                break;
                            }
                        }
                    }

                    b.addOwner(square, owner);
                    square->setNumImps(numImps);
                }
            }
        } else if (arg == "testing") {
        }
    } else {
        while (numPlayers < 2 || numPlayers > 6) {
            cout << "How many players would you like to enter into your new game?" << endl;
            cin >> numPlayers;
        }
        for (int i = 0; i < numPlayers; ++i) {
            cout << "Enter Player " << i + 1 << "'s name" << endl;
            string name;
            cin >> name;
            cin.clear();
            cout << "Select your piece (G, B, D, P, S, $, L, or T)" << endl;
            char piece;
            cin >> piece;
            while ((piece != 'G' && piece != 'B' && piece != 'D' && piece != 'P' && piece != 'S' && piece != '$' && piece != 'L' && piece != 'T') || pieces[piece]) {
                cout << "Please choose a valid/available piece" << endl;
                cin >> piece;
            }
            Player *p = new Player{name, 1500, piece, false, 0, 0, 0, i};
            pieces[piece] = p;
            players.emplace_back(p);
        }
    }
    Board b{players, numPlayers};
    // b.numPieces = numPlayers;
    // cout << b;

    cout << "Player " << b.currPlayerNum + 1 << " turn!" << endl;
    // while game hasn't ended
    while (!b.gameOver())
    {
        string cmd;
        cin >> cmd;
        while (cmd != "roll" && cmd != "next" && cmd != "trade" && cmd != "improve" && cmd != "mortgage" && cmd != "unmortgage" && cmd != "assets" && cmd != "all" && cmd != "save" && cmd != "bankrupt")
        {
            if (cin.eof())
                break;
            cout << "Please enter a valid command" << endl;
            cin >> cmd;
        }
        if (cmd == "bankrupt")
        { // and b.currPlayer->isBankrupt()
            cout << "Are you sure you want to declare bankruptcy? (y/n)" << endl;
            cin >> cmd;
            if (cmd == "y")
            {
                // b.bankrupt() -> begin bankruptcy auctioning process
            }
            else
            {
                cin >> cmd;
                continue;
            }
        }
        else if (cmd == "roll")
        {
            b.move();
        }
        else if (cmd == "next")
        {
            b.next();
        }
        else if (cmd == "trade")
        {
            string name;
            cin >> name;
            for (auto it = players.begin(); it != players.end(); ++it)
            {
                if ((*it)->getName() == name)
                {
                    try
                    {
                        b.trade(**it);
                    }
                    catch (invalid_argument &ia)
                    {
                        cout << ia.what() << endl;
                    }
                }
            }
        }
        else if (cmd == "improve")
        {
            cout << "Enter the name of the property you would like to improve" << endl;
            string name;
            cin >> name;
            b.improve(name);
        }
        else if (cmd == "mortgage")
        {
        }
        else if (cmd == "unmortgage")
        {
        }
        else if (cmd == "assets")
        {
        }
        else if (cmd == "all")
        {
        }
        else if (cmd == "save")
        {
            string fileName;
            cin >> fileName;
            ofstream outfile{fileName + ".txt"};

            outfile << b.getPlayers().size() << endl; // Save num players

            // player char TimsCups money position -- normal
            // player char TimsCups money 10 0 -- at DC not in jail
            // player char TimsCups money 10 1 num -- in jail
            string playerName;
            char playerPiece;
            int playerTimsCups;
            int playerMoney;
            int playerPosition;
            int inJail; // Stored as bool in player, but needs to be int when written in file
            int turnsInLine;

            for (auto it = b.getPlayers().begin(); it != b.getPlayers().end(); ++it)
            {                                     // loop through players vec
                cout << (*it)->getName() << endl; // remove later
                playerName = (*it)->getName();
                playerPiece = (*it)->getPiece();
                playerTimsCups = (*it)->getNumCups();
                playerMoney = (*it)->getBalance();
                playerPosition = (*it)->getLocId();
                inJail = (*it)->getInJail();
                turnsInLine = (*it)->getNumJailRolls();

                outfile << playerName << " " << playerPiece << " " << playerTimsCups << " " << playerMoney << " " << playerPosition;

                if (playerPosition == 10)
                {
                    if (inJail)
                    {
                        outfile << " " << inJail << " " << turnsInLine;
                    }
                    else
                    {
                        outfile << " " << inJail;
                    }
                }
                outfile << endl;
            }

            string propertyNames[] = {"AL", "ML", "MKV", "ECH", "PAS", "HH", "RCH", "PAC", "DWE", "CPH",
                                      "UWP", "LHI", "BMH", "OPT", "EV1", "EV2", "EV3", "V1", "PHYS", "B1",
                                      "CIF", "B2", "EIT", "ESC", "C2", "REV", "MC", "DC"}; // arr of all properties (including residences)
            Square *square;
            map<Square *, Player *> ownersMap = b.getOwners();
            Player *player;
            int improvements;
            for (int i = 0; i < sizeof(propertyNames) / sizeof(propertyNames[0]); i++)
            {
                square = b.getPropertyFromMap(propertyNames[i]);
                player = nullptr;
                improvements = 0;

                if (ownersMap.count(square) > 0)
                { // Property  has owner
                    improvements = square->getNumImps();
                    outfile << square->getName() << " " << player->getName() << " " << improvements << endl; // format: AL owner improvements -- buildings
                }
                else
                { // BANK owns property
                    outfile << square->getName() << " BANK " << improvements << endl;
                }
            }
        }
    }
}
