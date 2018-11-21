#include "tBlock.h"

tBlock::tBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[1][2] = true;
    currShape[2][0] = true;
    currShape[2][1] = true;
    currShape[2][2] = true;
}

void tBlock::rotateClockwise() {
    bool rotations[4][3][3] = {
        {{1,1,1},
         {0,1,0},
         {0,0,0}},

        {{0,1,0},
         {1,1,0},
         {0,1,0}},

        {{0,1,0},
         {1,1,1},
         {0,0,0}},

        {{1,0,0},
         {1,1,0},
         {1,0,0}}
    };
}

void tBlock::rotateCounterClockwise() {
    bool rotations[4][3][3] = {
        {{1,1,1},
         {0,1,0},
         {0,0,0}},
        
        {{1,0,0},
         {1,1,0},
         {1,0,0}},

        {{0,1,0},
         {1,1,1},
         {0,0,0}},

        {{0,1,0},
         {1,1,0},
         {0,1,0}}
        
    };
}

void tBlock::right() {
    //board->cellAt(x + 1, y);
    x = x + 1;
}


void tBlock::left() {
    //board->cellAt(x - 1, y);
    x = x - 1;
}

void tBlock::down() {
    //board->cellAt(x, y + 1);
    y = y + 1;
}