#include <iostream>
#include <string>
#include <sstream>
#include "game.h"
using namespace std;


int main(int argc, char* argv[]) {
    int startLevel = 0;
    int seed = 0; // should there be a default value for seed?
    string sequenceFileName1 = "sequence1.txt";
    string sequenceFileName2 = "sequence2.txt";
    bool textOnly = false;
    bool willSetSeed = false;

    int i = 1;
    while(i < argc) {
        string arg = argv[i];

        if (arg == "-scriptfile1" || arg == "-scriptfile2" || arg == "-startlevel" || arg == "-seed") {
            if (i + 1 == argc) {
                cerr << "Invalid arguments" << endl;
                return 1;
            } // if

            string temp = argv[i + 1];
            i++;

            if (arg == "-scriptfile1") {
                sequenceFileName1 = temp;
            } else if (arg == "-scriptfile2") {
                sequenceFileName2 = temp;
            } else if (arg == "-startlevel") {
                istringstream(temp) >> startLevel;
            } else if (arg == "-seed") {
                istringstream(temp) >> seed;
                willSetSeed = true;
            } else {
                cerr << "Invalid arguments" << endl;
                return 1;
            } // if
        } else if (arg == "-text") {
            textOnly = true;
        } else {
            cerr << "Invalid arguments" << endl;
            return 1;
        } // if

        i++;
    } // while

    Game game = Game(startLevel, sequenceFileName1, sequenceFileName2, textOnly, willSetSeed, seed);

    game.init();
    game.run();
} // main
