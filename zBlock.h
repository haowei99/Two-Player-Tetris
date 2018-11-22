#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

class zBlock: public Block{
    bool currShape[3][3];
public:
    zBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    void right() override;
    void left() override;
    void down() override;
    void drop() override;
    bool canMoveDown() override;
    ~zBlock() = default;
};


#endif //__zBLOCK_H__