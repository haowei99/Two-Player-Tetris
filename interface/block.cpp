#include "block.h"
#include "cell.h"
#include "board.h"
#include <iostream>

Block::Block(int x, int y, int level, Board *board)
    : xCoor{x}, yCoor{y}, level{level}, board{board}, curLevel{level}, hasHeavy{false}, len{0} {
    /*
    if (level >= 3) {
        dropSpeed = 1;
    } else {
        dropSpeed = 0;  
    } // if
    */
} // constructor


Block::~Block() {} // destructor


void Block::applyHeavy(){
    hasHeavy = true;
}

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



//implement later
/*bool Block::onBoard() {
    for (int i = 0; i < len;i++) {
        if (cells[i]->getBlock() == this) {
            return true;
        } // if
    } // for

    return false;
} // onBoard
*/

void Block::addCell(Cell* cell) {
    if (cell != nullptr) {    
        cells[len] = cell;
        cell->set_X(cell->get_X()); //wont get coordinates!
        cell->set_Y(cell->get_Y());
        len = len + 1;
    } else {
        cells[len] = nullptr;
        len += 1;
    } // if
} // addCell

char Block::getBlockType() {
    return blockType;
}

bool Block::in_grid(int x, int y) {
    if ((x >= 0 && x < 11) && (y >= 0 && y < 18)) return true;
    else return  false;
}

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
}
void Block::left(){
    int x, y;
    if(!canMoveLeft()) {
        applyDropSpeed();
        return;
    }
    // check constraints
    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y(); //pos of block (new opsitition)
        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        cells[i]->set_X(x - 1);
    }
    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y();
        board->set(x, y);
        cells[i]->set_X(x + 1);
        cells[i] = board->cellAt(x, y);
    }
    applyDropSpeed();
}


void Block::shiftDown() {
    int x;
    int y;
   // check constraints
    if(!canMoveDown()) return;
    /*for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y();
        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
    }
    for (int i = 0; i < numCells; i++){
        board->set(x, y + 1);
        cells[i] = board->cellAt(x, y + 1);
    }*/
    for (int i = 0; i < numCells; i++){
        x = cells[i]->get_X();
        y = cells[i]->get_Y(); //pos of block (new positition)
        if(board->cellAt(x,y)->cellFilled()) board->unset(x, y);
        cells[i]->set_Y(y + 1);
    }
    for (int i = 0; i < numCells; i++){
        //int change = cells[i]->get_Y(); // change back to original
        x = cells[i]->get_X();
        y = cells[i]->get_Y();
        board->set(x, y);
        //re initialzie (TRYING TO CHANGE FOR NEXT 2 LINES DEBUGGING)
        cells[i]->set_Y(y - 1);
        cells[i] = board->cellAt(x,y);
        //cells[i]->set_Y(change - 1);
        //cells[i] = board->cellAt(cells[i]->get_X(), change);
    }
} // shiftDown


void Block::down(){
    shiftDown();
    applyDropSpeed();
}

void Block::drop(){
    while(true){
        if(!canMoveDown()) return;
        shiftDown();
    }
}

bool Block::canMoveDown(){
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x, y + 1)){
            return false; //base case?
        }; //if false return
    } // check constraints

    // check collision
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y); // unset first to avoid collision
    }

    bool canMove = true;

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y() + 1; //pos of block when move down 1
        if(board->cellAt(x,y)->cellFilled()){//if everything is filled
            canMove = false;
        }
    }

    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->set(x, y); // unset first to avoid collision
    }

    return canMove;
}
bool Block::canMoveRight(){
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x + 1, y)){
            return false;
        }; //if false return
    }

    //check collision
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y); // unset first to avoid collision
    }
    bool canMove = true;
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X() + 1;
        int y = cells[i]->get_Y(); //pos of block when move down 1
        if(board->cellAt(x,y)->cellFilled()){//if everything is filled
            canMove = false;
        }
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->set(x, y); // unset first to avoid collision
    }
    return canMove;
}

bool Block::canMoveLeft(){
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x - 1, y)){
            return false;
        }; //if false return
    }

    //check collision
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y); // unset first to avoid collision
    }
    bool canMove = true;
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X() - 1;
        int y = cells[i]->get_Y(); //pos of block when move down 1
        if(board->cellAt(x,y)->cellFilled()){//if everything is filled
            canMove = false;
        }
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->set(x, y); // unset first to avoid collision
    }
    return canMove;
}

int Block::getCellSize() {
    return numCells;
}
