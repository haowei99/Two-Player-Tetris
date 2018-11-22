#include <string>
#include <iostream>
#include "game.h"


Game::Game(int startLevel, std::string sequenceFileName1, std::string sequenceFileName2)
    : startLevel{startLevel}, 
      sequenceFileName1{sequenceFileName1}, 
      sequenceFileName2{sequenceFileName2},
      player1{new Player(startLevel, sequenceFileName1)}, 
      player2{new Player(startLevel, sequenceFileName2)}, 
      curPlayer{nullptr}
{

} // constructor


Game::~Game() {
    delete player1;
    delete player2;
    // delete the XWindow, 
} // destructor


void Game::init() {
    player1->init(player2);
    player2->init(player1);
    curPlayer = player1;
} // init


void Game::reset() { // *******????
    player1->reset();
    player2->reset();
    curPlayer = player1;
} // reset


void Game::tick() {
    // follow instructions in doc
} // tick


void Game::run() {
    while(true) {
        try {
            tick();
        } catch (EndGameException e) {
            break;
        } // try/catch
    } // while
} // run