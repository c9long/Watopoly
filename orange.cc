#include "orange.h"

Orange::Orange(int price, std::string name):price{price}, name{name} {
    if (name == "LHI") {
        impTuit.emplace_back(14);
        impTuit.emplace_back(70);
        impTuit.emplace_back(200);
        impTuit.emplace_back(550);
        impTuit.emplace_back(750);
        impTuit.emplace_back(950);
    } else if (name == "BMH") {
        impTuit.emplace_back(14);
        impTuit.emplace_back(70);
        impTuit.emplace_back(200);
        impTuit.emplace_back(550);
        impTuit.emplace_back(750);
        impTuit.emplace_back(950);
    } else if (name == "OPT") {
        impTuit.emplace_back(16);
        impTuit.emplace_back(80);
        impTuit.emplace_back(220);
        impTuit.emplace_back(600);
        impTuit.emplace_back(800);
        impTuit.emplace_back(1000);
    }
}

void Orange::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Orange::addImprovement()
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

void Orange::purchase(Player &buyer)
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

void Orange::auction(){

}

Orange::~Orange() {
    impTuit.clear();
}
