#ifndef DCTIMS_H
#define DCTIMS_H
#include "nonproperty.h"
#include <string>
#include <vector>

class DCTims : public NonProperty
{

public:
    DCTims();
    void payOut(Player &affected);
};

#endif
