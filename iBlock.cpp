#include "iBlock.h"
#include "board.h"

iBlock::iBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[0][0] = true;
    currShape[0][1] = true;
    currShape[0][2] = true;
    currShape[0][3] = true;
    numCells = 4;
}


void iBlock::rotate(int state) {
    int x, y;
    if (state == 2) { //initial state is flat
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 3, y + 3);


        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 2, y + 2);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 1, y + 1);

        //block 4 pivot point, does not change
    }
    else{
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 3, y - 3);


        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 2, y - 2);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 1, y - 1);

        //block 4 pivot point, does not change
    }
}
void iBlock::rotateClockwise() {
    rotate(rotateState);
    if (rotateState == 2) rotateState = 1;
    else rotateState = 2;
}

void iBlock::rotateCounterClockwise() {
    rotate(rotateState);
    if (rotateState == 1) rotateState = 2;
    else rotateState--;
}

void iBlock::right() {
    for (int i =0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 1, y);
    }
}


void iBlock::left() {
    for (int i =0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 1, y);
    }
}

void iBlock::down() {
    for (int i =0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x, y + 1);
    }
}