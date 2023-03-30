#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>

class Textdisplay
{
    std::vector<std::vector<char>> theBoard;
public:
    Textdisplay();
    void notify();
    ~Textdisplay();
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
