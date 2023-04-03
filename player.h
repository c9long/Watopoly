#ifndef PLAYER_H
#define PLAYER_H

class Square;
class Player
{
protected:
    int balance;
    char piece;
    bool inJail;
    int numJailRolls;
    int locID;
    Square* location;
    void roll();
    void next();
    void trade(string name);
public:
    void changeBalance(int x);
};
#endif
