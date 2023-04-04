#ifndef SLC_H
#define SLC_H
#include "nonproperty.h"
#include <string>
#include <vector>

class SLC : public NonProperty
{

public:
    SLC();
    void payOut(Player &affected);
};

#endif
