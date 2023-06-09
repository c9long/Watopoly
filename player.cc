#include "player.h"

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <random>
#include <chrono>

#include "square.h"

using namespace std;

Player::Player(string name, int balance, char piece, bool inJail, int numJailRolls, int locId, int numCups, int playerNum) : name{name}, balance{balance}, piece{piece}, inJail{inJail}, numJailRolls{numJailRolls}, locId{locId}, numCups{numCups}, playerNum{playerNum} {}

string Player::getName()
{
    return name;
}

char Player::getPiece()
{
    return piece;
}

int Player::getBalance()
{
    return balance;
}

bool Player::getInJail()
{
    return inJail;
}

int Player::getNumJailRolls()
{
    return numJailRolls;
}

int Player::getNumDoubleRolls()
{
    return numDoubleRolls;
}

int Player::getLocId()
{
    return locId;
}

int Player::getOldLocId() 
{
    return oldLocId;
}

int Player::getNumCups()
{
    return numCups;
}

int Player::getPlayerNum() 
{
    return playerNum;
}

bool Player::getCanRollAgain()
{
    return canRollAgain;
}

void Player::roll()
{
    // use a time-based seed for the default seed value
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
    uniform_int_distribution<int> dist{1, 6};

    int die1 = dist(rng);
    int die2 = dist(rng);

    // int die1 = rand() % 6 + 1;
    // int die2 = rand() % 6 + 1;
    cout << "You rolled a " << die1 << " and a " << die2 << "." << endl;
    rollSum = die1 + die2;
    if (die1 == die2) {
        numDoubleRolls++;
    } else {
        numDoubleRolls = 0;
    }
    if (inJail) {
        numJailRolls++;
    }
    if (numJailRolls == 3 && numDoubleRolls == 1) {
        cout << "It's been 3 turns and you rolled doubles, so you will exit the DC Tims Line." << endl;
        toggleInJail();
        numJailRolls = 0;
    } 
    else if (numJailRolls == 3) {
        cout << "It's been 3 turns, so you will exit the DC Tims Line." << endl;
        toggleInJail();
        numJailRolls = 0;
    }
    else if (inJail && numDoubleRolls == 1) {
        cout << "You rolled doubles, so you will exit the DC Tims Line." << endl;
        toggleInJail();
        numJailRolls = 0;
    }
    if (inJail) {
        cout << "It's been " << numJailRolls << " turns and you didn't roll double, so you will stay in the DC Tims Line." << endl;
    } 
    else {
        cout << "Moving " << die1 + die2 << " steps now." << endl;
    }
}

void Player::next() {}

void Player::changeBalance(int x)
{
    if (balance + x < 0)
        throw invalid_argument("You do not have enough funds to make this purchase");
    balance += x;
}

void Player::setLocId(int loc) {
    locId = loc;
}

void Player::toggleInJail() {
    inJail = !inJail;
}
