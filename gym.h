#ifndef GYM_H
#define GYM_H
#include "property.h"
class Gym : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::gym;
    int impCost = 200;
    int numImps = 0;

public:
    void purchase(Player &buyer) override;
    void auction() override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    virtual ~Gym() {}
};
#endif
