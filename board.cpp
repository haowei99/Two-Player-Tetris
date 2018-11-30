#include <vector>
#include <iostream>
#include "board.h"
#include "iBlock.h"
#include "jBlock.h"
#include "lBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include "zBlock.h"
#include "tBlock.h"

using namespace::std;

Board::Board(int x, int y): x{x}, y{y}{
}

void Board::init() {
    vector<vector<Cell>> new_grid(18, vector<Cell>(11)); // with three reserved rows
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 11; j++){
            new_grid[i][j].set_X(j);
            new_grid[i][j].set_Y(i);
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
        this->set(0, 3);
        this->set(1, 3);
        this->set(2, 3);
        this->set(3, 3);
        block->addCell(&grid[3][0]);
        block->addCell(&grid[3][1]);
        block->addCell(&grid[3][2]);
        block->addCell(&grid[3][3]);

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
        block->addCell(&grid[3][0]);
        block->addCell(&grid[4][0]);
        block->addCell(&grid[4][1]);
        block->addCell(&grid[4][2]);

        currBlock = block;
        return currBlock;
    }
    else if (type == 'l'){
        Block * block = new lBlock(0,0,0, this);
        //cout << "addr block" << block << endl;
        currBlock = block;
        this->set(0, 4);
        this->set(1, 4);
        this->set(2, 4);
        this->set(2, 3);
        block->addCell(&grid[4][0]);
        block->addCell(&grid[4][1]);
        block->addCell(&grid[4][2]);
        block->addCell(&grid[3][2]);

        currBlock = block;
        return currBlock;
    }
    else if (type == 'o'){
        Block * block = new oBlock(0,0,0, this);
        currBlock = block;
        this->set(0, 3);
        this->set(1, 3);
        this->set(0, 4);
        this->set(1, 4);
        block->addCell(&grid[3][0]);
        block->addCell(&grid[3][1]);
        block->addCell(&grid[4][0]);
        block->addCell(&grid[4][1]);

        currBlock = block;
        return currBlock;
    }
    else if (type == 's'){
        Block * block = new sBlock(0,0,0, this);
        currBlock = block;
        this->set(0, 4);
        this->set(1, 4);
        this->set(1, 3);
        this->set(2, 3);
        block->addCell(&grid[4][0]);
        block->addCell(&grid[4][1]);
        block->addCell(&grid[3][1]);
        block->addCell(&grid[3][2]);

        currBlock = block;
        return currBlock;
    }
    else if (type == 'z'){
        Block * block = new zBlock(0,0,0, this);
        currBlock = block;
        this->set(0, 3);
        this->set(1, 3);
        this->set(1, 4);
        this->set(2, 4);
        block->addCell(&grid[3][0]);
        block->addCell(&grid[3][1]);
        block->addCell(&grid[4][1]);
        block->addCell(&grid[4][2]);

        currBlock = block;
        return currBlock;
    }
    else if (type == 't'){
        Block * block = new tBlock(0,0,0, this);
        currBlock = block;
        this->set(0, 3);
        this->set(1, 3);
        this->set(2, 3);
        this->set(1, 4);
        block->addCell(&grid[3][0]);
        block->addCell(&grid[3][1]);
        block->addCell(&grid[3][2]);
        block->addCell(&grid[4][1]);

        currBlock = block;
        return currBlock;
    }
}

void Board::addBlock(Block *b){
    loBlock.emplace_back(b);
}

void Board::removeCells(){
    int size = loBlock.size();
    for (int i = 0; i < size; i++){
        Block *b = loBlock.at(i);
        for (int j = 0; j < 4; j++){
            if (b->cells[j]->cellFilled() == false){
                b->cells[j] = nullptr;
                --(b->numCells);
            }
        }
    }   

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

void Board::checkRows() {
    for (int i = 0; i < 18; i++){
        bool clear = true;
        for (int j = 0; j < 11; j++){
            if(!grid[i][j].cellFilled()) clear = false;
        }
        if(clear) clearRow(i);
    }
}
void Board::clearRow(int row) {
    // Unset first
    for(int i = 0; i < 11; i++){
        grid[row][i].unsetCell();
    }
    //remove blocks helper
    removeCells();
    grid.erase(grid.begin() + row);
    grid.insert(grid.begin(), vector<Cell>(18));
    //re init x,y position
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 11; j++){
            grid[i][j].set_X(j);
            grid[i][j].set_Y(i);
        }
    }
}