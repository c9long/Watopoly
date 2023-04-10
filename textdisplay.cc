#include "textdisplay.h"

using namespace std;

Textdisplay::Textdisplay()
{
    for (int i = 0; i < 40; i++) {
        string empty = "       ";
        positions.emplace_back(empty);
    }
    

    vector<string> v;
    v.emplace_back("Goose  ");
    v.emplace_back("Nesting");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("EV1    ");
    v.emplace_back(positions[21]);
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("NEEDLES");
    v.emplace_back("HALL   ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("EV2    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("EV3    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("V1     ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("PHYS   ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("B1     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("CIF    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("B2     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("GO TO  ");
    v.emplace_back("TIMS   ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("OPT    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("EIT    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("BMH    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("ESC    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("SLC    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("SLC    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("LHI    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("C2     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("UWP    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("REV    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("CPH    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("NEEDLES");
    v.emplace_back("HALL   ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("DWE    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("MC     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("PAC    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("COOP   ");
    v.emplace_back("FEE    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("RCH    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("DC     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("DC TIMS");
    v.emplace_back("LINE   ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("HH     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("PAS    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("NEEDLES");
    v.emplace_back("HALL   ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("ECH    ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("MKV    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("TUITION");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("ML     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("SLC    ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("       ");
    v.emplace_back("-------");
    v.emplace_back("AL     ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    v.emplace_back("COLLECT");
    v.emplace_back("OSAP   ");
    v.emplace_back("       ");
    v.emplace_back("       ");
    v.emplace_back("_______");
    theBoard.emplace_back(v);
    v.clear();

    for (int i = 20; i <= 30; i++) {
        convertLoc[i] = i - 20;
    }
    for (int i = 0; i <= 10; i++) {
        convertLoc[i] = 39 - i;
    }
    convertLoc[11] = 27;
    convertLoc[12] = 25;
    convertLoc[13] = 23;
    convertLoc[14] = 21;
    convertLoc[15] = 19;
    convertLoc[16] = 17;
    convertLoc[17] = 15;
    convertLoc[18] = 13;
    convertLoc[19] = 11;
    convertLoc[31] = 12;
    convertLoc[32] = 14;
    convertLoc[33] = 16;
    convertLoc[34] = 18;
    convertLoc[35] = 20;
    convertLoc[36] = 22;
    convertLoc[37] = 24;
    convertLoc[38] = 26;
    convertLoc[39] = 28;
}

std::ostream &operator<<(std::ostream &out, const Textdisplay &td)
{
    for (int i = 0; i < 56; ++i)
    {
        if (i == 0)
        {
            for (int j = 0; j < 89; ++j)
            {
                out << '_';
            }
            out << endl;
        }
        else if (i > 0 && i < 6)
        {
            for (int j = 0; j <= 10; ++j)
            {
                out << '|' << td.theBoard.at(j).at((i - 1) % 5);
            }
            out << '|' << endl;
        }
        else if (i >= 6 && i <= 10)
        {
            out << '|' << td.theBoard.at(11).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(12).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 10 && i <= 15)
        {
            out << '|' << td.theBoard.at(13).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(14).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 15 && i <= 20)
        {
            out << '|' << td.theBoard.at(15).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(16).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 20 && i <= 23)
        {
            out << '|' << td.theBoard.at(17).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(18).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 24)
        {
            out << '|' << td.theBoard.at(17).at((i - 1) % 5) << '|' << "             _____________________________________________             |" << td.theBoard.at(18).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 25)
        {
            out << '|' << td.theBoard.at(17).at((i - 1) % 5) << '|' << "            |                                             |            |" << td.theBoard.at(18).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 26)
        {
            out << '|' << td.theBoard.at(19).at((i - 1) % 5) << '|' << "            | #   #  ##  #####  ###  ###   ###  #   #   # |            |" << td.theBoard.at(20).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 27)
        {
            out << '|' << td.theBoard.at(19).at((i - 1) % 5) << '|' << "            | #   # #  #   #   #   # #  # #   # #   #   # |            |" << td.theBoard.at(20).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 28)
        {
            out << '|' << td.theBoard.at(19).at((i - 1) % 5) << '|' << "            | # # # ####   #   #   # ###  #   # #    # #  |            |" << td.theBoard.at(20).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 29)
        {
            out << '|' << td.theBoard.at(19).at((i - 1) % 5) << '|' << "            | # # # #  #   #   #   # #    #   # #     #   |            |" << td.theBoard.at(20).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 30)
        {
            out << '|' << td.theBoard.at(19).at((i - 1) % 5) << '|' << "            | ##### #  #   #    ###  #     ###  ## #  #   |            |" << td.theBoard.at(20).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 31)
        {
            out << '|' << td.theBoard.at(21).at((i - 1) % 5) << '|' << "            |_____________________________________________|            |" << td.theBoard.at(22).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 31 && i <= 35)
        {
            out << '|' << td.theBoard.at(21).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(22).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 35 && i <= 40)
        {
            out << '|' << td.theBoard.at(23).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(24).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 40 && i <= 45)
        {
            out << '|' << td.theBoard.at(25).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(26).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 45 && i <= 49)
        {
            out << '|' << td.theBoard.at(27).at((i - 1) % 5) << '|' << "                                                                       |" << td.theBoard.at(28).at((i - 1) % 5) << '|' << endl;
        }
        else if (i == 50) {
            out << '|' << td.theBoard.at(27).at((i - 1) % 5) << '|' << "_______________________________________________________________________|" << td.theBoard.at(28).at((i - 1) % 5) << '|' << endl;
        }
        else if (i > 50) {
            for (int j = 29; j <= 39; ++j)
            {
                out << '|' << td.theBoard.at(j).at((i - 1) % 5);
            }
            out << '|' << endl;
        }
    }
    return out;
}

void Textdisplay::notify(Board &whoNotified) {
    if (whoNotified.currPlayer == nullptr) {
        // setting up all pieces at the beginning of the game
        cout << "whoNotified was a nullptr" << endl;
        for (int i = 0; i < whoNotified.numPieces; i++) {

        }
    } else {
        // moving one player's piece after a move
        cout << "currentPlayerNum is " << whoNotified.currPlayer->getPlayerNum() + 1 << endl;
        cout << "current piece is " << whoNotified.currPlayer->getPiece() << endl;
        int oldLoc = convertLoc[whoNotified.currPlayer->getOldLocId()];;
        int newLoc = convertLoc[whoNotified.currPlayer->getLocId()];
        int spot = whoNotified.currPlayer->getPlayerNum();
        theBoard[oldLoc][3][spot] = ' ';
        theBoard[newLoc][3][spot] = whoNotified.currPlayer->getPiece();
        cout << *this;
    }
} 

Textdisplay::~Textdisplay() {
    theBoard.clear();
    positions.clear();
}
