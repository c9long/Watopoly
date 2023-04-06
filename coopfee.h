#ifndef COOPFEE_H
#define COOPFEE_H
#include "nonproperty.h"
#include <string>
#include <vector>

class CoopFee : public NonProperty
{

public:
    CoopFee();
    void payOut(Player &affected) override;
};

#endif
