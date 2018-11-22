#include "iBlock.h"

iBlock::iBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[0][0] = true;
    currShape[0][1] = true;
    currShape[0][2] = true;
    currShape[0][3] = true;
}

void iBlock::rotateClockwise() {
    if (rotateState == 1){
        for (int i = 0; i <numCells; i++){
            int x = cells[i]->get_X();
            int y = cells[i]->get_Y(); //pos of block

            board->unset(x,y);
            board->set(x, -y, 'I');

        }
    }



    //Change state at the end
    if (rotateState == 2) rotateState = 1;
    else rotateState++;
}

void iBlock::rotateCounterClockwise() {
}

void iBlock::right() {
    //board->cellAt(x + 1, y);
    x = x + 1;
}


void iBlock::left() {
    //board->cellAt(x - 1, y);
    x = x - 1;
}

void iBlock::down() {
    //board->cellAt(x, y + 1);
    y = y + 1;
}