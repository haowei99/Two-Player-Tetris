#include "lBlock.h"
#include "board.h"

using namespace::std;

lBlock::lBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'L';
}

void lBlock::rotate(int state) {
    int x, y;
    if (state == 1) { //initial state is flat
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_Y(y - 2);
        board->set(x, y - 2);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x - 1);
        cells[1]->set_Y(y - 1);
        board->set(x - 1, y - 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x - 2);
        board->set(x - 2, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x - 1);
        cells[3]->set_Y(y + 1);
        board->set(x - 1, y + 1);


    }
    else if (state == 2){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x + 2);
        cells[0]->set_Y(y + 1);
        board->set(x + 2, y + 1);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x + 1);
        cells[1]->set_Y(y + 1);
        board->set(x + 1, y + 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_Y(y - 1);
        board->set(x, y - 1);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x - 1);
        board->set(x - 1, y);

    }
    else if (state == 3){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x + 1);
        cells[0]->set_Y(y - 1);
        board->set(x + 1, y - 1);

        //block 2 pivot

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 1);
        cells[2]->set_Y(y - 1);
        board->set(x + 1, y - 1);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_Y(y - 2);
        board->set(x, y - 2);
    }
    else if (state == 4){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x - 1);
        board->set(x - 1, y);

        //block 2 pivot
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_Y(y + 1);
        board->set(x, y + 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 1);
        cells[2]->set_Y(y + 2);
        board->set(x + 1, y + 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x + 2);
        cells[3]->set_Y(y + 1);
        board->set(x + 2, y + 1);
    }
}

void lBlock::rotateClockwise() {
    rotate(rotateState);
    if (rotateState == 4) rotateState = 1;
    else rotateState++;
}

void lBlock::rotateCounterClockwise() {
    int loop = 3;
    while (loop) {
        rotate(rotateState);
        if (rotateState == 4) rotateState = 1;
        else rotateState++;
        loop--;
    }
}


void lBlock::right() {
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


void lBlock::left() {
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

void lBlock::down() {
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

void lBlock::drop() {} //need to implement
bool lBlock::canMoveDown() {
    return true; // need implement
}