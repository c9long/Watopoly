#include "green.h"

Green::Green(int price, std::string name):price{price}, name{name} {
    if (name == "EIT") {
        impTuit.emplace_back(26);
        impTuit.emplace_back(130);
        impTuit.emplace_back(390);
        impTuit.emplace_back(900);
        impTuit.emplace_back(1100);
        impTuit.emplace_back(1275);
    } else if (name == "ESC") {
        impTuit.emplace_back(26);
        impTuit.emplace_back(130);
        impTuit.emplace_back(390);
        impTuit.emplace_back(900);
        impTuit.emplace_back(1100);
        impTuit.emplace_back(1275);
    } else if (name == "C2") {
        impTuit.emplace_back(28);
        impTuit.emplace_back(150);
        impTuit.emplace_back(450);
        impTuit.emplace_back(1000);
        impTuit.emplace_back(1200);
        impTuit.emplace_back(1400);
    }
}

void Green::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Green::addImprovement()
{
    // potentially need to pass in purchasing player to change balance
    if (numImps < 5)
    {
        try
        {
            owner->changeBalance(-impCost);
            ++numImps;
        }
        catch (...)
        {
            std::cout << "Not enough funds to make this purchase" << std::endl;
        }
    }
}

void Green::purchase(Player &buyer)
{
    try
    {
        buyer.changeBalance(-price);
        owner = &buyer;
    }
    catch (...)
    {
        std::cout << "Not enough funds to make this purchase" << std::endl;
    }
}

void Green::auction(){

}

Green::~Green() {
    impTuit.clear();
}
