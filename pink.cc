#include "pink.h"
using namespace std;

Pink::Pink(int price, std::string name):price{price}, name{name} {
    if (name == "RCH") {
        impTuit.emplace_back(10);
        impTuit.emplace_back(50);
        impTuit.emplace_back(150);
        impTuit.emplace_back(450);
        impTuit.emplace_back(625);
        impTuit.emplace_back(750);
    } else if (name == "DWE") {
        impTuit.emplace_back(10);
        impTuit.emplace_back(50);
        impTuit.emplace_back(150);
        impTuit.emplace_back(450);
        impTuit.emplace_back(625);
        impTuit.emplace_back(750);
    } else if (name == "CPH") {
        impTuit.emplace_back(12);
        impTuit.emplace_back(60);
        impTuit.emplace_back(180);
        impTuit.emplace_back(500);
        impTuit.emplace_back(700);
        impTuit.emplace_back(900);
    }
}

void Pink::payTuition(Player &paying, Player &earning)
{
    paying.changeBalance(-impTuit.at(numImps));
    earning.changeBalance(impTuit.at(numImps));
}

void Pink::addImprovement()
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

void Pink::purchase(Player &buyer)
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

void Pink::auction(){

}

void Pink::setNumImps(int num) {
    numImps = num;
}

int Pink::getNumImps() {
    return numImps;
}

string Pink::getName() {
    return name;
}

int Pink::getPrice() {
    return price;
}

Pink::~Pink() {
    impTuit.clear();
}
