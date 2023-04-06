#ifndef ORANGE_H
#define ORANGE_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Orange : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::orange;
    int impCost = 100;
    int numImps = 0;
    vector<int> impTuit;

public:
    Orange(int price, string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement();
    void auction();
    int getNumImps();
    void purchase(Player &buyer);
    ~Orange();
};

#endif
