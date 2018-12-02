#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "numbergenerator.h"
#include "blockgenerator.h"
#include "block.h"
#include "board.h"

const int maxLevel = 4;
const int minLevel = 0;

class Player {
    Board* board;
    int startLevel;
    std::string sequenceFileName;
    BlockGenerator* generator;
    Player* opponent;
    bool hasHeavy, hasForce, hasBlind = false;
    Block* curBlock;
    Block* nextBlock;
    int blocksDropped = 0;
    char forceType;
    int level;
    int score = 0;
    int highscore = 0;
public:
    Player(int x, int y, int startLevel, std::string sequenceFileName, NumberGenerator* ng);
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
    bool applyEffects();
    void heavyOpponent();
    void forceOpponent(char type);
    void blindOpponent();
    int getScore();
    int getHighscore();
    int getLevel();
    Board* getBoard();
};

#endif /** __PLAYER_H__ **/