#include "ltblue.h"

LtBlue::LtBlue(int price, std::string name):price{price}, name{name} {
    if (name == "ECH") {
        impTuit.emplace_back(6);
        impTuit.emplace_back(30);
        impTuit.emplace_back(90);
        impTuit.emplace_back(270);
        impTuit.emplace_back(400);
        impTuit.emplace_back(550);
    } else if (name == "PAS") {
        impTuit.emplace_back(6);
        impTuit.emplace_back(30);
        impTuit.emplace_back(90);
        impTuit.emplace_back(270);
        impTuit.emplace_back(400);
        impTuit.emplace_back(550);
    } else if (name == "HH") {
        impTuit.emplace_back(8);
        impTuit.emplace_back(40);
        impTuit.emplace_back(100);
        impTuit.emplace_back(300);
        impTuit.emplace_back(450);
        impTuit.emplace_back(600);
    }
}

void LtBlue::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void LtBlue::addImprovement()
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

void LtBlue::purchase(Player &buyer)
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

void LtBlue::auction(){

}

int LtBlue::getNumImps() {
    return numImps;
}

LtBlue::~LtBlue() {
    impTuit.clear();
}
