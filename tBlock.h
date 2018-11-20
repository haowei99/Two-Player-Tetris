#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class tBlock: public Block{
    bool currShape[3][3];
public:
    tBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    void right() override;
    void left() override;
    void down() override;
    void drop() override;
    bool canMoveDown() override;
    ~tBlock() = default;
};


#endif //__TBLOCK_H__
