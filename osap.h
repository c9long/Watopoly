#ifndef OSAP_H
#define OSAP_H
#include "nonproperty.h"
#include <string>
#include <vector>

class OSAp : public NonProperty
{

public:
    OSAP();
    void payOut(Player &affected);
};

#endif
