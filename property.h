#ifndef PROPERTY_H
#define PROPERTY_H
#include "square.h"
#include "player.h"

enum class Monopoly
{
    brown,
    ltblue,
    pink,
    orange,
    red,
    yellow,
    green,
    blue,
    residence,
    gym
};

class Property : public Square
{
public:
    virtual void purchase(Player &buyer) = 0;
    virtual void auction(int amount) = 0;
    virtual void payTuition(Player &paying, Player &earning) = 0;
    virtual void addImprovement(Player* owner) = 0;
    void payOut(Player &affected) override;
    virtual int getNumImps() = 0;
    virtual std::string getName() = 0;
    virtual int getPrice() = 0;
    virtual ~Property() {}
    virtual int getTuition() = 0;
};
#endif
