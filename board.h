#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include "cell.h"
#include "block.h"


class Board {
    std::vector<std::vector<Cell>> grid;
    int x;
    int y;
    Block* currblock;
    //Xwindow window;

    public:
    void init();
    void tick();
    void reset();
    bool isRowFilled(int row);
    void clearRow(int row);
    Cell *cellAt(int x, int y);

};


#endif