#include "sBlock.h"

sBlock::sBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[2][0] = true;
    currShape[2][1] = true;
    currShape[1][1] = true;
    currShape[1][2] = true;
}

void sBlock::rotateClockwise() {
    bool rotations[2][3][3] = {
        {{0,0,0},
         {0,1,1},
         {1,1,0}},

        {{1,0,0},
         {1,1,0},
         {0,1,0}}
    };
}

void sBlock::rotateCounterClockwise() {
    bool rotations[2][3][3] = {
        {{0,0,0},
         {0,1,1},
         {1,1,0}},

        {{1,0,0},
         {1,1,0},
         {0,1,0}}
    };
}

void sBlock::right() {
    //board->cellAt(x + 1, y);
    x = x + 1;
}


void sBlock::left() {
    //board->cellAt(x - 1, y);
    x = x - 1;
}

void sBlock::down() {
    //board->cellAt(x, y + 1);
    y = y + 1;
}