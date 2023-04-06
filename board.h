#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <vector>
#include <map>

using namespace std;

class Textdisplay;

class Board
{
    Textdisplay* td;
    vector<Square *> theBoard;
    map<Square *, Player *> owners;
    vector<Player *> players;
    std::map<std::string, Square *> propertyMap; // Maps string and property name

public:
    Player *currPlayer;
    Board(); // implemented
    void move();
    void next();
    void trade(Player &other); // in progress
    bool hasImprovements(string propertyName); // implemented
    ~Board(); // implemented
    void setPropertyMap(); // implemented
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};
#endif
