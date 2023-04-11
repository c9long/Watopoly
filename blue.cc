#include "blue.h"
using namespace std;

Blue::Blue(int price, string name):price{price}, name{name} {
    if (name == "MC") {
        impTuit.emplace_back(35);
        impTuit.emplace_back(175);
        impTuit.emplace_back(500);
        impTuit.emplace_back(1100);
        impTuit.emplace_back(1300);
        impTuit.emplace_back(1500);
    } else if (name == "DC") {
        impTuit.emplace_back(50);
        impTuit.emplace_back(200);
        impTuit.emplace_back(600);
        impTuit.emplace_back(1400);
        impTuit.emplace_back(1700);
        impTuit.emplace_back(2000);
    }
}

void Blue::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Blue::addImprovement(Player* owner)
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

void Blue::purchase(Player &buyer)
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

void Blue::auction(int amount){

}

void Blue::setNumImps(int num) {
    numImps = num;
}

int Blue::getNumImps() {
    return numImps;
}

string Blue::getName() {
    return name;
}

int Blue::getPrice() {
    return price;
}

Blue::~Blue() {
    impTuit.clear();
}

int Blue::getTuition() {
    return impTuit.at(numImps);
}
