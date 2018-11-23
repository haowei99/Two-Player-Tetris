#include "jBlock.h"
#include "board.h"

jBlock::jBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    blockType = 'J';
    numCells = 4; 
}

void jBlock::rotateClockwise() {
}

void jBlock::rotateCounterClockwise() {
}

void jBlock::right() {
    for (int i = numCells - 1; i >= 0 ; i--){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x+1);
        board->unset(x, y);
        board->set(x + 1, y);
    }
}


void jBlock::left() {
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x - 1);
        board->unset(x, y);
        board->set(x - 1, y);
    }
}

void jBlock::down() {
    //board->cellAt(x, y + 1);
    y = y + 1;
}