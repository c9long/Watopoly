#ifndef LTBLUE_H
#define LTBLUE_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class LtBlue : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::ltblue;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    LtBlue(int price, string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement();
    void auction();
    int getNumImps();
    void purchase(Player &buyer);
    ~LtBlue();
};

#endif
