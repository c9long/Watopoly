#include "green.h"

using namespace std;

Green::Green(int price, string name):price{price}, name{name} {
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

void Green::addImprovement(Player* owner)
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
    }
    catch (invalid_argument& ia)
    {
        std::cout << ia.what() << std::endl;
        throw; // re-raise to be handled in Board
    }
}

void Green::auction(int amount){

}

void Green::setNumImps(int num) {
    numImps = num;
}

int Green::getNumImps() {
    return numImps;
}

string Green::getName() {
    return name;
}

int Green::getPrice() {
    return price;
}

Green::~Green() {
    impTuit.clear();
}

int Green::getTuition() {
    return impTuit.at(numImps);
}
