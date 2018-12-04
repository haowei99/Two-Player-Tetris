#include "oBlock.h"
#include "board.h"


oBlock::oBlock(int level, Board *board): Block{level, board} {
    numCells = 4;
    blockType = 'O';
}


void oBlock::rotateClockwise() {
    applyDropSpeed();
}


void oBlock::rotateCounterClockwise() {
    applyDropSpeed();
}

