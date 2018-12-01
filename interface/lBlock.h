#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class lBlock: public Block{
    int numCells;
    void rotate(int state);
    bool canRotate(int state);
    bool canRotateCounter(int state);
public:
    lBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    /*
    void right() override;
    void left() override;
    void down() override;
    void drop() override;
    bool canMoveDown() override;*/
    ~lBlock() = default;
};


#endif //__LBLOCK_H__
