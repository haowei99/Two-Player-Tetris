#include <iostream>
#include "block.h"
#include "cell.h"
#include "board.h"


Block::Block(int level, Board *board)
    : level{level}, board{board}, curLevel{level}, hasHeavy{false}, len{0} {
} // constructor


Block::~Block() {} // destructor


// Player calls this to notify the block that it has the heavy effect
void Block::applyHeavy(){
    hasHeavy = true;
} // applyHeavy


void Block::applyDropSpeed(){
    int speed = 0;

    switch(curLevel) {
        case 0:
        case 1:
        case 2:
            speed = 0;
            break;
        case 3:
        case 4:
            speed = 1;
            break;
    } // switch

    if (hasHeavy) {
        speed += 3;
    } // if

    while (speed > 0){
        shiftDown();
        speed--;
    } // while
} // applyDropSpeed


void Block::setCurLevel(int newCurLevel) {
    curLevel = newCurLevel;
} // setCurLevel


int Block::getPoints() {
    return (level + 1) * (level + 1);
} // getPoints


void Block::addCell(Cell* cell) {
    if (cell != nullptr) {    
        cells[len] = cell;
        cell->set_X(cell->get_X());
        cell->set_Y(cell->get_Y());
        len = len + 1;
    } else {
        cells[len] = nullptr;
        len += 1;
    } // if
} // addCell


char Block::getBlockType() {
    return blockType;
} // getBlockType


bool Block::in_grid(int x, int y) {
    if ((x >= 0 && x < 11) && (y >= 0 && y < 18)) return true;
    else return  false;
} // in_grid


void Block::right(){
    int x, y;
    if(!canMoveRight()){
        applyDropSpeed();
        return;
    }
    // check constraints
    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y(); //pos of block (new opsitition)
        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        cells[i]->set_X(x + 1);
    }
    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y();
        board->set(x, y);
        cells[i]->set_X(x - 1);
        cells[i] = board->cellAt(x, y);
    }
    applyDropSpeed();
} // right


void Block::left(){
    int x, y;

    if(!canMoveLeft()) {
        applyDropSpeed();
        return;
    } // if

    // check constraints
    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y(); //pos of block (new positition)
        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        cells[i]->set_X(x - 1);
    } // for

    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y();
        board->set(x, y);
        cells[i]->set_X(x + 1);
        cells[i] = board->cellAt(x, y);
    } // for

    applyDropSpeed();
} // left


void Block::shiftDown() {
    int x;
    int y;

    // check constraints
    if(!canMoveDown()) return;

    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y(); //pos of block (new positition)
        if(board->cellAt(x,y)->cellFilled()) board->unset(x, y);
        cells[i]->set_Y(y + 1);
    } // for

    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y();
        board->set(x, y);
        cells[i]->set_Y(y - 1);
        cells[i] = board->cellAt(x,y);
    } // for
} // shiftDown


void Block::down(){
    shiftDown();
    applyDropSpeed();
} // down


void Block::drop(){
    while(true){
        if(!canMoveDown()) return;
        shiftDown();
    } // while
} // drop


bool Block::canMoveDown(){
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x, y + 1)){
            return false; //base case
        }; // if false return
    } // for

    // check collision
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); // pos of block
        board->unset(x, y); // unset first to avoid collision
    } // for

    bool canMove = true;

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y() + 1; // pos of block when move down 1
        if(board->cellAt(x,y)->cellFilled()){ // if everything is filled
            canMove = false;
        } // if
    } // for

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->set(x, y); // unset first to avoid collision
    } // for

    return canMove;
} // canMoveDown


bool Block::canMoveRight(){
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x + 1, y)){
            return false;
        }; //if false return
    } // for

    //check collision
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y); // unset first to avoid collision
    } // for

    bool canMove = true;

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X() + 1;
        int y = cells[i]->get_Y(); //pos of block when move down 1
        if(board->cellAt(x,y)->cellFilled()){//if everything is filled
            canMove = false;
        } // if
    } // for

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->set(x, y); // unset first to avoid collision
    } // for

    return canMove;
} // canMoveRight


bool Block::canMoveLeft(){
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x - 1, y)){
            return false;
        }; // if false return
    } // for

    // check collision
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); // pos of block
        board->unset(x, y); // unset first to avoid collision
    } // for

    bool canMove = true;
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X() - 1;
        int y = cells[i]->get_Y(); // pos of block when move down 1
        if(board->cellAt(x,y)->cellFilled()){ // if everything is filled
            canMove = false;
        } // if
    } // for

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->set(x, y); // unset first to avoid collision
    } // for

    return canMove;
} // canMoveLeft


int Block::getCellSize() {
    return numCells;
} // getCellSize
