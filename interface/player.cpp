#include <string>
#include <iostream>
#include "player.h"
#include "blockgenerator.h"
#include "numbergenerator.h"
#include "board.h"
#include "block.h"


Player::Player(int x, int y, int startLevel, std::string sequenceFileName, NumberGenerator* ng) 
    : board{new Board(x, y)}, startLevel{startLevel}, level{startLevel}, 
      score{0}, sequenceFileName{sequenceFileName},
      generator{new BlockGenerator(board, ng, sequenceFileName)} {} // constructor 


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
<<<<<<< HEAD
    delete curBlock;
    delete nextBlock;
    blocksDropped = 0;
    
    generator->reset();
    board->reset();
=======
    /** delete placedBlocks, delete curBlock, nextBlock, reset BlockGenerator, etc here! **/
>>>>>>> f9b30a59922139a42525da93ee55ff053ede6551
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
<<<<<<< HEAD

    board->swapBlock(blockType[0]);
=======
    std::cout << "set block" << std::endl;
>>>>>>> f9b30a59922139a42525da93ee55ff053ede6551
} // setBlock


void Player::drop() {
    // add the dropped block to board's placedBlocks <-- this should be handled in board/block
    curBlock->drop()

    if (hasBlind) {
        hasBlind = false;
        // board->unblind();
    } // if
    
    hasHeavy = false;
<<<<<<< HEAD
    hasForce = false;
    blocksDropped += 1;
=======
    std::cout << "drop\n\n" << std::endl;
>>>>>>> f9b30a59922139a42525da93ee55ff053ede6551
} // drop


int Player::clearRows() {
    // clear filled rows, use returned val to calculated a score and add that to own score
    int rowsCleared = board->clearRow();
    score += ((level + rowsCleared) * (level + rowsCleared)); 

    if (rowsCleared == 0) {
        if (blocksDropped % 5 == 0 && level >= 4) {
            board->dropStar(level);
        } // if
    } else {
        blocksDropped = 0;
    } // if

    return rowsCleared;
} // clearRows


void Player::checkRemovedBlocks() {
    // check for any removed blocks, add returned score to own score
    //    - call count_score()
    score += board->count_score();
} // checkRemoveBlocks


bool Player::endTurn() {
    // check if nextBlock can be placed on the top of the board
    //     if not: I lose, return true
    //     if so: curBlock = nextBlock
    //            nextBlock = generator->getNextBlock(), return false
    if (board->canFitNew()) {
        curBlock = nextBlock;
        nextBlock = generator->getNextBlock();
        return false;
    } else {
        return true;
    } // if
} // endTurn

// return false if player loses
bool Player::applyEffects() {
    if (hasHeavy) {
        std::cout << "heavy applied! ";
        // curBlock->applyHeavy(); function just adds 3 to existing dropspeed
    } // if

    if (hasBlind) {
<<<<<<< HEAD
        board->blind();
    } // if

    if (hasForce) {
        if (!(board->swapBlock(forceType))) {
            return false;
        } // if
    } // if

    return true;
=======
        std::cout << "blind applied! ";
        // board->blind()
    } // if

    std::cout << std::endl;
>>>>>>> f9b30a59922139a42525da93ee55ff053ede6551
} // applyEffects


void Player::heavyOpponent() {
    opponent->hasHeavy = true;
} // heavyOpponent


void Player::forceOpponent(char type) {
    opponent->hasForce = true;
    opponen->forceType = type;
} // forceOpponent


void Player::blindOpponent() {
    opponent->hasBlind = true;
} // blindOpponent


int Player::getScore() {
    return score;
} // getScore