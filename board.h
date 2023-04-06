#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <vector>
#include <map>

using namespace std;

class Board
{

    vector<Square *> theBoard;
    map<Square*, Player*> owners;
    vector<Player*> players;
    std::map<std::string, Square*> propertyMap; // Maps string and property name

public:
    Player *currPlayer;
    Board();
    void move();
    void next();
    void trade(Player& other);
    bool Board::hasImprovements(string propertyName);
    ~Board();
    void setPropertyMap();
};
#endif
