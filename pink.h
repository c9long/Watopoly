#ifndef PINK_H
#define PINK_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Pink
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::pink;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    Pink(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    void purchase();
};

#endif