#include "yellow.h"

Yellow::Yellow(int price, std::string name):price{price}, name{name} {
    if (name == "PHYS") {
        impTuit.emplace_back(22);
        impTuit.emplace_back(110);
        impTuit.emplace_back(330);
        impTuit.emplace_back(800);
        impTuit.emplace_back(975);
        impTuit.emplace_back(1150);
    } else if (name == "B1") {
        impTuit.emplace_back(22);
        impTuit.emplace_back(110);
        impTuit.emplace_back(330);
        impTuit.emplace_back(800);
        impTuit.emplace_back(975);
        impTuit.emplace_back(1150);
    } else if (name == "B2") {
        impTuit.emplace_back(24);
        impTuit.emplace_back(120);
        impTuit.emplace_back(360);
        impTuit.emplace_back(850);
        impTuit.emplace_back(1025);
        impTuit.emplace_back(1200);
    }
}

void Yellow::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Yellow::addImprovement()
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

void Yellow::purchase(Player &buyer)
{
    try
    {
        buyer.changeBalance(-price);
        owner = &buyer;
    }
    catch (invalid_argument ia)
    {
        std::cout << ia.what() << std::endl;
    }
}

void Yellow::auction(){

}

void Yellow::setNumImps(int num) {
    numImps = num;
}

int Yellow::getNumImps() {
    return numImps;
}

string Yellow::getName() {
    return name;
}

int Yellow::getPrice() {
    return price;
}

Yellow::~Yellow() {
    impTuit.clear();
}
