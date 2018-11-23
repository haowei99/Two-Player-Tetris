#include "zBlock.h"
#include "board.h"

using namespace::std;

zBlock::zBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'Z';
}

void zBlock::rotate(int state) {
    int x, y;
    if (state == 2) { //initial state is flat
        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x - 1);
        board->set(x - 1, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x - 1);
        cells[3]->set_Y(y - 2);
        board->set(x - 1, y - 2);

        //block 1 pivot point, does not change
    }
    else{
        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 1);
        cells[2]->set_Y(y);
        board->set(x + 1, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x + 1);
        cells[3]->set_Y(y + 2);
        board->set(x + 1, y + 2);

        //block 1 pivot point, does not change
    }
}

void zBlock::rotateClockwise() {
    rotate(rotateState);
    if (rotateState == 2) rotateState = 1;
    else rotateState = 2;
}

void zBlock::rotateCounterClockwise() {
    rotate(rotateState);
    if (rotateState == 1) rotateState = 2;
    else rotateState--;
}

void zBlock::down() {
    for (int i = numCells - 1; i >= 0 ; i--){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y);
        cells[i]->set_Y(y + 1);
        board->set(x, y + 1);
    }
}

void zBlock::drop() {} //need to implement
bool zBlock::canMoveDown() {
    return true; // need implement
}