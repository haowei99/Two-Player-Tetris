#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include "cell.h"
#include "block.h"

class Board {
    std::vector<std::vector<Cell>> grid; //NEED TO FIX, ARRAY OF CELL POINTERS NOW
    int x;
    int y;
    Block* currBlock;
    Block *nextBlock;
    std::vector<Block *> loBlock;
    //Xwindow window;

    public:
    Board(int x, int y);
    void init();
    void reset();
    void clearRow(int row);
    void checkRows();
    Cell *cellAt(int x, int y);
    void set(int x, int y);
    void unset(int x, int y);
    Block * getBlock();
    Block * changeBlock(char type);
    void addBlock(Block *b);
    bool loBEmpty();
    void removeCells();

   // void setCurrBlock(Block *currBlock);
    friend std::ostream& operator<<(std::ostream& os, Board& board);



};

std::ostream& operator<<(std::ostream& os, Board& board);


#endif