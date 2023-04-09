#include "player.h"
#include "square.h"
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <random>
#include <chrono>

using namespace std;

Player::Player(string name, int balance, char piece, bool inJail, int numJailRolls, int locId, int numCups) : name{name}, balance{balance}, piece{piece}, inJail{inJail}, numJailRolls{numJailRolls}, locId{locId}, numCups{numCups} {}

string Player::getName() {
    return name;
}

void Player::roll() {
    // use a time-based seed for the default seed value
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
    uniform_int_distribution<int> dist{1, 6};

    int die1 = dist(rng);
    int die2 = dist(rng);

    // int die1 = rand() % 6 + 1;
    // int die2 = rand() % 6 + 1;

    rollSum = die1 + die2;
    cout << "You rolled a " << die1 << " and a " << die2 << ". Moving " << die1 + die2 << " steps now." << endl;
}

void Player::next() {}

void Player::changeBalance(int x) {
    if (balance + x < 0) throw invalid_argument("You do not have enough funds to make this purchase");
    balance += x;
}
