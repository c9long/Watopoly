#include "gototims.h"
#include <iostream>

using namespace std;

GoToTims::GoToTims() {}

void GoToTims::payOut(Player &affected) {
    // need to do something about skipping collecting the $200 osap
    affected.toggleInJail();
    affected.rollSum = 20;
    cout << "Going to the DC Tims Line" << endl;
}
