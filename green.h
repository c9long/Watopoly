#ifndef GREEN_H
#define GREEN_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Green
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::green;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    Green(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    void purchase();
    int getNumImps();
};

#endif