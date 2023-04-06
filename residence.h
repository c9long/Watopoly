#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "property.h"
class Residence : public Property
{
    virtual void purchase(Player &buyer) override;
    virtual void auction() override;
    virtual void payTuition(Player &paying, Player &earning) override;
    virtual void addImprovement() override{};
    void payOut(Player &affected) override{};
    int getNumImps() override{};
    ~Residence() {}
};
#endif
