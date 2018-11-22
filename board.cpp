#include "board.h"
#include <vector>
#include "oBlock.h"

using namespace::std;

Board::Board(int x, int y): x{x}, y{y}{
}

void Board::init() {
    vector<vector<Cell>> new_grid(18, vector<Cell>(11)); // with three reserved rows
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

Block* Board::changeBlock() {
    Block * block = new oBlock(0,0,0, this);
    Cell c = Cell();
    currBlock = block;
    currBlock->addCell(&grid[0][0]);
    currBlock->addCell(&grid[0][1]);
    currBlock->addCell(&grid[1][0]);
    currBlock->addCell(&grid[1][1]);
    this->set(0, 0);
    this->set(1, 0);
    this->set(0, 1);
    this->set(1, 1);
    return block;
   // currBlock = new oBlock(0,0,0,this);
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
