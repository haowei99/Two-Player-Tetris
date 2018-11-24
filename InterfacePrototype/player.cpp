#include <string>
#include <iostream>
#include "player.h"


Player::Player(int startLevel, std::string sequenceFileName) 
    : startLevel{startLevel}, level{startLevel}, 
      score{0}, sequenceFileName{sequenceFileName} {} // constructor 


Player::~Player() {} // destructor


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
    std::cout << "moved current block left!" << std::endl;
} // left


void Player::right() {
    std::cout << "moved current block right!" << std::endl;
} // right


void Player::down() {
    std::cout << "moved current block down!" << std::endl;
} // down


void Player::clockwise() {
    std::cout << "rotated current block clockwise!" << std::endl;
} // clockwise


void Player::counterclockwise() {
    std::cout << "rotated current block counterclockwise!" << std::endl;
} // counterclockwise


void Player::levelUp() {
    if (level < maxLevel) {
        level += 1;
        std::cout << "level up successful! current level: " << level << std::endl;
        return;
    } // if

    std::cout << "level up failed! current level: " << level << std::endl;
} // levelUp


void Player::levelDown() {
    if (level > minLevel) {
        level -= 1;
        std::cout << "level down successful! current level: " << level << std::endl;
        return;
    } // if

    std::cout << "level down failed! current level: " << level << std::endl;
} // levelDown


void Player::random() {
    if (level > 2) {
        std::cout << "randomness restored!" << std::endl;
        return;
    } // if

    std::cout << "can't call random on level: " << level << std::endl;
} // random


void Player::noRandom(std::string noRandomFileName) {
    if (level > 2) {
        std::cout << "no more randomness! Now reading blocks from: " << noRandomFileName << std::endl;
        return;
    } // if

    std::cout << "can't call noRandom on level: " << level << std::endl;
} // noRandom


void Player::drop() {
    std::cout << "block has been dropped!" << std::endl;
} // drop


void Player::setBlock(std::string blockType) { // needs err checking for block?
    std::cout << "current block has been replaced with a(n) " << blockType << "-block!" << std::endl;
} // setBlock


void Player::applyEffects() {
    if (hasHeavy) {
        std::cout << "heavy applied! ";
    } // if

    if (hasBlind) {
        std::cout << "blind applied! ";
        // board->blind()
    } // if

    std::cout << std::endl;
} // applyEffects


void Player::disableHeavy() {
    hasHeavy = false;
    // might need more logic depending on how blocks are shifted after they're placed
} // disableHeavy


void Player::disableBlind() {
    if (hasBlind) {
        hasBlind = false;
        // board->unBlind()
    } // if
} // disableBlind


void Player::disableForce() {
    hasForce = false;
} // disableForce


void Player::endTurn() {
    std::cout << "Player's turn has ended!" << std::endl << std::endl;
} // endTurn


void Player::heavyOpponent() {
    opponent->hasHeavy = true;
} // heavyOpponent


void Player::forceOpponent() {
    opponent->hasForce = true;
} // forceOpponent


void Player::blindOpponent() {
    opponent->hasBlind = true;
} // blindOpponent