#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class lBlock: public Block{
    void rotate(int state);
    bool canRotate(int state);
    bool canRotateCounter(int state);
public:
    lBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~lBlock() = default;
};


#endif //__LBLOCK_H__
