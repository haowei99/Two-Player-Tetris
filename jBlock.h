#ifndef __jBLOCK_H__
#define __jBLOCK_H__
#include "block.h"

class jBlock: public Block{
    int numCells;

public:
    jBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    void right() override;
    void left() override;
    void down() override;
    void drop() override;
    bool canMoveDown() override;
    ~jBlock() = default;
};


#endif //__jBLOCK_H__
