#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

class sBlock: public Block{
    bool rotate(int state);
public:
    sBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~sBlock() = default;
};


#endif //__SBLOCK_H__
