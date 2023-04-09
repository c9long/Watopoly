#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>


class Square;
class Player {
protected:
    std::string name;
    int balance;
    char piece;
    int rollSum; // the sum of two dice rolls
    bool inJail;
    int numJailRolls;
    int locId;
    int numCups; // Number of tims cups player currently has
    void roll(); // returns total roll num
    void next();
    bool hasImprovements(std::string propertyName);
    bool owns(Square* square, Player& player); // Checks if the player owns given square
    
    // bool trade(std::string name, std::string give, std::string receive);

   public:
    Player(std::string name, int balance, char piece, bool inJail, int numJailRolls, int locId, int numCups);
    std::string getName();
    char getPiece();
    int getBalance();
    bool getInJail();
    int getNumJailRolls();
    int getLocId();
    int getNumCups();
    void changeBalance(int x);  // cannot make properties friends for error checking
    bool trade(Player& other, std::string give, std::string receive);
    friend class Board;
    friend class SLC;
};

#endif
