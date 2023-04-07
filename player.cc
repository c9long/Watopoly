#include "player.h"

#include <cstdlib>
#include <map>
#include <string>

#include "square.h"

using namespace std;

Player::Player(string name, int balance, char piece, bool inJail, int numJailRolls, int locId) : name{name}, balance{balance}, piece{piece}, inJail{inJail}, numJailRolls{numJailRolls}, locId{locId} {}

string Player::getName() {
    return name;
}

void Player::roll() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;

    rollSum = die1 + die2;
}

void Player::next() {}

void Player::changeBalance(int x) {
    if (balance + x < 0) throw invalid_argument("You do not have enough funds to make this purchase");
    balance += x;
}
