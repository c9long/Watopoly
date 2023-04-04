#ifndef RED_H
#define RED_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Red
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::red;
    int impCost = 50;
    int numImps = 0;
    vector<int> impTuit;

public:
    Red(int price, string name);
    void payTuition(Player &paying, Player &earning);
    void addImprovement();
    void auction();
    void purchase();
    int getNumImps();
};

#endif