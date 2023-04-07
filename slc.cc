#include "slc.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

SLC::SLC() {}

/*void SLC::print( std::vector<int> const & v ) {
            for ( int i : v ) std::cout << i << ' ';
            std::cout << std::endl;
} */

void SLC::payOut(Player &affected) {
    // Player's piece is randomly moved on the board (implement the proabability stuff)
    // Play proceeds as if they had landed on the square they were moved to
    std::vector<int> v = {};
    for (int i = 1; i <= 88; i++) {
        v.emplace_back(i);
    }

    // use a time-based seed for the default seed value
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine rng{seed};

    for ( int i = 0; i < 1000; i++ ) {
            shuffle( v.begin(), v.end(), rng );
    }
    
    int randomVal = v[1];
    if (randomVal <= 8) {
        // move back 3
    } else if (randomVal <= 14) {
        // move back 2
    } else if (randomVal <= 20) {
        // move back 1
    } else if (randomVal <= 28) {
        // move forward 1
    } else if (randomVal <= 34) {
        // move forward 2
    } else if (randomVal <= 40) {
        // move forward 3
    } else if (randomVal <= 64) {
        // go to dc tims line
    } else if (randomVal <= 88) {
        // advance to collect osap
    }
}
