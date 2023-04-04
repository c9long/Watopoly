#ifndef NEEDLES_H
#define NEEDLES_H
#include "nonproperty.h"
#include <string>
#include <vector>

class Needles : public NonProperty
{

public:
    Needles();
    void payOut(Player &affected);
};

#endif
