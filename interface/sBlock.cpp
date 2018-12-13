#include "sBlock.h"
#include "board.h"


sBlock::sBlock(int level, Board *board): Block{level, board} {
    numCells = 4;
    blockType = 'S';
}


bool sBlock::rotate(int state) {
    int x, y;
    if (state == 1) { // initial state is flat
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); 
        bool cell1 = board->cellAt(x, y - 2)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 
        bool cell4 = board->cellAt(x - 2, y)->cellFilled();

        if(cell1 || cell4) return false;

        // block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y - 2);
        cells[0] = board->cellAt(x, y - 2);

        // block 2/3 are pivot points

        // block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 2, y);
        cells[3] = board->cellAt(x - 2, y);

        return true;
    }
    else{
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); 
        bool cell1 = board->cellAt(x, y + 2)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 
        bool cell4 = board->cellAt(x + 2, y)->cellFilled();

        if(cell1 || cell4) return false;

        // block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y + 2);
        cells[0] = board->cellAt(x, y + 2);

        // block 2/3 are pivot points

        // block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); 

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 2, y);
        cells[3] = board->cellAt(x + 2, y);

        return true;
    }
}


void sBlock::rotateClockwise() {
    int x3 = cells[3]->get_X();
    if ( (rotateState == 2) && (x3 > 8)) return;

    if (rotate(rotateState)) {
        if (rotateState == 2) rotateState = 1;
        else rotateState = 2;
    }
    applyDropSpeed();
}


void sBlock::rotateCounterClockwise() {
    int x3 = cells[3]->get_X();
    if ( (rotateState == 2) && (x3 > 8)) return;

    if (rotate(rotateState)) {
        if (rotateState == 2) rotateState = 1;
        else rotateState = 2;
    }
    applyDropSpeed();
}

