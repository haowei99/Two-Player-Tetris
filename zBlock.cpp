#include "zBlock.h"

zBlock::zBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[1][0] = true;
    currShape[1][1] = true;
    currShape[2][1] = true;
    currShape[2][2] = true;
}

void zBlock::rotateClockwise() {
    bool rotations[2][3][3] = {
        {{0,0,0},
         {1,1,0},
         {0,1,1}},

        {{0,1,0},
         {1,1,0},
         {1,0,0}}
    };
}

void zBlock::rotateCounterClockwise() {
    bool rotations[4][3][3] = {
        {{0,0,0},
         {1,1,0},
         {0,1,1}},
        
        {{0,1,0},
         {1,1,0},
         {1,0,0}}
        
    };
}

void zBlock::right() {
    //board->cellAt(x + 1, y);
    x = x + 1;
}


void zBlock::left() {
    //board->cellAt(x - 1, y);
    x = x - 1;
}

void zBlock::down() {
    //board->cellAt(x, y + 1);
    y = y + 1;
}