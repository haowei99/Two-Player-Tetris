#include "block.h"
#include "cell.h"
#include "board.h"
#include <iostream>

Block::Block(int x, int y, int level, Board *board)
    : xCoor{x}, yCoor{y}, level{level}, board{board}, dropSpeed{0}, len{0} {
    if (level >= 3) {
        dropSpeed = 1;
    } // if
} // constructor


Block::~Block() {} // destructor



void Block::applyDropSpeed(){
    int speed = dropSpeed;
    while (speed > 0){
        down();
        speed--;
    }
}

void Block::applyHeavy(){
    dropSpeed += 3;
}


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
    cells[len] = cell;
    cell->set_X(cell->get_X()); //wont get coordinates!
    cell->set_Y(cell->get_Y());
    len = len + 1;
    std::cout << "Cell at: " << len << *cell << std::endl;
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
void Block::down(){
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
    applyDropSpeed();
}

void Block::drop(){
    while(true){
        if(!canMoveDown()) return;
        down();
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
