#include "red.h"
using namespace std;

Red::Red(int price, string name) : price{price}, name{name} {
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

void Red::addImprovement(Player* owner)
{
    // potentially need to pass in purchasing player to change balance
    if (numImps < 5)
    {
        try
        {
            owner->changeBalance(-impCost);
            ++numImps;
        }
        catch (invalid_argument& ia)
        {
            std::cout << ia.what() << std::endl;
        }
    }
}

void Red::purchase(Player &buyer)
{
    try
    {
        buyer.changeBalance(-price);
    }
    catch (invalid_argument& ia)
    {
        std::cout << ia.what() << std::endl;
        throw; // re-raise to be handled in Board
    }
}

void Red::auction(int amount){

}

void Red::setNumImps(int num) {
    numImps = num;
}

int Red::getNumImps() {
    return numImps;
}

string Red::getName() {
    return name;
}

int Red::getPrice() {
    return price;
}

Red::~Red() {
    impTuit.clear();
}

int Red::getTuition() {
    return impTuit.at(numImps);
}
