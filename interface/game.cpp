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
#include "window.h"

void Game::loseGamePrompt() {
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
} // loseGamePrompt


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

        // because L and S conflict with levelup/leveldown and sequence
        if (command == "I" || command == "J" || command == "L" || command == "O" ||
            command == "S" || command == "Z" || command == "T") {   
            curPlayer->setBlock(command);
            std::cout << (*display);
            continue;
        } // if

        command = ci->interpret(command); // interpret the command and apply shortcuts

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

            if (curPlayer == player1) {
                display->updatePlayer1Level(curPlayer->getLevel());
            } else {
                display->updatePlayer2Level(curPlayer->getLevel());
            } // if

        } else if (command == "leveldown") {

            for (int i = 0;i < multiplier;i++) {
                curPlayer->levelDown();
            } // for

            if (curPlayer == player1) {
                display->updatePlayer1Level(curPlayer->getLevel());
            } else {
                display->updatePlayer2Level(curPlayer->getLevel());
            } // if

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
            throw Game::GameException{false, true};

        } else if (command == "drop") { 

            curPlayer->drop();
            break;

        } else {

            std::cout << "Please enter a valid command" << std::endl;
            continue;

        } // if

        std::cout << (*display);
    } // while

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
                char type;
                
                std::cout << "Please enter a valid block type: " << std::endl;
                std::cin >> type;

                curPlayer->forceOpponent(type);
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
    : window{textOnly ? nullptr : new Xwindow(700, 650)},
      startLevel{startLevel}, 
      sequenceFileName1{sequenceFileName1}, 
      sequenceFileName2{sequenceFileName2},
      textOnly{textOnly},
      willSetSeed{willSetSeed},
      seed{seed},
      ng{new NumberGenerator(willSetSeed, seed)},
      player1{new Player(0, 100, startLevel, sequenceFileName1, ng, window)}, 
      player2{new Player(425, 100, startLevel, sequenceFileName2, ng, window)}, 
      curPlayer{nullptr},
      display{new GameDisplay(startLevel, window)},
      ci{new CommandInterpreter()} {
    ci->addCommand("left");
    ci->addCommand("right");
    ci->addCommand("down");
    ci->addCommand("clockwise");
    ci->addCommand("counterclockwise");
    ci->addCommand("drop");
    ci->addCommand("levelup");
    ci->addCommand("leveldown");
    ci->addCommand("random");
    ci->addCommand("norandom");
    ci->addCommand("sequence");
    ci->addCommand("restart");
    ci->addCommand("I");
    ci->addCommand("J");
    ci->addCommand("L");
    ci->addCommand("O");
    ci->addCommand("S");
    ci->addCommand("Z");
    ci->addCommand("T");
} // constructor


Game::~Game() {
    delete player1;
    delete player2;
    delete display;
    delete window;
    delete ng;
    delete ci;
} // destructor


void Game::init() {
    player1->init(player2);
    player2->init(player1);
    display->init(player1->getBoard(), player2->getBoard());

    curPlayer = player1;
} // init


void Game::reset() { 
    player1->reset();
    player2->reset();
    display->reset();
} // reset


void Game::tick() {
    // apply special effects, if false returned, player has lost
    if (!(curPlayer->applyEffects())) {
        loseGamePrompt();
    } // if

    std::cout << (*display);

    // read in commands until drop or restart
    std::cout << "Now reading commands: " << std::endl;
    readCommands();
    
    // assume player has just called drop
    int rowsCleared = curPlayer->clearRows(); // store the amount of rows cleared
    curPlayer->checkRemovedBlocks();          // check if any blocks has been removed

    bool hasLost = curPlayer->endTurn();      // end the turn, and check if player has lost

    if (hasLost) {
        loseGamePrompt();
    } else {
        if (curPlayer == player1) {
            display->updatePlayer1Highscore(curPlayer->getHighscore());
            display->updatePlayer1Score(curPlayer->getScore());
        } else {
            display->updatePlayer2Highscore(curPlayer->getHighscore());
            display->updatePlayer2Score(curPlayer->getScore());
        } // if

        std::cout << (*display);

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


