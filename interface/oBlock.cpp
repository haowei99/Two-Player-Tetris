#include "oBlock.h"
#include "board.h"

using namespace::std;

oBlock::oBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'O';
}

void oBlock::rotateClockwise() {
    applyDropSpeed();
}

void oBlock::rotateCounterClockwise() {
    applyDropSpeed();
}

/*
void oBlock::right() {
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x + 1, y)){
            return;
        }; //if false return
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x + 1);
        board->unset(x, y);
        //board->set(x + 1, y);
    }
    for (int i = 0; i < numCells; i++){
        board->set(cells[i]->get_X(), cells[i]->get_Y());
    }
}


void oBlock::left() {
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x - 1, y)){
            return;
        }; //if false return
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        cells[i]->set_X(x - 1);
        board->unset(x, y);
        //board->set(x - 1, y);
    }
    for (int i = 0; i < numCells; i++){
        board->set(cells[i]->get_X(), cells[i]->get_Y());
    }
}

void oBlock::down() {
    // check constraints
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y();
        if(!in_grid(x, y + 1)){
            return;
        }; //if false return
    }
    for (int i = 0; i < numCells; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block
        if(board->cellAt(x,y)->cellFilled()) board->unset(x, y);
        cells[i]->set_Y(y + 1);
        //board->set(x, y + 1);
    }
    for (int i = 0; i < numCells; i++){
        board->set(cells[i]->get_X(), cells[i]->get_Y());
    }
}


void oBlock::drop() {} //need to implement
bool oBlock::canMoveDown() {
    return true; // need implement
}*/