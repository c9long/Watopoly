#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "property.h"
class Residence : public Property
{
    void purchase(Player &buyer) override;
    void auction() override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    ~Residence() {}
};
#endif
