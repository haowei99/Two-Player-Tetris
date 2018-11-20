#ifndef BLOCK_H
#define BLOCK_H
#include <string>
#include "cell.h"
#include "board.h"


class Block{
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

    protected:
    int x; // x-cord
    int y; // y-cord
    int dropSpeed;
    int level;
    int len;
    Board * board;
    //XWindow * window;
    Cell *cells[];
};

#endif //BLOCK_H
