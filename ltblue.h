#ifndef LTBLUE_H
#define LTBLUE_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class LtBlue
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::ltblue;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    LtBlue(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    void purchase();
    int getNumImps();
};

#endif