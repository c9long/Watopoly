#ifndef YELLOW_H
#define YELLOW_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Yellow : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::yellow;
    int impCost = 150;
    int numImps = 0;
    vector<int> impTuit;

public:
    Yellow(int price, string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    void purchase(Player &buyer) override;
    ~Yellow();
};

#endif
