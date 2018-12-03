#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class tBlock: public Block{
    void rotate(int state);
    bool canRotate(int state);
    bool canRotateCounter(int state);
public:
    tBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~tBlock() = default;
};


#endif //__TBLOCK_H__
