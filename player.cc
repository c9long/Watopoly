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

bool Player::trade(Player& other, string give, string receive) {
    int itemGiven = -1;
    int itemReceived = -1;

    // Check if trading with self
    if (name == other.name) {
        throw invalid_argument("You cannot trade with yourself!");
    }

    // Store amount if either trading items are money
    try {
        itemGiven = stoi(give);
    } catch (exception& e) {
    }

    try {
        itemReceived = stoi(receive);
    } catch (exception& e) {
    }

    // Check if trading money for money
    if ((itemGiven >= 0) && (itemReceived >= 0)) {
        throw invalid_argument("You cannot trade money with money!");
    }

    if (itemGiven == -1) {  // Is a property
        // Check if property being given has improvements
        if (hasImprovements(give)) {
            throw invalid_argument("You cannot trade a property in a monopoly that has improvements!");
        }

        // Check if player owns property being given
        auto it = propertyMap.find(give);
        if (it == propertyMap.end() || !owns(it->second, *this)) {
            throw invalid_argument("You cannot trade a property you don't own!");
        }
    }

    // Check if property being received has improvements
    if (itemReceived == -1) {
        if (hasImprovements(receive)) {
            throw invalid_argument("You cannot trade a property in a monopoly that has improvements!");
        }
    }

    // Check if player has enough balance
    if (itemGiven >= 0 && balance < itemGiven) {
        throw invalid_argument("You do not have enough money to do this trade!");
    }
    if (itemReceived >= 0 && other.balance < itemReceived) {
        throw invalid_argument("You do not have enough money to do this trade!");
    }
}

void Player::setPropertyMap() {
    propertyMap["AL"] = &AL;
    propertyMap["ML"] = &ML;
    propertyMap["ECH"] = &ECH;
    propertyMap["PAS"] = &PAS;
    propertyMap["HH"] = &HH;
    propertyMap["RCH"] = &RCH;
    propertyMap["DWE"] = &DWE;
    propertyMap["CPH"] = &CPH;
    propertyMap["LHI"] = &LHI;
    propertyMap["MBH"] = &MBH;
    propertyMap["OPT"] = &OPT;
    propertyMap["EV1"] = &EV1;
    propertyMap["EV2"] = &EV2;
    propertyMap["EV3"] = &EV3;
    propertyMap["B1"] = &B1;
    propertyMap["B2"] = &B2;
    propertyMap["EIT"] = &EIT;
    propertyMap["ESC"] = &ESC;
    propertyMap["C2"] = &C2;
    propertyMap["MC"] = &MC;
    propertyMap["DC"] = &DC;
}

bool Player::hasImprovements(string propertyName) {
    auto it = propertyMap.find(propertyName);

    if ((it != propertyMap.end()) && (it->second->getNumImps() > 0)) {  // TODO: add getNumImps()
        return true;
    }
}

bool Player::owns(Square* square, Player& player) {
    if (owners.find(square) != owners.end()) {
        Player* squareOwner = owners[square];
        if (squareOwner == &player) return true;
    }

    return false;
}
