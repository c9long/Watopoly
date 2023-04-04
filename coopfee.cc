#include "coopfee.h"

CoopFee::CoopFee() {}

CoopFee::Payout(Player &affected) {
    affected.changeBalance(-150);
}
