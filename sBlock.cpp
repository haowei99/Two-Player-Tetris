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

        board->unset(x, y);
        cells[0]->set_X(x - 2);
        board->set(x - 2, y);

        //block 2/3 are pivot points

        //block 4
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 2);
        cells[2]->set_Y(y + 2);
        board->set(x + 2, y + 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x + 3);
        cells[3]->set_Y(y + 3);
        board->set(x + 3, y + 3);

        //block 1 pivot point, does not change
    }
    else{}
}
void sBlock::rotateClockwise() {}

void sBlock::rotateCounterClockwise() {
}


void sBlock::right() {
    for (int i = numCells - 1; i >= 0 ; i--){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x+1);
        board->unset(x, y);
        board->set(x + 1, y);
    }
}


void sBlock::left() {
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x - 1);
        board->unset(x, y);
        board->set(x - 1, y);
    }
}

void sBlock::down() {
    for (int i = numCells - 1; i >= 0 ; i--){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        board->unset(x, y);
        cells[i]->set_Y(y + 1);
        board->set(x, y + 1);
    }
}

void sBlock::drop() {} //need to implement
bool sBlock::canMoveDown() {
    return true; // need implement
}