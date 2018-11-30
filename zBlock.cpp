#include "zBlock.h"
#include "board.h"

using namespace::std;

zBlock::zBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'Z';
}

void zBlock::rotate(int state) {
    int x, y;
    if (state == 1) { //initial state is flat
        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y);
        cells[2] = board->cellAt(x - 1, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y - 2);
        cells[3] = board->cellAt(x - 1, y - 2);
    }
    else{
        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y);
        cells[2] = board->cellAt(x + 1, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y + 2);
        cells[3] = board->cellAt(x + 1, y + 2);

        //block 1 pivot point, does not change
    }
}

void zBlock::rotateClockwise() {
    rotate(rotateState);
    if (rotateState == 2) rotateState = 1;
    else rotateState = 2;
    applyDropSpeed();
}

void zBlock::rotateCounterClockwise() {
    rotate(rotateState);
    if (rotateState == 1) rotateState = 2;
    else rotateState--;
    applyDropSpeed();
}