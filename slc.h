#ifndef SLC_H
#define SLC_H
#include "nonproperty.h"
#include <string>
#include <vector>

class SLC : public NonProperty
{

public:
    SLC();
    void payOut(Player &affected); //in progress, need to figure out how to implement moves
};

#endif
