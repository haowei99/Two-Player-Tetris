#ifndef __iBLOCK_H__
#define __iBLOCK_H__
#include "block.h"

class iBlock: public Block{
    bool rotate(int state);
public:
    iBlock(int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    ~iBlock() = default;
};


#endif //__iBLOCK_H__
