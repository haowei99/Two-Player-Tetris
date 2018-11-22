#ifndef __iBLOCK_H__
#define __iBLOCK_H__
#include "block.h"

class iBlock: public Block{
    bool currShape[4][4];
    int rotateState = 1; //new state 1 - 4
    int numCells;
public:
    iBlock(int x, int y, int level, Board *board);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    void right() override;
    void left() override;
    void down() override;
    //void drop() override;
    //bool canMoveDown() override;
    void rotate(int state) override;
    ~iBlock() = default;
};


#endif //__iBLOCK_H__