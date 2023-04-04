#include "needles.h"

Needles::Needles() {}

void Needles::payOut(Player &affected) {
    // Player either gains or loses some amount of their savings
    //implement probability code
    int amount;
    affected.changeBalance(amount);
}
