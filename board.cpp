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
    vector<vector<Cell>> new_grid(22, vector<Cell>(11)); // with three reserved rows
    for (int i = 0; i < 22; i++){
        for (int j = 0; j < 11; j++){
            new_grid[i][j].set_X(j);
            new_grid[i][j].set_Y(i);
        }
    }

    for (int j = 0; j < 11; j++){
            new_grid[18][j].setCell('-');
    } //setting up  ------

    // Next:
    new_grid[19][0].setCell('N');
    new_grid[19][1].setCell('E');
    new_grid[19][2].setCell('X');
    new_grid[19][3].setCell('T');
    new_grid[19][4].setCell(':');

    // set next block
    set_next_block();


    grid = new_grid;
}

void Board::reset(){
    for(auto it = grid.begin(); it != grid.end(); ++it){
        it->erase(it->begin(), it->end());
    }
    loBlock.clear();
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
    nextBlock = currBlock;

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
        for (int j = 0; j < 4; j++) {
            if (b->cells[j]) { // if cell exist
                if (!b->cells[j]->cellFilled()) {
                    b->cells[j] = nullptr;
                    --(b->numCells);
                }
            }
        }
    }   

}

std::ostream& operator<<(std::ostream& out, Board& board){
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 11; j++){
            out << board.grid[i][j];
        }
        out <<endl;
    }
    //out << endl << "Next: " <<endl;
    //out << board.nextBlock << endl;
    return out;
}

//test if block is properly added
bool Board::loBEmpty(){
    return loBlock.empty();
}

int Board::checkRows() { // note give score
    int row_cleared = 0;
    for (int i = 0; i < 18; i++) {
        bool clear = true;
        for (int j = 0; j < 11; j++) {
            if (!grid[i][j].cellFilled()) {
                clear = false;
                break;
            }
        }
        if (clear) {
            clearRow(i);
            row_cleared++;
        }
    }
    if (row_cleared == 0) return 0;

    //else
    int level = currBlock->level;
    int row_cleared_score = (level + row_cleared) * (level + row_cleared);
    int block_score = count_score();
    return (block_score + row_cleared_score);
}

int Board::count_score() {
    int s = 0;
    int size = loBlock.size();
    for (int i = 0; i < size; i++){
        if(!loBlock.at(i)->counted){
            loBlock.at(i)->counted = true;
            int point = (loBlock.at(i)->level + 1) * (loBlock.at(i)->level + 1); //level + 1 squared
            s += point;
        }
    }
    return s;
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

void Board::set_next_block() {
    for (int i = 20; i < 22; i++){
        for (int j = 0; j < 11; j++){
            grid[i][j].unsetCell();
        }
    } //clear cells first
    char type = nextBlock->getBlockType();

    if (type == 'I'){
        grid[20][0].setCell(type);
        grid[20][1].setCell(type);
        grid[20][2].setCell(type);
        grid[20][3].setCell(type);
    }
    else if (type == 'J'){
        grid[20][0].setCell(type);
        grid[21][0].setCell(type);
        grid[21][1].setCell(type);
        grid[21][2].setCell(type);
    }
    else if (type == 'L'){
        grid[20][2].setCell(type);
        grid[21][0].setCell(type);
        grid[21][1].setCell(type);
        grid[21][2].setCell(type);
    }
    else if (type == 'T'){
        grid[20][0].setCell(type);
        grid[20][1].setCell(type);
        grid[20][2].setCell(type);
        grid[21][1].setCell(type);
    }
    else if (type == 'O'){
        grid[20][0].setCell(type);
        grid[20][1].setCell(type);
        grid[21][0].setCell(type);
        grid[21][1].setCell(type);
    }
    else if (type == 'S'){
        grid[21][0].setCell(type);
        grid[21][1].setCell(type);
        grid[20][1].setCell(type);
        grid[20][2].setCell(type);
    }
    else if (type == 'Z'){
        grid[20][0].setCell(type);
        grid[20][1].setCell(type);
        grid[21][1].setCell(type);
        grid[21][2].setCell(type);
    }
}

void Board::set_blocks(Block *curr, Block *next) {
    currBlock = curr;
    nextBlock = next;
}