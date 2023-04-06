#include "board.h"
#include "brown.h"
#include "ltblue.h"
#include "pink.h"
#include "orange.h"
#include "red.h"
#include "yellow.h"
#include "green.h"
#include "blue.h"

using namespace std;

Board::Board() {
    theBoard.emplace_back(new Brown{40, "AL"});
    theBoard.emplace_back(new Brown{60, "ML"});
    theBoard.emplace_back(new LtBlue{100, "ECH"});
    theBoard.emplace_back(new LtBlue{100, "PAS"});
    theBoard.emplace_back(new LtBlue{120, "HH"});
    theBoard.emplace_back(new Pink{140, "RCH"});
    theBoard.emplace_back(new Pink{140, "DWE"});
    theBoard.emplace_back(new Pink{160, "CPH"});
    theBoard.emplace_back(new Orange{180, "LHI"});
    theBoard.emplace_back(new Orange{180, "BMH"});
    theBoard.emplace_back(new Orange{200, "OPT"});
    theBoard.emplace_back(new Red{220, "EV1"});
    theBoard.emplace_back(new Red{220, "EV2"});
    theBoard.emplace_back(new Red{240, "EV3"});
    theBoard.emplace_back(new Yellow{260, "PHYS"});
    theBoard.emplace_back(new Yellow{260, "B1"});
    theBoard.emplace_back(new Yellow{280, "B2"});
    theBoard.emplace_back(new Green{300, "EIT"});
    theBoard.emplace_back(new Green{300, "ESC"});
    theBoard.emplace_back(new Green{320, "C2"});
    theBoard.emplace_back(new Blue{350, "MC"});
    theBoard.emplace_back(new Blue{400, "DC"});
}

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
    /* propertyMap["AL"] = &AL;
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
    propertyMap["DC"] = &DC; */
}
