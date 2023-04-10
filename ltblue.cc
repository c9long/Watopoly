#include "ltblue.h"

using namespace std;

LtBlue::LtBlue(int price, string name):price{price}, name{name} {
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
            cout << "Not enough funds to make this purchase" << endl;
        }
    }
}

void LtBlue::purchase(Player &buyer)
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

void LtBlue::auction(int amount){

}

void LtBlue::setNumImps(int num) {
    numImps = num;
}

int LtBlue::getNumImps() {
    return numImps;
}

string LtBlue::getName() {
    return name;
}

int LtBlue::getPrice() {
    return price;
}

LtBlue::~LtBlue() {
    impTuit.clear();
}

int LtBlue::getTuition() {
    return impTuit.at(numImps);
}
