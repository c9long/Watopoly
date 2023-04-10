#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <string>
#include "board.h"

class Board;

class Textdisplay
{
    std::vector<std::vector<std::string>> theBoard;
    std::vector<std::string> positions;
    std::map<int, int> convertLoc;
public:
    Textdisplay();
    void notify(Board &whoNotified);
    ~Textdisplay();
    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};
#endif
