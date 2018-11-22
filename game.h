#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include <iostream>
#include "player.h"
//#include "display.h"

class Game {
    int startLevel;
    std::string sequenceFileName1;
    std::string sequenceFileName2;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    // Display* display;
    // XWindow* window;

public:
    Game(int startLevel, std::string sequenceFileName1, std::string sequenceFileName2);
    ~Game();
    void init();
    void reset();
    void tick();
    void run();
};

#endif /** __GAME_H__ **/