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

    grid = new_grid;
    }

void Board::reset(){
    for(auto it = grid.begin(); it != grid.end(); ++it){
        it->erase(it->begin(), it->end());
    }
    int size = loBlock.size();
    for (int i = 0; i < size; i++){
        delete loBlock.at(i);
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
/*
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

}*/

std::ostream& operator<<(std::ostream& out, Board& board){
    for (int i = 0; i < 22; i++){
        for (int j = 0; j < 11; j++){
            out << board.grid[i][j];
        }
        out <<endl;
    }
    //out << endl << "Next: " <<endl;
    //out << board.nextBlock << endl;
    return out;
}

vector<Cell> Board::getline(int i) {
    return grid[i];
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

    return row_cleared;
    
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
    // set next block
    set_next_block();
}

void Board::blind() {
    for (int i = 2; i < 12; i++){
        for (int j = 2; j < 9; j++){
            grid[i][j].blind();
        }
    }
}

void Board::unblind() {
    for (int i = 2; i < 12; i++){
        for (int j = 2; j < 9; j++){
            grid[i][j].unblind();
        }
    }
}

bool Board::canFitNew(char blockType){
    // check for if new block or replaced block can fit
    char type = blockType;

    if (type == 'I'){
        return grid[3][0].cellFilled() 
        && grid[3][1].cellFilled()
        && grid[3][2].cellFilled() 
        && grid[3][3].cellFilled();
    }
    else if (type == 'J'){
        return grid[3][0].cellFilled() 
        && grid[4][0].cellFilled()
        && grid[4][1].cellFilled() 
        && grid[4][2].cellFilled();
    }
    else if (type == 'L'){
        return grid[4][0].cellFilled() 
        && grid[4][1].cellFilled()
        && grid[4][2].cellFilled() 
        && grid[3][2].cellFilled();
    }
    else if (type == 'T'){
        return grid[4][1].cellFilled() 
        && grid[3][1].cellFilled()
        && grid[3][2].cellFilled() 
        && grid[3][0].cellFilled();
    }
    else if (type == 'O'){
        return grid[3][0].cellFilled()
        && grid[3][1].cellFilled() 
        && grid[4][0].cellFilled()
        && grid[4][1].cellFilled();
    }
    else if (type == 'S'){
        return grid[4][0].cellFilled()
        && grid[4][1].cellFilled()
        && grid[3][1].cellFilled()
        && grid[3][2].cellFilled();
    }
    else if (type == 'Z'){
        return grid[3][0].cellFilled()
        && grid[3][1].cellFilled()
        && grid[4][1].cellFilled()
        && grid[4][2].cellFilled();
    }


}

bool Board::canFit(char blockType){
    // check for if new block or replaced block can fit
    char type = blockType;

    int maxY = currBlock->cells[0]->get_Y();
    int minX = currBlock->cells[0]->get_X();
    for (int i = 0; i < 4; i++){
        int tmpY = currBlock->cells[i]->get_Y();
        if ( tmpY >= maxY){
            int tmpX = currBlock->cells[i]->get_X();
            if (tmpX <= minX){
                minX = tmpX;
                maxY = tmpY;
            }
        }
        currBlock->cells[i]->unsetCell();
    } 

    if (type == 'I'){
        return grid[maxY][minX].cellFilled() 
        && grid[maxY][minX + 1].cellFilled()
        && grid[maxY][minX + 2].cellFilled() 
        && grid[maxY][minX + 3].cellFilled();
    }
    else if (type == 'J'){
        return grid[maxY - 1][minX].cellFilled() 
        && grid[maxY][minX].cellFilled()
        && grid[maxY][minX + 1].cellFilled() 
        && grid[maxY][minX + 2].cellFilled();
    }
    else if (type == 'L'){
        return grid[maxY][minX].cellFilled() 
        && grid[maxY][minX + 1].cellFilled()
        && grid[maxY][minX + 2].cellFilled() 
        && grid[maxY - 1][minX + 2].cellFilled();
    }
    else if (type == 'T'){
        return grid[maxY][minX].cellFilled() 
        && grid[maxY - 1][minX].cellFilled()
        && grid[maxY - 1][minX - 1].cellFilled() 
        && grid[maxY - 1][minX + 1].cellFilled();
    }
    else if (type == 'O'){
        return grid[maxY][minX].cellFilled()
        && grid[maxY][minX + 1].cellFilled() 
        && grid[maxY - 1][minX].cellFilled()
        && grid[maxY - 1][minX + 1].cellFilled();
    }
    else if (type == 'S'){
        return grid[maxY][minX].cellFilled()
        && grid[maxY][minX + 1].cellFilled()
        && grid[maxY - 1][minX + 1].cellFilled()
        && grid[maxY - 1][minX + 2].cellFilled();
    }
    else if (type == 'Z'){
        return grid[maxY][minX].cellFilled()
        && grid[maxY - 1][minX].cellFilled()
        && grid[maxY - 1][minX - 1].cellFilled()
        && grid[maxY][minX + 1].cellFilled();
    }


}

bool Board::swapBlock(char blockType){
    Block *b;
    int currLvl =currBlock->level;

    char type = blockType;

    int maxY = currBlock->cells[0]->get_Y();
    int minX = currBlock->cells[0]->get_X();
    for (int i = 0; i < 4; i++){
        int tmpY = currBlock->cells[i]->get_Y();
        if ( tmpY >= maxY){
            int tmpX = currBlock->cells[i]->get_X();
            if (tmpX <= minX){
                minX = tmpX;
                maxY = tmpY;
            }
        }
        currBlock->cells[i]->unsetCell();
    } 

    if (canFit(blockType)){
        if (blockType == 'I'){
            b = new iBlock{0, 0, currLvl, this};
            b->addCell(&grid[maxY][minX]);
            b->addCell(&grid[maxY][minX + 1]);
            b->addCell(&grid[maxY][minX + 2]);
            b->addCell(&grid[maxY][minX + 3]);
        }
        else if (blockType == 'J'){
            b = new jBlock{0, 0, currLvl, this};
            b->addCell(&grid[maxY - 1][minX]);
            b->addCell(&grid[maxY][minX]);
            b->addCell(&grid[maxY][minX + 1]);
            b->addCell(&grid[maxY][minX + 2]);
        }
        else if (blockType == 'L'){
            b = new lBlock{0, 0, currLvl, this};
        }
        else if (blockType == 'T'){
            b = new tBlock{0, 0, currLvl, this};
        }
        else if (blockType == 'O'){
            b = new oBlock{0, 0, currLvl, this};
        }
        else if (blockType == 'S'){
            b = new sBlock{0, 0, currLvl, this};
        }
        else if (blockType == 'Z'){
            b = new zBlock{0, 0, currLvl, this};
        }
        delete currBlock;
        currBlock = b;
    }
}