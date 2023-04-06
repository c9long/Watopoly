#include "player.h"

#include <cstdlib>
#include <map>
#include <string>

#include "square.h"

using namespace std;

Player::Player(string name, int balance, char piece, bool inJail, int numJailRolls, int locId, Square* location) : name{name}, balance{balance}, piece{piece}, inJail{inJail}, numJailRolls{numJailRolls}, locId{locId}, location{location} {}

void Player::roll() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;

    rollSum = die1 + die2;
}

void Player::next() {}

void Player::changeBalance(int x) {
    balance += x;
}
