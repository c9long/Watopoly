#include "osap.h"

OSAP::OSAP() {}

void OSAP::payOut(Player &affected) {
    affected.changeBalance(200);
}
