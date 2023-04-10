#ifndef RED_H
#define RED_H
#include "property.h"
#include <string>
#include <vector>

class Red : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::red;
    int impCost = 150;
    int numImps = 0;
    std::vector<int> impTuit;

public:
    Red(int price, std::string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    void purchase(Player &buyer) override;
    int getTuition() override;
    ~Red();
};

#endif
