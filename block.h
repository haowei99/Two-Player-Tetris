#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include "cell.h"
#include "board.h"

const int max = 4;

class Block {
protected:
    int x, y; // coords of top left corner of block
    int level;
    Board* board;
    int dropSpeed;
    Cell* cells[max];
    int len;
    // XWindow* window;
    
public:
    Block(int x, int y, int level, Board* board);
    ~Block();
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterClockwise() = 0;
    virtual void right() = 0;
    virtual void left() = 0;
    virtual void down() = 0;
    virtual void drop() = 0;
    virtual bool canMoveDown() = 0;
    int getDropSpeed();
    void setDropSpeed(int speed);
    int getPoints();
    bool onBoard();
    void addCell(Cell* cell);
};

#endif // __BLOCK_H__
