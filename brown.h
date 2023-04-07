#ifndef BROWN_H
#define BROWN_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Brown : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::brown;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    Brown(int price, string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void purchase(Player& buyer) override;
    void setNumImps(int num) override;
    int getNumImps() override;
    
    ~Brown();
};

#endif
