#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "textdisplay.h"
#include <vector>
#include <map>

class Textdisplay;

class Board
{
    Textdisplay* td;
    std::vector<Square *> theBoard;
    std::map<Square *, Player *> owners;
    std::vector<Player *> players;
    std::map<Player *, char> playerToChar;
    std::map<std::string, Square *> propertyMap; // Maps string and property name
    std::vector<bool> isProperty = {false, true, false, true, false, true, true, false, true, true, false, true, false, true, true, true, true, false, true, true, false, true, false, true, true, true, true, true, false, true, false, true, true, false, true, true, false, true, false, true};
    // Property: 1 3 6 8 9 11 13 14 16 18 19 21 23 24 26 27 29 31 32 34 37 39
    // NonProperty: 0 2 4 7 10 12 17 20 22 28 30 33 36 38
    // need to figure out residences: 5 15 25 35

public:
    Player *currPlayer = nullptr;
    int currPlayerNum;
    int numPieces; // same thing as numPlayers in main but don't want to double on variable names
    Board(std::vector<Player*> players, int numPlayers); // implemented
    bool gameOver();
    void move(bool newRoll = true);
    void next();
    void trade(Player &other); // in progress
    bool hasImprovements(std::string propertyName); // implemented
    ~Board(); // implemented
    std::vector<Player *> getPlayers(); // Getter for players vector
    void setPropertyMap(); // implemented
    Square* getPropertyFromMap(std::string propertyName);
    std::map<Square *, Player *> getOwners();
    void updateTD();
    void addOwner(Square * square, Player* player);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};
#endif
