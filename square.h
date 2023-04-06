#ifndef SQUARE_H
#define SQUARE_H
#include "player.h"
#include <iostream>

class Square
{
public:
    virtual void purchase(Player &buyer) = 0;
    virtual void auction() = 0;
    virtual void payTuition(Player &paying, Player &earning) = 0;
    virtual void addImprovement() = 0;
    virtual void payOut(Player &affected) = 0;
    virtual int getNumImps() = 0;
    virtual ~Square() {}
};
#endif
