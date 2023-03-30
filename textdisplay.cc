#include "textdisplay.h"

Textdisplay::Textdisplay() {
    for (int i = 0; i < )
}

std::ostream &operator<<(std::ostream &out, const Textdisplay &td)
{
    for (int i = 0; i < theBoard.size(); ++i)
    {
        for (int j = 0; j < theBoard.at(i).size(); ++j)
        {
            out << td.theBoard[i][j];
        }
        out << std::endl;
    }
    return out;
}
