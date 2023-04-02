#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int numPlayers = 0;
    if (argc > 1)
    {
        string arg = argv[1];
        if (arg == "-load")
        {
            cout << "success" << endl;
            ifstream ifs{argv[2]};
            string s;
            while (getline(ifs, s, ' '))
            {
                cout << s << endl;
            }
        }
    }

        cout << "How many players would you like to enter into your new game?" << endl;
    }
