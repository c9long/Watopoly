#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "property.h"
class Residence : public Property
{
    void purchase(Player &buyer) override;
    void auction() override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    int getNumImps() override;
    ~Residence() {}
};
#endif
