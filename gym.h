#ifndef GYM_H
#define GYM_H
#include "property.h"
class Gym : public Property
{
    int price;
    std::string name;
    Monopoly monopoly = Monopoly::gym;
    int impCost = 200;
    int numImps = 0;

public:
    Gym(int price, std::string name);
    void purchase(Player &buyer) override;
    void auction(int amount) override;
    void payTuition(Player &paying, Player &earning) override;
    void addImprovement(Player* owner) override;
    void setNumImps(int num) override;
    int getNumImps() override;
    std::string getName() override;
    int getPrice() override;
    int getTuition() override;
    virtual ~Gym() {}
};
#endif
