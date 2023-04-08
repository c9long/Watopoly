#include "nonproperty.h"
using namespace std;

void NonProperty::purchase(Player &buyer) {}
void NonProperty::auction() {}
void NonProperty::payTuition(Player &paying, Player &earning) {}
void NonProperty::addImprovement() {}
int NonProperty::getNumImps() { return 0; }
void NonProperty::setNumImps(int num) {}
string NonProperty::getName() { return 0; }
int NonProperty::getPrice() {return 0; }
NonProperty::~NonProperty() {}
