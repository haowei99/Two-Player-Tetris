#include "oBlock.h"
#include "board.h"

oBlock::oBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[0][0] = true;
    currShape[0][1] = true;
    currShape[1][0] = true;
    currShape[1][1] = true;
    numCells = 4;
}

void oBlock::rotateClockwise() {}

void oBlock::rotateCounterClockwise() {}


void oBlock::right() {
    for (int i =0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 1, y);
    }
}


void oBlock::left() {
    for (int i =0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 1, y);
    }
}

void oBlock::down() {
    for (int i =0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y);
        board->set(x, y + 1);
    }
}