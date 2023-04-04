#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "square.h"

class NonProperty : public Square
{

public:
    virtual void addImprovement() = 0;
    virtual void payOut(Player &) = 0;
    virtual ~NonProperty() = 0;
};
#endif
