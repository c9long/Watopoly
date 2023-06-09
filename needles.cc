#include "needles.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

Needles::Needles() {}

void Needles::payOut(Player &affected) {
    // Player either gains or loses some amount of their savings
    // still need to implement 1% chance of roll up the rim cup
    std::vector<int> v = {};
    for (int i = 1; i <= 69; i++) {
        v.emplace_back(i);
    }

    // use a time-based seed for the default seed value
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine rng{seed};

    for ( int i = 0; i < 1000; i++ ) {
            shuffle( v.begin(), v.end(), rng );
    }
    
    int randomVal = v[1];
    // need to add bankruptcy to this
    if (randomVal <= 18) {
        affected.changeBalance(-200);
        cout << "You just lost $200. Your new balance is $" <<  affected.getBalance() << endl;
    } else if (randomVal <= 27) {
        affected.changeBalance(-100);
        cout << "You just lost $100. Your new balance is $" <<  affected.getBalance() << endl;
    } else if (randomVal <= 33) {
        affected.changeBalance(-50);
        cout << "You just lost $50. Your new balance is $" <<  affected.getBalance() << endl;
    } else if (randomVal <= 36) {
        affected.changeBalance(25);
        cout << "You just gained $25. Your new balance is $" <<  affected.getBalance() << endl;
    } else if (randomVal <= 42) {
        affected.changeBalance(50);
        cout << "You just gained $50. Your new balance is $" <<  affected.getBalance() << endl;
    } else if (randomVal <= 51) {
        affected.changeBalance(100);
        cout << "You just gained $100. Your new balance is $" <<  affected.getBalance() << endl;
    } else if (randomVal <= 69) {
        affected.changeBalance(200);
        cout << "You just gained $200. Your new balance is $" <<  affected.getBalance() << endl;
    }
}
