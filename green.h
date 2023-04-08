#ifndef GREEN_H
#define GREEN_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Green : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::green;
    int impCost = 200;
    int numImps = 0;
    vector<int> impTuit;

public:
    Green(int price, string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    void purchase(Player &buyer) override;
    ~Green();
};

#endif
