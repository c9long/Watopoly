#ifndef GOTOTIMS_H
#define GOTOTIMS_H
#include "nonproperty.h"
#include <string>
#include <vector>

class GoToTims : public NonProperty
{

public:
    GoToTims();
    void payOut(Player &affected);
};

#endif
