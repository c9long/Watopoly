#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <vector>
#include <map>

using namespace std;

class Board
{

    Player *currPlayer;
    vector<Square *> theBoard;
    map<Square*, Player*> owners;
    vector<Player*> players;

public:
    Board();
    void move();
    void next();
    void trade(Player& other);
    ~Board();
};
#endif
