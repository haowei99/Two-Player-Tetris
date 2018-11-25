#include "iBlock.h"
#include "board.h"

iBlock::iBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    blockType ='I';
    numCells = 4;
}


bool iBlock::rotate(int state) {
    int x, y;
    if (state == 2) { //initial state is flat
        // check if 4th block is out of bounds when rotate
        x = cells[3]->get_X() + 3;
        y = cells[3]->get_Y() + 3; //pos of block
        if (!in_grid(x, y )) return false;
        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x + 1);
        cells[1]->set_Y(y + 1);
        board->set(x + 1, y + 1);


        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 2);
        cells[2]->set_Y(y + 2);
        board->set(x + 2, y + 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x + 3);
        cells[3]->set_Y(y + 3);
        board->set(x + 3, y + 3);

        //block 1 pivot point, does not change
    }
    else{
        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x - 1);
        cells[1]->set_Y(y - 1);
        board->set(x - 1, y - 1);


        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x - 2);
        cells[2]->set_Y(y - 2);
        board->set(x - 2, y - 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x - 3);
        cells[3]->set_Y(y - 3);
        board->set(x - 3, y - 3);

        //block 1 pivot point, does not change
    }
    return true;
}


void iBlock::rotateClockwise() {
    if(rotate(rotateState)) {
        if (rotateState == 2) rotateState = 1;
        else rotateState = 2;
    }
}

void iBlock::rotateCounterClockwise() {
    if (rotate(rotateState)) {
        if (rotateState == 1) rotateState = 2;
        else rotateState--;
    }
}

/*
void iBlock::right() {
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x + 1, y)){
            return;
        }; //if false return
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x + 1);
        board->unset(x, y);
        //board->set(x + 1, y);
    }
    for (int i = 0; i < numCells; i++){
        board->set(cells[i]->get_X(), cells[i]->get_Y());
    }
}


void iBlock::left() {
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x - 1, y)){
            return;
        }; //if false return
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x - 1);
        board->unset(x, y);
        //board->set(x - 1, y);
    }
    for (int i = 0; i < numCells; i++){
        board->set(cells[i]->get_X(), cells[i]->get_Y());
    }
}

void iBlock::down() {
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x, y + 1)){
            return;
        }; //if false return
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        if(board->cellAt(x,y)->cellFilled()) board->unset(x, y);
        cells[i]->set_Y(y + 1);
        //board->set(x, y + 1);
    }
    for (int i = 0; i < numCells; i++){
        board->set(cells[i]->get_X(), cells[i]->get_Y());
    }
}

bool iBlock::canMoveDown() {
    return true;//need to implement
}

void iBlock::drop() {

}
*/