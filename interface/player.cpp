#include <string>
#include <iostream>
#include "player.h"
#include "blockgenerator.h"
#include "numbergenerator.h"


Player::Player(int startLevel, std::string sequenceFileName, NumberGenerator* ng) 
    : startLevel{startLevel}, level{startLevel}, 
      score{0}, sequenceFileName{sequenceFileName},
      generator{new BlockGenerator(ng, sequenceFileName)} {} // constructor 


Player::~Player() {
    delete generator;
    // delete board, curBlock, nextBlock;
} // destructor


void Player::init(Player* opponent) {
    this->opponent = opponent;
    level = startLevel;
    score = 0;
    /** construct first curBlock and nextBlock based on level here! **/
} // init


void Player::reset() {
    /** delete placedBlocks, delete curBlock, nextBlock, reset BlockGenerator, etc here! **/
    init(opponent);
} // reset


void Player::left() {
    // curBlock->left()
    std::cout << "left" << std::endl;
} // left


void Player::right() {
    // curBlock->right()
    std::cout << "right" << std::endl;
} // right


void Player::down() {
    // curBlock->down()
    std::cout << "down" << std::endl;
} // down


void Player::clockwise() {
    // curBlock->clockwise()
    std::cout << "clockwise" << std::endl;
} // clockwise


void Player::counterclockwise() {
    // curBlock->counterclockwise()
    std::cout << "counterclockwise" << std::endl;
} // counterclockwise


void Player::levelUp() {
    if (level < maxLevel) {
        level += 1;
    } // if

    std::cout << "level up" << std::endl;
} // levelUp


void Player::levelDown() {
    if (level > minLevel) {
        level -= 1;
    } // if

    std::cout << "level down" << std::endl;
} // levelDown


void Player::random() {
    if (level > 2) {
        generator->unsetStream();
    } // if

    std::cout << "random" << std::endl;
} // random


void Player::noRandom(std::string noRandomFileName) {
    if (level > 2) {
        generator->setStream(noRandomFileName);
    } // if

    std::cout << "no random" << std::endl;
} // noRandom


void Player::setBlock(std::string blockType) { // needs err checking for block?
    // check if I can replace current block with the specified blocktype
    // if so, do so and delete previous curBlock
    std::cout << "set block" << std::endl;
} // setBlock


void Player::drop() {
    // add the dropped block to board's placedBlocks <-- this should be handled in board/block
    // curBlock->drop()

    if (hasBlind) {
        hasBlind = false;
        // board->unblind();
    } // if
    
    hasHeavy = false;
    std::cout << "drop\n\n" << std::endl;
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
        std::cout << "heavy applied! ";
        // curBlock->applyHeavy(); function just adds 3 to existing dropspeed
    } // if

    if (hasBlind) {
        std::cout << "blind applied! ";
        // board->blind()
    } // if

    std::cout << std::endl;
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