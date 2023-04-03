#include "ltblue.h"

LtBlue::LtBlue(int price, std::string name):price{price}, name{name} {
    if (name == "AL") {
        impTuit.emplace_back(2);
        impTuit.emplace_back(10);
        impTuit.emplace_back(30);
        impTuit.emplace_back(90);
        impTuit.emplace_back(160);
        impTuit.emplace_back(250);
    } else if (name == "ML") {
        impTuit.emplace_back(4);
        impTuit.emplace_back(20);
        impTuit.emplace_back(60);
        impTuit.emplace_back(180);
        impTuit.emplace_back(320);
        impTuit.emplace_back(450);
    } else if (name == "ML") {
        impTuit.emplace_back(4);
        impTuit.emplace_back(20);
        impTuit.emplace_back(60);
        impTuit.emplace_back(180);
        impTuit.emplace_back(320);
        impTuit.emplace_back(450);
    }
}
