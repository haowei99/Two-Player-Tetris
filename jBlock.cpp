#include "jBlock.h"
#include "board.h"

jBlock::jBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    blockType = 'J';
    numCells = 4; 
}

void jBlock::rotate(int state) {
    int x, y;
    if (state == 1) { //initial state is flat
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x + 1);
        cells[0]->set_Y(y - 1);
        board->set(x + 1, y - 1);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_Y(y - 2);
        board->set(x, y - 2);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x - 1);
        cells[2]->set_Y(y - 1);
        board->set(x - 1, y - 1);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x - 2);
        board->set(x - 2, y);
    } // end of if

    else if (state == 2){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x + 1);
        cells[0]->set_Y(y + 2);
        board->set(x + 1, y + 2);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x + 2);
        cells[1]->set_Y(y + 1);
        board->set(x + 2, y + 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_X(x + 1);
        board->set(x + 1, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_Y(y - 1);
        board->set(x, y - 1);
    }

    else if (state == 3){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_X(x - 2);
        board->set(x - 2, y);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x - 1);
        cells[1]->set_Y(y + 1);
        board->set(x - 1, y + 1);

        //block 3 is constant

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_X(x + 1);
        cells[3]->set_Y(y - 1);
        board->set(x  + 1, y - 1);
    }
    else{
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        board->unset(x, y);
        cells[0]->set_Y(y - 1);
        board->set(x , y - 1);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        board->unset(x, y);
        cells[1]->set_X(x - 1);
        board->set(x - 1, y);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        board->unset(x, y);
        cells[2]->set_Y(y + 1);
        board->set(x, y + 1);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        board->unset(x, y);
        cells[3]->set_Y(y + 2);
        cells[3]->set_X(x + 1);
        board->set(x + 1, y + 2);
    }
}

void jBlock::rotateClockwise() {
    int x0 = cells[0]->get_X();
    int x3 = cells[3]->get_X();
    if ( (rotateState == 2) && (x3 > 8)) return;
    if ( (rotateState == 4) && (x0 > 8)) return;
    rotate(rotateState);
    if (rotateState == 4) rotateState = 1;
    else rotateState++;
}

void jBlock::rotateCounterClockwise() {
    int cycle = 3;
    while(cycle){
        rotate(rotateState);
        if (rotateState == 4) rotateState = 1;
        else rotateState++;
        cycle--;
    }
}

/*
void jBlock::right() {
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


void jBlock::left() {
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

void jBlock::down() {
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


void jBlock::drop(){
}

bool jBlock::canMoveDown(){
    return true; //implement later
}
*/