#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "textdisplay.h"
#include <vector>
#include <map>

using namespace std;

class Board
{
    Textdisplay* td;
    vector<Square *> theBoard;
    map<Square *, Player *> owners;
    vector<Player *> players;
    std::map<std::string, Square *> propertyMap; // Maps string and property name

public:
    Player *currPlayer;
    Board(vector<Player*> players); // implemented
    bool gameOver();
    void move();
    void next();
    void trade(Player &other); // in progress
    bool hasImprovements(string propertyName); // implemented
    ~Board(); // implemented
    vector<Player *> getPlayers(); // Getter for players vector
    void setPropertyMap(); // implemented
    Square* getPropertyFromMap(std::string propertyName);
    void updateTD();
    void addOwner(Square * square, Player* player);

    friend ostream &operator<<(std::ostream &out, const Board &b);
};
#endif
