#ifndef BLUE_H
#define BLUE_H
#include "property.h"
#include <string>
#include <vector>

class Blue : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::blue;
    int impCost = 200;
    int numImps = 0;
    std::vector<int> impTuit;

public:
    Blue(int price, std::string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void purchase(Player& buyer) override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    int getTuition() override;
    
    ~Blue();
};

#endif