#include "residence.h"

using namespace std;

Residence::Residence(int price, string name): price{price}, name{name} {}

void Residence::purchase(Player &buyer)
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
void Residence::auction(int amount)
{
}
void Residence::payTuition(Player &paying, Player &earning)
{
}
void Residence::addImprovement(Player* owner)
{
}

void Residence::setNumImps(int num) {} // Intentionally left blank

string Residence::getName()
{
    return name;
}

int Residence::getNumImps()
{
    return numImps;
}

int Residence::getPrice()
{
    return 200;
}

int Residence::getTuition() {
    return 0;
}
