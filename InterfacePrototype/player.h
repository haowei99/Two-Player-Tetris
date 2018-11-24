#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>

const int maxLevel = 4;
const int minLevel = 0;

class Player {
    int startLevel;
    int level;
    int score;
    std::string sequenceFileName;
    Player* opponent;
    bool hasHeavy, hasForce, hasBlind = false;
    // BlockGenerator generator;
    // placeBlocks
public:
    Player(int startLevel, std::string sequenceFileName);
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
    void setBlock(std::string blockType);
    void applyEffects();
    void disableHeavy();
    void disableBlind();
    void disableForce();
    void heavyOpponent();
    void forceOpponent();
    void blindOpponent();
    void endTurn();
};

#endif /** __PLAYER_H__ **/