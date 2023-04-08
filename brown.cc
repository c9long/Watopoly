#include "brown.h"

Brown::Brown(int price, std::string name) : price{price}, name{name}
{
    if (name == "AL")
    {
        impTuit.emplace_back(2);
        impTuit.emplace_back(10);
        impTuit.emplace_back(30);
        impTuit.emplace_back(90);
        impTuit.emplace_back(160);
        impTuit.emplace_back(250);
    }
    else if (name == "ML")
    {
        impTuit.emplace_back(4);
        impTuit.emplace_back(20);
        impTuit.emplace_back(60);
        impTuit.emplace_back(180);
        impTuit.emplace_back(320);
        impTuit.emplace_back(450);
    }
}

void Brown::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Brown::addImprovement()
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

void Brown::purchase(Player &buyer)
{
    try
    {
        buyer.changeBalance(-price);
        owner = &buyer; // remove this when below error handled by board; remove owner field from property overall
    }
    catch (invalid_argument& ia)
    {
        std::cout << ia.what() << std::endl;
        throw; // re-raise to be handled in Board
    }
}

void Brown::auction(){

}

void Brown::setNumImps(int num) {
    numImps = num;
}

int Brown::getNumImps() {
    return numImps;
}

string Brown::getName() {
    return name;
}

int Brown::getPrice() {
    return price;
}

Brown::~Brown() {
    impTuit.clear();
}
