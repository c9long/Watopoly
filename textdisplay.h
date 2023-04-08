#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <string>

class Textdisplay
{
    std::vector<std::vector<std::string>> theBoard;
public:
    Textdisplay();
    void notify();
    ~Textdisplay();
    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};
#endif
