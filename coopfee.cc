#include "coopfee.h"

CoopFee::CoopFee() {}

void CoopFee::payOut(Player &affected) {
    affected.changeBalance(-150);
}
