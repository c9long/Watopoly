#include "board.h"

using namespace std;

void Board::trade(Player& other) {
    int itemGiven = -1;
    int itemReceived = -1;

    // Check if trading with self
    if (currPlayer->name == other.name) {
        throw invalid_argument("You cannot trade with yourself!");
    }

    string give, receive;
    cin >> give; cin >> receive;


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
        if (it == propertyMap.end() || owners[it->second] != currPlayer) {
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
    if (itemGiven >= 0 && currPlayer->balance < itemGiven) {
        throw invalid_argument("You do not have enough money to do this trade!");
    }
    if (itemReceived >= 0 && other.balance < itemReceived) {
        throw invalid_argument("You do not have enough money to do this trade!");
    }

    cout << other.name << ", would you like to accept this trade? (Y/N)" << endl;

    char c;

    cin >> c;
    if (c == 'Y' || c == 'y') {

    } else {
        
    }
}

bool Board::hasImprovements(string propertyName) {

    for (auto it = theBoard.begin(); it != theBoard.end(); ++it) {
        if ((*it)->getNumImps() > 0) return true;
    }

    return false;
}

void Board::setPropertyMap() {
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
