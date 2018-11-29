#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "player.h"
#include "numbergenerator.h"
#include "gamedisplay.h"
#include "game.h"


bool Game::readCommands(std::istream& in, bool readingFromFile, std::string fileName) {
    /** TODOS:
     * add logic for printing display when command called
     *     - ASK: print display only when NOT reading from sequence file???
     * add multipliers
     * add shortcuts
     * write a higher order function to make command multiplication easier? 
     * **/
    
    std::string command;

    while(true) {
        int multiplier;

        if (!(in >> multiplier)) {
            if (in.eof()) {
                if (readingFromFile) {
                    return false;
                } // if
            
                throw Game::GameException{true, false};
            } // if
            
            multiplier = 1;
            in.clear();
        } // if

        in >> command;

        /*** ASK: do I need this if statement? ***/
        if (in.fail()) {
            if (readingFromFile) {
                return false;
            } // if
            
            throw Game::GameException{true, false};
        } // if
        /******************************************/

        // if multiplier on command is 0, then we don't need to do anything
        if (multiplier == 0) {
            continue;
        } // if

        if (command == "left") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->left();
            } // for
        } else if (command == "right") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->right();
            } // for
        } else if (command == "down") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->down();
            } // for
        } else if (command == "clockwise") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->clockwise();
            } // for
        } else if (command == "counterclockwise") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->counterclockwise();
            } // for
        } else if (command == "levelup") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->levelUp();
            } // for
        } else if (command == "leveldown") {
            for (int i = 0;i < multiplier;i++) {
                curPlayer->levelDown();
            } // for
        } else if (command == "norandom") {
            std::string noRandomFileName;

            in >> noRandomFileName;
            curPlayer->noRandom(noRandomFileName);
        } else if (command == "random") { 
            curPlayer->random();
        } else if (command == "sequence") { // ASK: valid for multipliers?
            std::string fileReaderName;
            std::ifstream fileReader; 
            
            in >> fileReaderName; // read in file name
            
            // reading same file as the file that is currently being read is not valid
            if (fileName == fileReaderName) {
                std::cout << "This will cause an infinite loop you dumbass" << std::endl;
                fileReader.close();
                continue;
            } // if

            for (int i = 0;i < multiplier;i++) {
                fileReader.open(fileReaderName.c_str()); // open the ifstream

                bool turnWillEnd = readCommands(fileReader, true, fileName); // execute commands from file
                fileReader.close();
            
                // if drop was one of the commands in the sequence file, exit loop
                if (turnWillEnd) {
                    return true;
                } // if
            } // for
        } else if (command == "restart") {
            throw Game::GameException{false, true};
        } else if (command == "drop") { 
            curPlayer->drop();
            break;
        } else if (command == "I" || command == "J" || command == "L" || command == "O" ||
                   command == "S" || command == "Z" || command == "T") {
            curPlayer->setBlock(command);
        } else {
            std::cout << "Please enter a valid command" << std::endl;
            continue;
        } // if

        /** update/reprint display here **/
    } // while

    /** update/reprint display here <-- this will update screen after drop is called **/
    return true;
} // readCommands


void Game::promptSpecialActions() {
    while(true) {
        int n;

        std::cout << "Please select a special action: " << std::endl;
        std::cout << "1: heavy" << std::endl;
        std::cout << "2: force" << std::endl;
        std::cout << "3: blind" << std::endl;
        std::cout << "(enter the corresponding number)" << std::endl;

        if (std::cin >> n) {
            if (n == 1) {
                curPlayer->heavyOpponent();
            } else if (n == 2) {
                curPlayer->forceOpponent();
            } else if (n == 3) {
                curPlayer->blindOpponent();
            } else {
                std::cout << "Invalid input, please try again" << std::endl;
                continue;
            } // if

            return;
        } else {
            return;
        } // if
    } // while
} // promptSpecialActions


Game::Game(int startLevel, std::string sequenceFileName1, std::string sequenceFileName2, 
           bool textOnly, bool willSetSeed, int seed)
    : startLevel{startLevel}, 
      sequenceFileName1{sequenceFileName1}, 
      sequenceFileName2{sequenceFileName2},
      textOnly{textOnly},
      willSetSeed{willSetSeed},
      seed{seed},
      ng{new NumberGenerator(willSetSeed, seed)},
      player1{new Player(startLevel, sequenceFileName1, ng)}, 
      player2{new Player(startLevel, sequenceFileName2, ng)}, 
      curPlayer{nullptr},
      display{new GameDisplay(28, 23, startLevel)}
{} // constructor


Game::~Game() {
    delete player1;
    delete player2;
    delete display;
    // delete the XWindow, 
} // destructor


void Game::init() {
    player1->init(player2);
    player2->init(player1);
    curPlayer = player1;

    display->init();
    std::cout << (*display);
} // init


void Game::reset() { // *******????
    player1->reset();
    player2->reset();
    curPlayer = player1;
} // reset


void Game::tick() {

    // apply special effects
    curPlayer->applyEffects(); 
    /** update screen **/

    // read in commands until drop or restart
    std::cout << "Now reading commands: " << std::endl;
    readCommands(std::cin, false);
    
    // assume player has just called drop
    int rowsCleared = curPlayer->clearRows(); // store the amount of rows cleared
    curPlayer->checkRemovedBlocks();          // check if any blocks has been removed

    /*** update the board ***/

    bool hasLost = curPlayer->endTurn();      // end the turn, and check if player has lost

    if (hasLost) {
        char response;

        if (curPlayer == player1) {
            std::cout << "Sorry player 1, you have lost" << std::endl;
        } else {
            std::cout << "Sorry player 2, you have lost" << std::endl;
        } // if

        std::cout << "Would you like to restart? (Y/N)" << std::endl;
        std::cin >> response;

        if (response == 'Y' || response == 'y') {
            throw Game::GameException{false, true};
        } else {
            throw Game::GameException{true, false};
        } // if
    } else {
        if (curPlayer->getScore() > highscore) {
            highscore = curPlayer->getScore();
            // display->updateHighscore(highscore);
        } // if

        /*** print updated board ***/

        if (rowsCleared > 2) {
            promptSpecialActions();
        } // if
    } // if
} // tick


void Game::run() {
    while(true) {
        try {
            tick();
        } catch (Game::GameException& e) {
            if (e.status_restart()) {
                reset();
                init();
                continue;
            } else if (e.status_end()) {
                break;
            } // if
        } // try/catch

        // switch players to alternate turns
        curPlayer = (curPlayer == player1) ? player2 : player1;
    } // while
} // run


