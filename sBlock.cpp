#include "sBlock.h"
#include "board.h"

using namespace::std;

sBlock::sBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'S';
}
void sBlock::rotate(int state) {
    int x, y;
    if (state == 1) { //initial state is flat
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y - 2);
        cells[0] = board->cellAt(x, y - 2);

        //block 2/3 are pivot points

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 2, y);
        cells[3] = board->cellAt(x - 2, y);
    }
    else{
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y + 2);
        cells[0] = board->cellAt(x, y + 2);

        //block 2/3 are pivot points

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 2, y);
        cells[3] = board->cellAt(x + 2, y);
    }
}


void sBlock::rotateClockwise() {
    rotate(rotateState);
    if (rotateState == 2) rotateState = 1;
    else rotateState = 2;
}

void sBlock::rotateCounterClockwise() {
    rotate(rotateState);
    if (rotateState == 1) rotateState = 2;
    else rotateState--;
}