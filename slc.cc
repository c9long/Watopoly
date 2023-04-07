#include "slc.h"
#include "player.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

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
        affected.rollSum = -3;
        cout << "Moving 3 steps backwards." << endl;
    } else if (randomVal <= 14) {
        affected.rollSum = -2;
        cout << "Moving 2 steps backwards." << endl;
    } else if (randomVal <= 20) {
        affected.rollSum = -1;        
        cout << "Moving 1 step backwards." << endl;
    } else if (randomVal <= 28) {
        affected.rollSum = 1;
        cout << "Moving 1 step forward." << endl;
    } else if (randomVal <= 34) {
        affected.rollSum = 2;
        cout << "Moving 2 steps forward." << endl;
    } else if (randomVal <= 40) {
        affected.rollSum = 3;
        cout << "Moving 3 steps forward." << endl;
    } else if (randomVal <= 64) {
        // go to dc tims line
        if ((30 - affected.locId) < 0) {
            affected.rollSum = 70 - affected.locId;
        } else {
            affected.rollSum = 30 - affected.locId; 
        }
        cout << "Going to Tims." << endl;
    } else if (randomVal <= 88) {
        // advance to collect osap
        affected.rollSum = 40 - affected.locId;
        cout << "Advancing to Collect OSAP." << endl;
    }
}
