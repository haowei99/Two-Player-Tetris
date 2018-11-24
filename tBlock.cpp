#include "tBlock.h"
#include "board.h"

using namespace::std;

tBlock::tBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'T';
}

void tBlock::rotate(int state) {
    int x, y;
    if (state == 1) { //initial state is flat
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x + 1);
        cells[0]->set_Y(y - 1);
        board->set(x + 1, y - 1);

        //block 2 CONSTANT

        // Block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x - 1);
        cells[3]->set_Y(y - 1);
        board->set(x - 1, y - 1);

        // Block 3 ORDER IS IMPORTANT
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x - 1);
        cells[2]->set_Y(y + 1);
        board->set(x - 1, y + 1);

    }
    else if (state == 2){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x + 1);
        cells[0]->set_Y(y + 2);
        board->set(x + 1, y + 2);


        // Block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x - 1);
        board->set(x - 1, y);


        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_Y(y + 1);
        board->set(x, y + 1);


        // Block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x + 1);
        board->set(x + 1, y);
    }
    else if (state == 3){

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block
        board->unset(x, y);
        cells[1]->set_X(x - 1);
        cells[1]->set_Y(y - 1);
        board->set(x - 1, y - 1);

        // Block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block
        board->unset(x, y);
        cells[2]->set_Y(y - 2);
        board->set(x , y - 2);

        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x - 2);
        board->set(x - 2, y);


        //block 4 constant
    }
    else if (state == 4){
        // Block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 2);
        cells[2]->set_Y(y + 1);
        board->set(x + 2, y + 1);

        // Block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_Y(y + 1);
        board->set(x, y + 1);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x + 1);
        board->set(x + 1, y);

        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_Y(y - 1);
        board->set(x , y - 1);
    }
}

void tBlock::rotateClockwise() {
    rotate(rotateState);
    if (rotateState == 4) rotateState = 1;
    else rotateState++;
}

void tBlock::rotateCounterClockwise() {
    int cycle = 3;
    while(cycle){
        rotate(rotateState);
        if (rotateState == 4) rotateState = 1;
        else rotateState++;
        cycle--;
    }
}

void tBlock::right() {
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


void tBlock::left() {
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

void tBlock::down() {
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

void tBlock::drop() {} //need to implement
bool tBlock::canMoveDown() {
    return true; // need implement
}