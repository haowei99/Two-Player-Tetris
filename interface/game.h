#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include <iostream>
#include <vector>
#include "player.h"
#include "gamedisplay.h"
#include "numbergenerator.h"
#include "commandinterpreter.h"
#include "window.h"

class Game {
    Xwindow* window;
    int startLevel;
    std::string sequenceFileName1;
    std::string sequenceFileName2;
    bool textOnly;
    bool willSetSeed;
    int seed;
    NumberGenerator* ng;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    GameDisplay* display;
    CommandInterpreter* ci;
    bool readingFromFile = false;
    std::vector<std::string> fileInputs;
    std::vector<std::string> commandList;

    void promptSpecialActions();
    void addFileInputs(std::string fileName);
    void loseGamePrompt();
    std::string getNextInput();
    void readCommands();

public:

    class GameException {
        bool endGame, restartGame;
    public:
        GameException(bool endGame, bool restartGame) 
            : endGame{endGame}, restartGame{restartGame} {} // constructor

        bool status_end() {
            return endGame;
        } // status_end

        bool status_restart() {
            return restartGame;
        } // status_restart
    };

    Game(int startLevel, std::string sequenceFileName1, 
         std::string sequenceFileName2, bool textOnly, bool willSetSeed, int seed);
    ~Game();
    void init();
    void reset();
    void tick();
    void run();
};

#endif /** __GAME_H__ **/