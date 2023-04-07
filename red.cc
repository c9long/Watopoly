#include "red.h"

Red::Red(int price, std::string name):price{price}, name{name} {
    if (name == "EV1") {
        impTuit.emplace_back(18);
        impTuit.emplace_back(90);
        impTuit.emplace_back(250);
        impTuit.emplace_back(700);
        impTuit.emplace_back(875);
        impTuit.emplace_back(1050);
    } else if (name == "EV2") {
        impTuit.emplace_back(18);
        impTuit.emplace_back(90);
        impTuit.emplace_back(250);
        impTuit.emplace_back(700);
        impTuit.emplace_back(875);
        impTuit.emplace_back(1050);
    } else if (name == "EV3") {
        impTuit.emplace_back(20);
        impTuit.emplace_back(100);
        impTuit.emplace_back(300);
        impTuit.emplace_back(750);
        impTuit.emplace_back(925);
        impTuit.emplace_back(1100);
    }
}

void Red::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Red::addImprovement()
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

void Red::purchase(Player &buyer)
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

void Red::auction(){

}

void Red::setNumImps(int num) {
    numImps = num;
}

int Red::getNumImps() {
    return numImps;
}

Red::~Red() {
    impTuit.clear();
}
