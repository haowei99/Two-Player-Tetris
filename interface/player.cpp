#include <string>
#include <iostream>
#include "player.h"
#include "blockgenerator.h"
#include "numbergenerator.h"
#include "block.h"


Player::Player(int startLevel, std::string sequenceFileName, NumberGenerator* ng) 
    : startLevel{startLevel}, level{startLevel}, 
      score{0}, sequenceFileName{sequenceFileName},
      generator{new BlockGenerator(ng, sequenceFileName)} {} // constructor 


Player::~Player() {
    delete generator;
    delete board;
    delete curBlock;
    delete nextBlock;
} // destructor


void Player::init(Player* opponent) {
    this->opponent = opponent;
    level = startLevel;
    score = 0;
    curBlock = generator->generateBlock(level);
    nextBlock = generator->generateBlock(level);
} // init


void Player::reset() {
    delete curBlock;
    delete nextBlock;
    
    generator->reset();
    board->reset();
    init(opponent);
} // reset


void Player::left() {
    curBlock->left()
} // left


void Player::right() {
    curBlock->right()
} // right


void Player::down() {
    curBlock->down()
} // down


void Player::clockwise() {
    curBlock->clockwise()
} // clockwise


void Player::counterclockwise() {
    curBlock->counterclockwise()
} // counterclockwise


void Player::levelUp() {
    if (level < maxLevel) {
        level += 1;
    } // if
} // levelUp


void Player::levelDown() {
    if (level > minLevel) {
        level -= 1;
    } // if
} // levelDown


void Player::random() {
    if (level > 2) {
        generator->unsetStream();
    } // if
} // random


void Player::noRandom(std::string noRandomFileName) {
    if (level > 2) {
        generator->setStream(noRandomFileName);
    } // if
} // noRandom


void Player::setBlock(std::string blockType) { 
    // check if I can replace current block with the specified blocktype
    // if so, do so and delete previous curBlock

    char type = blockType[0];
    // board->replaceBlock(type);
} // setBlock


void Player::drop() {
    // add the dropped block to board's placedBlocks <-- this should be handled in board/block
    // curBlock->drop()

    if (hasBlind) {
        hasBlind = false;
        board->unblind();
    } // if
    
    hasHeavy = false;
} // drop


int Player::clearRows() {
    // clear filled rows, use returned val to calculated a score and add that to own score
    return 0;
} // clearRows


void Player::checkRemovedBlocks() {
    // check for any removed blocks, add returned score to own score
    // if no blocks has been cleared, and its been 5 blocks, and hasForce, 
    //     drop a starblock onto the board if able, board->dropStar()
    hasForce = false;
} // checkRemoveBlocks


bool Player::endTurn() {
    // check if nextBlock can be placed on the top of the board
    //     if not: I lose, return true
    //     if so: curBlock = nextBlock, update coords of nextBlock, 
    //            nextBlock = generator->getNextBlock(), return false
    return false;
} // endTurn


void Player::applyEffects() {
    if (hasHeavy) {
        curBlock->applyHeavy();
    } // if

    if (hasBlind) {
        board->blind()
    } // if
} // applyEffects


void Player::heavyOpponent() {
    opponent->hasHeavy = true;
} // heavyOpponent


void Player::forceOpponent() {
    opponent->hasForce = true;
} // forceOpponent


void Player::blindOpponent() {
    opponent->hasBlind = true;
} // blindOpponent


int Player::getScore() {
    return score;
} // getScore