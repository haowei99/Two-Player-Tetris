#include "zBlock.h"
#include "board.h"

using namespace::std;

zBlock::zBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'O';
}

void zBlock::rotateClockwise() {}

void zBlock::rotateCounterClockwise() {}


void zBlock::right() {
    for (int i = numCells - 1; i >= 0 ; i--){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x+1);
        board->unset(x, y);
        board->set(x + 1, y);
    }
}


void zBlock::left() {
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x - 1);
        board->unset(x, y);
        board->set(x - 1, y);
    }
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