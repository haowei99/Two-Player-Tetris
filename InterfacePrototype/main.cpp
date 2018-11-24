#include <iostream>
#include <string>
#include "game.h"
using namespace std;


int main(int argc, char* argv[]) {
    int startLevel = 0;
    string sequenceFileName1 = "sequence1.txt";
    string sequenceFileName2 = "sequence2.txt";
    Game game = Game(startLevel, sequenceFileName1, sequenceFileName2);

    game.init();
    game.run();
} // main
