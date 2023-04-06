#ifndef NONPROPERTY_H
#define NONPROPERTY_H
#include "square.h"

class NonProperty : public Square
{

public:
    void purchase(Player &buyer) override;
    void auction() override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    virtual void payOut(Player &affected) = 0;
    int getNumImps() override;
    virtual ~NonProperty();
};
#endif
