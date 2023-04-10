#ifndef SQUARE_H
#define SQUARE_H
#include "player.h"
#include <iostream>

class Square
{
public:
    virtual void purchase(Player &buyer) = 0;
    virtual void auction(int amount) = 0;
    virtual void payTuition(Player &paying, Player &earning) = 0;
    virtual void addImprovement(Player* owner) = 0;
    virtual void payOut(Player &affected) = 0;
    virtual void setNumImps(int num) = 0;
    virtual int getNumImps() = 0;
    virtual std::string getName() = 0;
    virtual int getPrice() = 0;
    virtual ~Square() {}
    virtual int getTuition() = 0;
};
#endif
