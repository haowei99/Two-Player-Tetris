#include "oBlock.h"

oBlock::oBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[0][0] = true;
    currShape[0][1] = true;
    currShape[1][0] = true;
    currShape[1][1] = true;
}

void oBlock::rotateClockwise() {}

void oBlock::rotateCounterClockwise() {}

void oBlock::right() {
    x = x + 1;
}


void oBlock::left() {
    x = x - 1;
}

void oBlock::down() {
    y = y + 1;
}

