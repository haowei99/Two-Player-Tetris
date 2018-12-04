#include "starBlock.h"


starBlock::starBlock(int level, Board *board): Block{level, board} {
    blockType ='*';
    numCells = 1;
}


void starBlock::rotateCounterClockwise() {}


void starBlock::rotateClockwise() {}

