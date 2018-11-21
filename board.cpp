#include "board.h"
#include <vector>

using namespace::std;

Board::Board(int x, int y): x{x}, y{y}{
}

void Board::init() {
    vector<vector<Cell> > new_grid(15, vector<Cell>(11));
    grid = new_grid;
}