#ifndef BLUE_H
#define BLUE_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Blue
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::blue;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    Blue(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    void purchase();
    int getNumImps();
};

#endif