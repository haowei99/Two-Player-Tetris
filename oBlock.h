#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class oBlock: public Block{
    bool currShape[2][2];
public:
    Block(int x, int y, int dropSpeed, int level, int len, Board *b, Cell **c);
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterClockwise() = 0;
    virtual void right() = 0;
    virtual void left() = 0;
    virtual void down() = 0;
    virtual void drop() = 0;
    virtual bool canMoveDown() = 0;
    int getDropSpeed();
    void setDropSpeed(int x);
    int getPoints();
    bool onBoard();
    void addCell(Cell *);

};


#endif //__OBLOCK_H__
