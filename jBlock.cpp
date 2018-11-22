#include "jBlock.h"

jBlock::jBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[1][0] = true;
    currShape[2][0] = true;
    currShape[2][1] = true;
    currShape[2][2] = true;
}

void jBlock::rotateClockwise() {
    bool rotations[4][3][3] = {
        {{0,0,0},
         {1,0,0},
         {1,1,1}},

        {{1,1,0},
         {1,0,0},
         {1,0,0}},

        {{0,0,0},
         {1,1,1},
         {0,0,1}},

        {{0,1,0},
         {0,1,0},
         {1,1,0}}
    };
}

void jBlock::rotateCounterClockwise() {
    bool rotations[4][3][3] = {
        {{0,0,0},
         {1,0,0},
         {1,1,1}},
        
        {{0,1,0},
         {0,1,0},
         {1,1,0}},

        {{0,0,0},
         {1,1,1},
         {0,0,1}},

        {{1,1,0},
         {1,0,0},
         {1,0,0}}
        
    };
}

void jBlock::right() {
    //board->cellAt(x + 1, y);
    x = x + 1;
}


void jBlock::left() {
    //board->cellAt(x - 1, y);
    x = x - 1;
}

void jBlock::down() {
    //board->cellAt(x, y + 1);
    y = y + 1;
}