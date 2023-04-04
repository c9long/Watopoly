#ifndef BLUE_H
#define BLUE_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Blue : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::blue;
    int impCost = 200;
    int numImps = 0;
    vector<int> impTuit;

public:
    Blue(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    int getNumImps();
    void purchase(Player &buyer);
    ~Blue();
};

#endif