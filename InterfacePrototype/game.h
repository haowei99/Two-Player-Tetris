#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include <iostream>
#include "player.h"
#include "display.h"

class Game {
    int startLevel;
    std::string sequenceFileName1;
    std::string sequenceFileName2;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    Display* display;
    // XWindow* window;

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

    Game(int startLevel, std::string sequenceFileName1, std::string sequenceFileName2);
    ~Game();
    void init();
    void reset();
    void tick();
    void run();

private:
    bool readCommands(std::istream& in, bool readingFromFile, std::string fileName = "");
};

#endif /** __GAME_H__ **/