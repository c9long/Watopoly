#ifndef GYM_H
#define GYM_H
#include "property.h"
class Gym : public Property
{
    virtual void purchase(Player &buyer) override;
    virtual void auction() override;
    virtual void payTuition(Player &paying, Player &earning) override;
    virtual void addImprovement() override{};
    void payOut(Player &affected) override{};
    int getNumImps() override{};
    ~Gym() {}
};
#endif
