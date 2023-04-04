#include "osap.h"

OSAP::OSAP() {}

OSAP::Payout(Player &affected) {
    affected.changeBalance(200);
}
