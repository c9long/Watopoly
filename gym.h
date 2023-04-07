#ifndef GYM_H
#define GYM_H
#include "property.h"
class Gym : public Property
{
    void purchase(Player &buyer) override;
    void auction() override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    virtual ~Gym() {}
};
#endif
