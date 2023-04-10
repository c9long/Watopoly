#include "residence.h"

using namespace std;

void Residence::purchase(Player &buyer)
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
void Residence::auction()
{
}
void Residence::payTuition(Player &paying, Player &earning)
{
}
void Residence::addImprovement()
{
}

void Residence::setNumImps(int num) {} // Intentionally left blank

string Residence::getName()
{
    return 0;
}

int Residence::getNumImps()
{
    return 0;
}

int Residence::getPrice()
{
    return 200;
}

int Residence::getTuition() {
    return 0;
}
