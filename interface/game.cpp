#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "player.h"
#include "numbergenerator.h"
#include "gamedisplay.h"
#include "game.h"


void Game::addFileInputs(std::string fileName) {
    std::ifstream in(fileName.c_str());
    std::string command;
    std::vector<std::string> commandsInOrder;

    while (in >> command) {
        commandsInOrder.emplace_back(command);
    } // while

    int len = commandsInOrder.size();

    for (int i = len-1;i >= 0;i--) {
        fileInputs.emplace_back(commandsInOrder.at(i));
    } // for

    in.close();
    readingFromFile = true;
} // addFileInputs


std::string Game::getNextInput() {
    std::string input;
    
    if (readingFromFile) {
        input = fileInputs.back();
        fileInputs.pop_back();

        if (fileInputs.size() == 0) {
            readingFromFile = false;
        } // if
    } else {
        std::cin >> input;

        if (std::cin.fail()) {
            throw Game::GameException{true, false};
        } // if
    } // if

    return input;
} // getNextInput


void Game::readCommands() {
    /** TODOS:
     * add logic for printing display when command called
     * add shortcuts
     * write a higher order function to make command multiplication easier? 
     **/
    
    while (true) {
        std::string input = getNextInput();
        std::istringstream iss(input);
        std::string command;
        int multiplier;

        if (!(iss >> multiplier)) {
            multiplier = 1;
            iss.clear();
        } // if

        iss >> command;

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

            std::string noRandomFileName = getNextInput();
            curPlayer->noRandom(noRandomFileName);

        } else if (command == "random") { 

            curPlayer->random();

        } else if (command == "sequence") { 

            std::string fileName = getNextInput();

            for (int i = 0;i < multiplier;i++) {
                addFileInputs(fileName);
            } // for

        } else if (command == "restart") {

            std::cout << "restart" << std::endl;
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
} // readCommands


void Game::promptSpecialActions() {
    while (true) {
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
    //std::cout << (*display);
} // init


void Game::reset() { 
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
    readCommands();
    
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
    while (true) {
        if (curPlayer == player1) {
            std::cout << "Player 1 turn begins" << std::endl;
        } else {
            std::cout << "Player 2 turn begins" << std::endl;
        } // if
        
        try {
            tick();
        } catch (Game::GameException& e) {
            if (e.status_restart()) {
                reset();
                init();
                std::cout << "\n\n";
                continue;
            } else if (e.status_end()) {
                break;
            } // if
        } // try/catch

        // switch players to alternate turns
        curPlayer = (curPlayer == player1) ? player2 : player1;
    } // while
} // run


