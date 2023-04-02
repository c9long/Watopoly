#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Textdisplay
{
    std::vector<std::vector<string>> theBoard;
public:
    Textdisplay();
    void notify();
    ~Textdisplay();
    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};
#endif
