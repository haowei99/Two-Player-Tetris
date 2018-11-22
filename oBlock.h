#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class oBlock: public Block{
    bool currShape[2][2];
    int numCells;
public:
    oBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    void right() override;
    void left() override;
    void down() override;
    void drop() override;
    bool canMoveDown() override;
    ~oBlock() = default;
};


#endif //__OBLOCK_H__
