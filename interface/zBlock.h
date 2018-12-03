#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

class zBlock: public Block{
    bool rotate(int state);
public:
    zBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~zBlock() = default;
};


#endif //__ZBLOCK_H__
