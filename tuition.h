#ifndef TUITION_H
#define TUITION_H
#include "nonproperty.h"
#include <string>
#include <vector>

class Tuition : public NonProperty
{

public:
    Tuition();
    void payOut(Player &affected) override;
};

#endif
