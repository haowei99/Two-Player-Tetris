#include <iostream>
#include <string>
#include "blockgenerator.h"
using namespace std;

int main() {
    string s;
    int level = 0;
    BlockGenerator* bg = new BlockGenerator{"sequence.txt"};

    while(cin >> s) {
        if (s == "level") {
            cin >> level;
        } else if (s == "gen") {
            cout << bg->generateBlock(level) << endl;
        } else if (s == "random") {
            bg->unsetStream();
        } else if (s == "norandom") {
            string name;
            
            cin >> name;
            bg->setStream(name);
        } else if (s == "restart") {
            bg->reset();
        } // if
    } // while

    delete bg;
} // main