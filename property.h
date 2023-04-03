#ifndef PROPERTY_H
#define PROPERTY_H
#include "square.h"

enum class Monopoly {brown, ltblue, pink, orange, red, yellow, green, blue};

class Property
{
public:
    virtual void purchase() = 0;
    virtual void auction() = 0;
    virtual void payTuition(Player& paying, Player& earning) = 0;
    virtual void addImprovement() = 0;
    void payOut(Player &){};
    virtual ~Property(){}
};
#endif
