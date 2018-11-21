#include "iBlock.h"

iBlock::iBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[0][0] = true;
    currShape[0][1] = true;
    currShape[0][2] = true;
    currShape[0][3] = true;
}

void iBlock::rotateClockwise() {
    bool rotations[2][4][4] = {
        {{0,0,0,0},
         {0,0,0,0},
         {0,0,0,0},
         {1,1,1,1}},
         
        {{1,0,0,0},
         {1,0,0,0},
         {1,0,0,0},
         {1,0,0,0}}

    };
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