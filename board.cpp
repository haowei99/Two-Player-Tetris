#include "board.h"
#include <vector>

using namespace::std;

Board::Board(int x, int y): x{x}, y{y}{
}

void Board::init() {
    vector<vector<Cell>> new_grid(18, vector<Cell>(11)); // with three reserved rows
    grid = new_grid;
}

void Board::reset(){
    for (auto it = grid.begin(); it != grid.end(); ++it){
        it->erase(it->begin(), it->end());
    }
    grid.erase(grid.begin(), grid.end());
}

Cell *Board::cellAt(int x, int y){
    return &grid[y][x];
}

void Board::set(int x, int y){
    cellAt(x, y)->setCell();
}

void Board::unset(int x, int y){
    cellAt(x, y)->unsetCell();
}