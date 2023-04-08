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
    blue
};

class Property : public Square
{
protected:
    Player *owner = nullptr;

public:
    virtual void purchase(Player &buyer) = 0;
    virtual void auction() = 0;
    virtual void payTuition(Player &paying, Player &earning) = 0;
    virtual void addImprovement() = 0;
    void payOut(Player &affected) override;
    virtual int getNumImps() = 0;
    virtual std::string getName() = 0;
    virtual int getPrice() = 0;
    virtual ~Property() { owner = nullptr; }
};
#endif
