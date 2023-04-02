#include <iostream>
#include <fstream>
#include <string>
#include "square.h" // can be changed to forward declaration

using namespace std;

int main(int argc, char *argv[])
{
    int numPlayers = 0;
    if (argc > 1)
    {
        string arg = argv[1];
        if (arg == "-load")
        {
            ifstream ifs{argv[2]};
            string s;
            if (ifs >> s)
            {
                numPlayers = stoi(s);
                for (int i = 0; i < numPlayers; ++i)
                {
                    string name;
                    char piece;
                    int timsCups;
                    int balance;
                    string location;
                    ifs >> name;
                    ifs >> s; piece = s[0];
                    ifs >> s; timsCups = stoi(s);
                    ifs >> s; balance = stoi(s);
                    char c;
                    ifs.get(c);
                    getline(ifs, location);
                    cout << name << endl;
                    cout << piece << endl;
                    cout << timsCups << endl;
                    cout << balance << endl;
                    cout << location << endl;
                }
            }
        }
    }

    cout << "How many players would you like to enter into your new game?" << endl;
}
