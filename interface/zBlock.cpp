#include "zBlock.h"
#include "board.h"


zBlock::zBlock(int level, Board *board): Block{level, board} {
    numCells = 4;
    blockType = 'Z';
}


bool zBlock::rotate(int state) {
    int x, y;
    if (state == 1) { // initial state is flat
        // check collision
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); 
        bool cell3 = board->cellAt(x - 1, y)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 
        bool cell4 = board->cellAt(x - 1, y - 2)->cellFilled();

        if(cell3 || cell4) return false;

        // rotate block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y);
        cells[2] = board->cellAt(x - 1, y);

        // rotate block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y - 2);
        cells[3] = board->cellAt(x - 1, y - 2);

    }
    else{
        // collision check
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); 
        bool cell3 = board->cellAt(x + 1, y)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 
        bool cell4 = board->cellAt(x + 1, y + 2)->cellFilled();

        if(cell3 || cell4) return false;

        // rotate block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y);
        cells[2] = board->cellAt(x + 1, y);

        // rotate block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y + 2);
        cells[3] = board->cellAt(x + 1, y + 2);

        // rotate block 1 pivot point, does not change
    }

    return true;
}


void zBlock::rotateClockwise() {
    if (rotate(rotateState)) {
        if (rotateState == 2) rotateState = 1;
        else rotateState = 2;
    }
    applyDropSpeed();
}


void zBlock::rotateCounterClockwise() {
    if (rotate(rotateState)) {
        if (rotateState == 2) rotateState = 1;
        else rotateState = 2;
    }
    applyDropSpeed();
}