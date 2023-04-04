#include "needles.h"

Needles::Needles() {}

Needles::Payout(Player &affected) {
    // Player either gains or loses some amount of their savings
    //implement probability code
    int amount;
    affected.changeBalance(amount);
}
