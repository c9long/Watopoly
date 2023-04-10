#include "gym.h"
using namespace std;

Gym::Gym(int price, string name): price{price}, name{name} {}

void Gym::purchase(Player &buyer) {
    
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
void Gym::auction(int amount) {

}
void Gym::payTuition(Player &paying, Player &earning) {

}
void Gym::addImprovement() {

}

void Gym::setNumImps(int num) {} // Intentionally left blank

int Gym::getNumImps() {
    return numImps;
}

int Gym::getPrice() {
    return 150;
}

string Gym::getName() {
    return name;
}

int Gym::getTuition() {
    return 0;
}
