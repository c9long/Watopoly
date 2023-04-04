#ifndef GOOSE_H
#define GOOSE_H
#include "nonproperty.h"
#include <string>
#include <vector>

class Goose : public NonProperty
{

public:
    Goose();
    void payOut(Player &affected);
};

#endif
