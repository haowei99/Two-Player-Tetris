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
#include "starBlock.h"

using namespace::std;

Board::Board(int x, int y, Xwindow * window): x{x}, y{y}, win{window}{
}

Board::~Board() {
    reset();
} 

void Board::init() {
    vector<vector<Cell>> new_grid(22, vector<Cell>(11)); // with three reserved rows

    int width = 25;
    int height = 25;
    for (int i = 0; i < 22; i++){
        for (int j = 0; j < 11; j++){
            int x_coord = x + 25 * j;
            int y_coord = y + 25 * i;
            new_grid[i][j].setCoords(x_coord,y_coord,width,height, win);
            new_grid[i][j].set_X(j);
            new_grid[i][j].set_Y(i);
        }
    }

    for (int j = 0; j < 11; j++){
            new_grid[18][j].setCell('-');
    } //setting up  ------
    
    // Next:
    new_grid[19][0].setCell('N');
    new_grid[19][1].setCell('e');
    new_grid[19][2].setCell('x');
    new_grid[19][3].setCell('t');
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

Block* Board::getCurrBlock() {
    return currBlock;
}

Block* Board::initBlock(char type) {
    //char type = currBlock->getBlockType();
    //iBlock
    if (type == 'I'){
        this->set(0, 3);
        this->set(1, 3);
        this->set(2, 3);
        this->set(3, 3);
        currBlock->addCell(&grid[3][0]);
        currBlock->addCell(&grid[3][1]);
        currBlock->addCell(&grid[3][2]);
        currBlock->addCell(&grid[3][3]);
        return currBlock;
    }
    else if (type == 'J'){
        this->set(0, 3);
        this->set(0, 4);
        this->set(1, 4);
        this->set(2, 4);
        currBlock->addCell(&grid[3][0]);
        currBlock->addCell(&grid[4][0]);
        currBlock->addCell(&grid[4][1]);
        currBlock->addCell(&grid[4][2]);
        return currBlock;
    }
    else if (type == 'L'){
        this->set(0, 4);
        this->set(1, 4);
        this->set(2, 4);
        this->set(2, 3);
        currBlock->addCell(&grid[4][0]);
        currBlock->addCell(&grid[4][1]);
        currBlock->addCell(&grid[4][2]);
        currBlock->addCell(&grid[3][2]);
        return currBlock;
    }
    else if (type == 'O'){
        this->set(0, 3);
        this->set(1, 3);
        this->set(0, 4);
        this->set(1, 4);
        currBlock->addCell(&grid[3][0]);
        currBlock->addCell(&grid[3][1]);
        currBlock->addCell(&grid[4][0]);
        currBlock->addCell(&grid[4][1]);
        return currBlock;
    }
    else if (type == 'S'){
        this->set(0, 4);
        this->set(1, 4);
        this->set(1, 3);
        this->set(2, 3);
        currBlock->addCell(&grid[4][0]);
        currBlock->addCell(&grid[4][1]);
        currBlock->addCell(&grid[3][1]);
        currBlock->addCell(&grid[3][2]);
        return currBlock;
    }
    else if (type == 'Z'){
        this->set(0, 3);
        this->set(1, 3);
        this->set(1, 4);
        this->set(2, 4);
        currBlock->addCell(&grid[3][0]);
        currBlock->addCell(&grid[3][1]);
        currBlock->addCell(&grid[4][1]);
        currBlock->addCell(&grid[4][2]);
        return currBlock;
    }
    else {
        this->set(0, 3);
        this->set(1, 3);
        this->set(2, 3);
        this->set(1, 4);
        currBlock->addCell(&grid[3][0]);
        currBlock->addCell(&grid[3][1]);
        currBlock->addCell(&grid[3][2]);
        currBlock->addCell(&grid[4][1]);
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
            if (loBlock.at(i)->numCells == 0) {
                loBlock.at(i)->counted = true;
                int point = (loBlock.at(i)->level + 1) * (loBlock.at(i)->level + 1); //level + 1 squared
                s += point;
            } // if
        }
    }
    return s;
}

void Board::clearRow(int row) {
    // Unset first
    for (int i = 0; i < 11; i++) {
        grid[row][i].unsetCell();
    }
    //remove blocks helper
    removeCells();


    grid.erase(grid.begin() + row);
    grid.insert(grid.begin(), vector<Cell>(18));
    //re init x,y position
    int width = 25;
    int height = 25;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            grid[i][j].set_X(j);
            grid[i][j].set_Y(i);
            int x_coord = x + 25 * j;
            int y_coord = y + 25 * i;
            grid[i][j].setCoords(x_coord, y_coord, width, height, win);
        }
    }
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            if (grid[i][j].cellFilled()) {
                grid[i][j].draw();
            } else {
                grid[i][j].undraw();
            }
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
    //currBlock = nextBlock;
}

void Board::dropStar(int level) {
    //check if can be dropped
    if (cellAt(5, 3)->cellFilled()) return;

    int x = 5;
    int y = 3;

    while (true){
        if(!cellAt(x, y + 1)->cellFilled()){
            y++;
        }
        else{
            break;
        }
    }
    Block * star = new starBlock(x, y, level, this);
    //this->set(x, y);
    cellAt(x, y)->setCell('*');
    
    star->addCell(&grid[y][x]);
    star->addCell(nullptr);
    star->addCell(nullptr);
    star->addCell(nullptr); //to stay consistent for four cells
    
    addBlock(star);
}

void Board::set_blocks(Block *curr, Block *next) {
    currBlock = curr;
    nextBlock = next;
    // set next block
    set_next_block();
}

void Board::blind() {
    for (int i = 5; i < 15; i++){
        for (int j = 2; j < 9; j++){
            grid[i][j].blind();
        }
    }
}

void Board::unblind() {
    for (int i = 5; i < 15; i++){
        for (int j = 2; j < 9; j++){
            grid[i][j].unblind();
        }
    }
}

bool Board::canFitNew(char blockType){
    // check for if new block or replaced block can fit
    char type = blockType;

    if (type == 'I'){
        return !(grid[3][0].cellFilled() 
        || grid[3][1].cellFilled()
        || grid[3][2].cellFilled() 
        || grid[3][3].cellFilled());
    }
    else if (type == 'J'){
        return !(grid[3][0].cellFilled() 
        || grid[4][0].cellFilled()
        || grid[4][1].cellFilled() 
        || grid[4][2].cellFilled());
    }
    else if (type == 'L'){
        return !(grid[4][0].cellFilled() 
        || grid[4][1].cellFilled()
        || grid[4][2].cellFilled() 
        || grid[3][2].cellFilled());
    }
    else if (type == 'T'){
        return !(grid[4][1].cellFilled() 
        || grid[3][1].cellFilled()
        || grid[3][2].cellFilled() 
        || grid[3][0].cellFilled());
    }
    else if (type == 'O'){
        return !(grid[3][0].cellFilled()
        || grid[3][1].cellFilled() 
        || grid[4][0].cellFilled()
        || grid[4][1].cellFilled());
    }
    else if (type == 'S'){
        return !(grid[4][0].cellFilled()
        || grid[4][1].cellFilled()
        || grid[3][1].cellFilled()
        || grid[3][2].cellFilled());
    }
    else if (type == 'Z'){
        return !(grid[3][0].cellFilled()
        || grid[3][1].cellFilled()
        || grid[4][1].cellFilled()
        || grid[4][2].cellFilled());
    }
    return  false;

}
bool Board::canFit(char blockType){
    // check for if new block or replaced block can fit
    char type = blockType;

    int maxY = currBlock->cells[0]->get_Y();
    int minX = currBlock->cells[0]->get_X();
    for (int i = 0; i < 4; i++){
        int tmpY = currBlock->cells[i]->get_Y();
        int tmpX = currBlock->cells[i]->get_X();
        if (tmpX < minX) minX = tmpX;
        if (tmpY > maxY) maxY = tmpY;
        //currBlock->cells[i]->unsetCell();
    } 

    if (type == 'I'){
        if (minX + 3 >= 11) return false;
        return !(grid[maxY][minX].cellFilled() 
        || grid[maxY][minX + 1].cellFilled()
        || grid[maxY][minX + 2].cellFilled() 
        || grid[maxY][minX + 3].cellFilled());
    }
    else if (type == 'J'){
        if (minX + 2 >= 11) return false;
        if (maxY - 1 < 0) return false;
        return !(grid[maxY - 1][minX].cellFilled() 
        || grid[maxY][minX].cellFilled()
        || grid[maxY][minX + 1].cellFilled() 
        || grid[maxY][minX + 2].cellFilled());
    }
    else if (type == 'L'){
        if (minX + 2 >= 11) return false;
        if (maxY - 1 < 0) return false;
        return !(grid[maxY][minX].cellFilled() 
        || grid[maxY][minX + 1].cellFilled()
        || grid[maxY][minX + 2].cellFilled() 
        || grid[maxY - 1][minX + 2].cellFilled());
    }
    else if (type == 'T'){
        if (minX + 1 >= 11) return false;
        //f (minX < 0) return false;
        if (maxY - 1 < 0) return false;
        return !(grid[maxY][minX].cellFilled() 
        || grid[maxY - 1][minX].cellFilled()
        || grid[maxY - 1][minX - 1].cellFilled() 
        || grid[maxY - 1][minX + 1].cellFilled());
    }
    else if (type == 'O'){
        if (minX + 1 >= 11) return false;
        if (maxY - 1 < 0) return false;
        return !(grid[maxY][minX].cellFilled()
        || grid[maxY][minX + 1].cellFilled() 
        || grid[maxY - 1][minX].cellFilled()
        || grid[maxY - 1][minX + 1].cellFilled());
    }
    else if (type == 'S'){
        if (minX + 2 >= 11) return false;
        if (maxY - 1 < 0) return false;
        return !(grid[maxY][minX].cellFilled()
        || grid[maxY][minX + 1].cellFilled()
        || grid[maxY - 1][minX + 1].cellFilled()
        || grid[maxY - 1][minX + 2].cellFilled());
    }
    else if (type == 'Z'){
        if (minX + 1 >= 11) return false;
       // if (minX - 1 < 0) return false;
        if (maxY - 1 < 0) return false;
        return !(grid[maxY][minX + 1].cellFilled()
        || grid[maxY - 1][minX + 1].cellFilled()
        || grid[maxY - 1][minX].cellFilled()
        || grid[maxY][minX + 2].cellFilled());
    }

    return  false;


}

bool Board::swapBlock(char blockType){

    int maxY = currBlock->cells[0]->get_Y();
    int minX = currBlock->cells[0]->get_X();
    for (int i = 0; i < 4; i++){
        int tmpY = currBlock->cells[i]->get_Y();
        int tmpX = currBlock->cells[i]->get_X();
        if (tmpX < minX) minX = tmpX;
        if (tmpY > maxY) maxY = tmpY;
        currBlock->cells[i]->unsetCell();
    }
    //unset before asking unset

    if (canFit(blockType)){
        Block *b;
        int currLvl =currBlock->level;

        //char type = blockType;

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
            b->addCell(&grid[maxY][minX]);
            b->addCell(&grid[maxY][minX + 1]);
            b->addCell(&grid[maxY][minX + 2]);
            b->addCell(&grid[maxY - 1][minX + 2]);
        }
        else if (blockType == 'T'){
            b = new tBlock{0, 0, currLvl, this};
            b->addCell(&grid[maxY - 1][minX]);
            b->addCell(&grid[maxY - 1][minX + 1]);
            b->addCell(&grid[maxY - 1][minX + 2]);
            b->addCell(&grid[maxY][minX + 1]);
        }
        else if (blockType == 'O'){
            b = new oBlock{0, 0, currLvl, this};
            b->addCell(&grid[maxY][minX]);
            b->addCell(&grid[maxY][minX + 1]);
            b->addCell(&grid[maxY - 1][minX]);
            b->addCell(&grid[maxY - 1][minX + 1]);
        }
        else if (blockType == 'S'){
            b = new sBlock{0, 0, currLvl, this};
            b->addCell(&grid[maxY][minX]);
            b->addCell(&grid[maxY][minX + 1]);
            b->addCell(&grid[maxY - 1][minX + 1]);
            b->addCell(&grid[maxY - 1][minX + 2]);
        }
        else { //(blockType == 'Z')
            b = new zBlock{0, 0, currLvl, this};
            b->addCell(&grid[maxY - 1][minX]);
            b->addCell(&grid[maxY - 1][minX + 1]);
            b->addCell(&grid[maxY][minX + 1]);
            b->addCell(&grid[maxY][minX + 2]);
        }
        for (int i = 0; i < 4; i++){
            b->cells[i]->setCell(b->getBlockType());
        }
        b->dropSpeed = currBlock->dropSpeed;
        b->level = currBlock->level;
        delete currBlock;
        currBlock = b;
        return true;
    }
    else{
        for (int i = 0; i < 4; i++){
            int tmpY = currBlock->cells[i]->get_Y();
            if ( tmpY >= maxY){
                int tmpX = currBlock->cells[i]->get_X();
                if (tmpX <= minX){
                    minX = tmpX;
                    maxY = tmpY;
                }
            }
            char type = currBlock->getBlockType();
            currBlock->cells[i]->setCell(type);
        }
    }
    return  false;
}