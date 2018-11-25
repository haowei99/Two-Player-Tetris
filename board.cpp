#include "board.h"
#include <vector>
#include "iBlock.h"
#include "jBlock.h"
/*
#include "oBlock.h"
#include "sBlock.h"
#include "zBlock.h"
#include "lBlock.h"
#include "tBlock.h"*/

using namespace::std;

Board::Board(int x, int y): x{x}, y{y}{
}

void Board::init() {
    vector<vector<Cell>> new_grid(18, vector<Cell>(11)); // with three reserved rows
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 11; j++){
            new_grid[i][j].set_X(i);
            new_grid[i][j].set_Y(j);
        }
    }
    grid = new_grid;
}

void Board::reset(){
    for(auto it = grid.begin(); it != grid.end(); ++it){
        it->erase(it->begin(), it->end());
    }
    grid.erase(grid.begin(), grid.end());
}

Cell *Board::cellAt(int x, int y){
    return &grid[y][x];
}

void Board::set(int x, int y){
    cellAt(x, y)->setCell(currBlock->getBlockType());
}

void Board::unset(int x, int y){
    cellAt(x, y)->unsetCell();
}

Block* Board::getBlock() {
    return currBlock;
}

Block* Board::changeBlock(char type) {
    /* t block
    Block * block = new tBlock(0,0,0, this);
    currBlock = block;
    this->set(0, 1);
    this->set(1, 1);
    this->set(2, 1);
    this->set(1 , 2);
    block->addCell(&grid[0][1]);
    block->addCell(&grid[1][1]);
    block->addCell(&grid[2][1]);
    block->addCell(&grid[1][2]);

    currBlock = block;
    return currBlock;
    */

    //iBlock
    if (type == 'i'){
        Block * block = new iBlock(0,0,0, this);
        //cout << "addr block" << block << endl;
        currBlock = block;
        this->set(0, 0);
        this->set(1, 0);
        this->set(2, 0);
        this->set(3, 0);
        block->addCell(&grid[0][0]);
        block->addCell(&grid[1][0]);
        block->addCell(&grid[2][0]);
        block->addCell(&grid[3][0]);

        currBlock = block;
        return currBlock;
    }
    else if (type == 'j'){
        Block * block = new jBlock(0,0,0, this);
        //cout << "addr block" << block << endl;
        currBlock = block;
        this->set(0, 3);
        this->set(0, 4);
        this->set(1, 4);
        this->set(2, 4);
        block->addCell(&grid[0][3]);
        block->addCell(&grid[0][4]);
        block->addCell(&grid[1][4]);
        block->addCell(&grid[2][4]);

        currBlock = block;
        return currBlock;
    }


    // Block
    /*
    Block * block = new oBlock(1,1,0, this);
    currBlock = block;
    this->set(0, 0);
    this->set(1, 0);
    this->set(0, 1);
    this->set(1, 1);
    cout << grid[0][1].get_X() << " Y:"<< grid[0][1].get_Y() <<endl;
    Cell a = grid[0][1];
    cout << a;
    block->addCell(&grid[0][0]);
    block->addCell(&grid[0][1]);
    block->addCell(&grid[1][0]);
    block->addCell(&grid[1][1]);

    currBlock = block;
    return currBlock;
   // currBlock = new oBlock(0,0,0,this); */
}

void Board::addBlock(Block *b){
    loBlock.emplace_back(b);
}

std::ostream& operator<<(std::ostream& out, Board& board){
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 11; j++){
            out << board.grid[i][j];
        }
        out << endl;
    }
    return out;
}

//test if block is properly added
bool Board::loBEmpty(){
    return loBlock.empty();
}
