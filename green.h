#ifndef GREEN_H
#define GREEN_H
#include "property.h"
#include <string>
#include <vector>

class Green : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::green;
    int impCost = 200;
    int numImps = 0;
    std::vector<int> impTuit;

public:
    Green(int price, std::string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement(Player* owner) override;
    void auction(int amount) override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    void purchase(Player &buyer) override;
    int getTuition() override;
    ~Green();
};

#endif
