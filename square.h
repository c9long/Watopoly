#ifndef SQUARE_H
#define SQUARE_H
#include "player.h"

class Square
{
public:
    virtual void payTuition(Player &paying, Player &earning) = 0;
    virtual void addImprovement() = 0;
    virtual void payOut(Player&) = 0;
    virtual ~Square(){}
};
#endif
