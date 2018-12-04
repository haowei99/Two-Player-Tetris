#ifndef __jBLOCK_H__
#define __jBLOCK_H__
#include "block.h"

class jBlock: public Block{
    void rotate(int state);
    bool canRotate(int state);
    bool canRotateCounter(int state);

public:
    jBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~jBlock() = default;
};


#endif // __jBLOCK_H__
