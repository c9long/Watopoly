#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "property.h"
class Residence : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::residence;
    int impCost = 200;
    int numImps = 0;

public:
    Residence(int price, std::string name);
    void purchase(Player &buyer) override;
    void auction(int amount) override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    int getTuition() override;
    ~Residence() {}
};
#endif
