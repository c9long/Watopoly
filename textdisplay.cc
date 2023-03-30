#include "textdisplay.h"

Textdisplay::Textdisplay() {
    for (int i = 0; i < theBoard.size(); ++i) {

    }
}

std::ostream &operator<<(std::ostream &out, const Textdisplay &td)
{
    for (int i = 0; i < td.theBoard.size(); ++i)
    {
        for (int j = 0; j < td.theBoard.at(i).size(); ++j)
        {
            out << td.theBoard[i][j];
        }
        out << std::endl;
    }
    return out;
}
