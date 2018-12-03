#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class oBlock: public Block{
public:
    oBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~oBlock() = default;
};


#endif //__OBLOCK_H__
