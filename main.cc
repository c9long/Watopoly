#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "board.h"
#include "square.h" // can be changed to forward declaration
#include "textdisplay.h"

using namespace std;

int main(int argc, char *argv[])
{
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

    if (argc > 1)
    {
        string arg = argv[1];
        if (arg == "-load")
        {
            ifstream ifs{argv[2]};
            string s;
            if (ifs >> s)
            {
                numPlayers = stoi(s);
                for (int i = 0; i < numPlayers; ++i)
                {
                    string name;
                    char piece;
                    int timsCups;
                    int balance;
                    int location;
                    int timsLinePos;
                    int turnsInLine;
                    ifs >> name;
                    ifs >> s;
                    piece = s[0];
                    ifs >> s;
                    timsCups = stoi(s);
                    ifs >> s;
                    balance = stoi(s);
                    char c;
                    ifs.get(c);
                    // getline(ifs, location);
                    /* cout << name << endl;
                    cout << piece << endl;
                    cout << timsCups << endl;
                    cout << balance << endl; */
                    cout << location << endl;
                    Player *p;
                    if (location == 10)
                    { // Player may be in DC Tims line
                        ifs >> timsLinePos;
                        // stringstream ss(location);
                        // ss >> timsLinePos;
                        if (timsLinePos > 0)
                        { // Player is in Tims line, otherwise at DC Tims Line but they are not in the DC Tims Line
                            // ss >> turnsInLine;
                            ifs >> turnsInLine;

                            if (turnsInLine >= 0 && turnsInLine <= 2)
                            {
                                // string name, int balance, char piece, bool inJail, int numJailRolls, int locId, int numCups
                                p = new Player{name, balance, piece, true, turnsInLine, location, timsCups};
                            }
                        }
                    }
                    else
                    {
                        p = new Player{name, balance, piece, false, 0, 0, timsCups};
                    }

                    players.emplace_back(p);
                }
                Board b{players};

                // Set each property and its owner and improvements
                string currLine;
                while (getline(ifs, currLine))
                {
                    stringstream ss(currLine);
                    string property;
                    string ownerName;
                    string tmpImpsStr;
                    int numImps;

                    ss >> property >> ownerName >> tmpImpsStr;
                    numImps = stoi(tmpImpsStr);

                    Square *square = b.getPropertyFromMap(property);
                    Player *owner = nullptr;

                    // Find player from player vector and set owner to Player
                    if (ownerName != "BANK")
                    {
                        for (auto p : b.getPlayers())
                        {
                            if (ownerName == p->getName())
                            {
                                owner = p;
                                break;
                            }
                        }
                    }

                    b.addOwner(square, owner);
                    square->setNumImps(numImps);
                }
            }
        }
        else if (arg == "testing")
        {
        }
    }
    else
    {
        while (numPlayers < 2 || numPlayers > 6)
        {
            cout << "How many players would you like to enter into your new game?" << endl;
            cin >> numPlayers;
        }
        for (int i = 0; i < numPlayers; ++i)
        {
            cout << "Enter Player " << i + 1 << "'s name" << endl;
            string name;
            cin >> name;
            cin.clear();
            cout << "Select your piece (G, B, D, P, S, $, L, or T)" << endl;
            char piece;
            cin >> piece;
            while ((piece != 'G' && piece != 'B' && piece != 'D' && piece != 'P' && piece != 'S' && piece != '$' && piece != 'L' && piece != 'T') || pieces[piece])
            {
                cout << "Please choose a valid/available piece" << endl;
                cin >> piece;
            }
            Player *p = new Player{name, 1500, piece, false, 0, 0, 0};
            pieces[piece] = p;
            players.emplace_back(p);
        }
        Board b{players};
        cout << b;

        cout << "Player " << b.currPlayerNum + 1 << " turn!" << endl;
        // while game hasn't ended
        while (!b.gameOver())
        {
            string cmd;
            cin >> cmd;
            while (cmd != "roll" && cmd != "next" && cmd != "trade" && cmd != "improve" && cmd != "mortgage" && cmd != "unmortgage" && cmd != "assets" && cmd != "all" && cmd != "save" && cmd != "bankrupt")
            {
                cout << "Please enter a valid command" << endl;
                cin >> cmd;
            }
            if (cmd == "bankrupt")
            { // and b.currPlayer->isBankrupt()
                cout << "Are you sure you want to declare bankruptcy? (y/n)" << endl;
                cin >> cmd;
                if (cmd == "y")
                {
                    // b.currPlayer->bankrupt() -> begin bankruptcy auctioning process
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
                for (auto it = players.begin(); it != players.end(); ++it) {
                    if ((*it)->getName() == name) {
                        try {
                            b.trade(**it);
                        } catch (invalid_argument& ia) {
                            cout << ia.what() << endl;
                        }
                    }
                }
            }
            else if (cmd == "improve")
            {
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
            }
        }
    }
}
