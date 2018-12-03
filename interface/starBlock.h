#ifndef __STARBLOCK_H__
#define __STARBLOCK_H__
#include "block.h"

class starBlock: public Block{
    void rotate(int state);
public:
    starBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~starBlock() = default;
};

#endif //__STARBLOCK_H__
