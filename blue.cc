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

void Blue::addImprovement()
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

void Blue::purchase(Player &buyer)
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

void Blue::auction(){

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
