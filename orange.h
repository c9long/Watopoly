#ifndef ORANGE_H
#define ORANGE_H
#include "property.h"
#include <string>
#include <vector>

class Orange : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::orange;
    int impCost = 100;
    int numImps = 0;
    std::vector<int> impTuit;

public:
    Orange(int price, std::string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    void purchase(Player &buyer) override;
    ~Orange();
};

#endif
