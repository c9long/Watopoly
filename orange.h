#ifndef ORANGE_H
#define ORANGE_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Orange
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::orange;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    Orange(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    void purchase();
};

#endif