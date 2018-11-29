#include "starBlock.h"

starBlock::starBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    blockType ='*';
    numCells = 1;
}

void starBlock::rotateCounterClockwise() {}
void starBlock::rotateClockwise() {}