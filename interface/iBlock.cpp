#include "iBlock.h"
#include "board.h"

iBlock::iBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    blockType ='I';
    numCells = 4;
}


bool iBlock::rotate(int state) {
    int x, y;
    if (state == 2) { //initial state is flat
        // check if 4th block is out of bounds when rotate
        x = cells[3]->get_X() + 3;
        y = cells[3]->get_Y() + 3; //pos of block
        if (!in_grid(x, y)) return false;
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        if((board->cellAt(x + 1, y)->cellFilled()) ||
        (board->cellAt(x + 2, y)->cellFilled()) || (board->cellAt(x + 3, y)->cellFilled())){
            return false;
        } //collision detection

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y + 1);
        cells[1] = board->cellAt(x + 1, y + 1);


        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 2, y + 2);
        cells[2] = board->cellAt(x + 2, y + 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 3, y + 3);
        cells[3] = board->cellAt(x + 3, y + 3);

        //block 1 pivot point, does not change
    }
    else{
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        if((board->cellAt(x, y - 1)->cellFilled()) ||
           (board->cellAt(x, y - 2)->cellFilled()) || (board->cellAt(x, y - 3)->cellFilled())){
            return false;
        } //collision detection
        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y - 1);
        cells[1] = board->cellAt(x - 1, y - 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 2, y - 2);
        cells[2] = board->cellAt(x - 2, y - 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 3, y - 3);
        cells[3] = board->cellAt(x - 3, y - 3);

        //block 1 pivot point, does not change
    }
    return true;
}


void iBlock::rotateClockwise() {
    if(rotate(rotateState)) {
        if (rotateState == 2) rotateState = 1;
        else rotateState = 2;
    }
    applyDropSpeed();
}

void iBlock::rotateCounterClockwise() {
    if (rotate(rotateState)) {
        if (rotateState == 1) rotateState = 2;
        else rotateState--;
    }
    applyDropSpeed();
}