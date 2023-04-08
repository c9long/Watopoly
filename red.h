#ifndef RED_H
#define RED_H
#include "property.h"
#include <string>
#include <vector>
using namespace std;
class Red : public Property
{
    int price;
    string name;
    Monopoly monopoly = Monopoly::red;
    int impCost = 150;
    int numImps = 0;
    vector<int> impTuit;

public:
    Red(int price, string name);
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement() override;
    void auction() override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    void purchase(Player &buyer) override;
    ~Red();
};

#endif
