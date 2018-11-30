#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "numbergenerator.h"
#include "blockgenerator.h"

const int maxLevel = 4;
const int minLevel = 0;

class Player {
    int startLevel;
    int level;
    int score;
    std::string sequenceFileName;
    BlockGenerator* generator;
    Player* opponent;
    bool hasHeavy, hasForce, hasBlind = false;
public:
    Player(int startLevel, std::string sequenceFileName, NumberGenerator* ng);
    ~Player();
    void init(Player* opponent);
    void reset();
    void left();
    void right();
    void down();
    void clockwise();
    void counterclockwise();
    void levelUp();
    void levelDown();
    void random();
    void noRandom(std::string noRandomFileName);
    void drop();
    int clearRows();
    void checkRemovedBlocks();
    bool endTurn();
    void setBlock(std::string blockType);
    void applyEffects();
    void heavyOpponent();
    void forceOpponent();
    void blindOpponent();
    int getScore();
};

#endif /** __PLAYER_H__ **/