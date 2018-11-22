#include "iBlock.h"

iBlock::iBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    currShape[0][0] = true;
    currShape[0][1] = true;
    currShape[0][2] = true;
    currShape[0][3] = true;
}

void iBlock::rotate(int state) {
    if (rotateState == 1) {
        //block 1
        int x = cells[0]->get_X();
        int y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 3, y + 3, 'I');


        //block 2
        int x = cells[1]->get_X();
        int y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 2, y + 2, 'I');

        //block 3
        int x = cells[2]->get_X();
        int y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 1, y + 1, 'I');

        //block 4 pivot point, does not change
    }
    else{
        //block 1
        int x = cells[0]->get_X();
        int y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 3, y - 3, 'I');


        //block 2
        int x = cells[1]->get_X();
        int y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 2, y - 2, 'I');

        //block 3
        int x = cells[2]->get_X();
        int y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 1, y - 1, 'I');

        //block 4 pivot point, does not change
    }
}
void iBlock::rotateClockwise() {
     rotate(rotateState);
     //still need top left to check and move the locaiton???

    //Change state at the end
    if (rotateState == 2) rotateState = 1;
    else rotateState++;
}

void iBlock::rotateCounterClockwise() {
    int s;
    if (rotateState == 2) s = 1;
    else s++; //opposite rotations

    rotate(s);
    if (rotateState == 1) rotateState = 2;
    else rotateState--;
}

void iBlock::right() {
    for (int i =0; i < 4; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x + 1, y, 'I');
    }
}


void iBlock::left() {
    for (int i =0; i < 4; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x - 1, y, 'I');
    }
}

void iBlock::down() {
    for (int i =0; i < 4; i++){
        int x = cells[i]->get_X();
        int y = cells[i]->get_Y(); //pos of block

        board->unset(x, y);
        board->set(x, y + 1, 'I');
    }
}