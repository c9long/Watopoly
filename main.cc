#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int numPlayers = 0;
    if (argv[1] == "-load") {
        ifstream ifs{argv[2]};
        string s;
        while(getline(ifs, s, ' ')) {
            cout << s << endl;
        }
    }
    
    cout << "How many players would you like to enter into your new game?" << endl;
    return 10;
}
