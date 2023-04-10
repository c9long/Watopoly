#ifndef LTBLUE_H
#define LTBLUE_H
#include "property.h"
#include <string>
#include <vector>

class LtBlue : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::ltblue;
    int impCost = 50;
    int numImps = 0;
    std::vector<int> impTuit;

public:
    LtBlue(int price, std::string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    void purchase(Player &buyer) override;
    void getTuition() override;
    ~LtBlue();
};

#endif
