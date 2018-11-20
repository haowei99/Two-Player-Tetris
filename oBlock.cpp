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
    board->cellAt(x + 1, y);
    x = x + 1;
}


void oBlock::left() {
    board->cellAt(x - 1, y);
    x = x - 1;
}

void oBlock::down() {
    board->cellAt(x, y + 1);
    y = y + 1;
}

