#ifndef __CELL_H__
#define __CELL_H__
#include "block.h"


class Cell{
    bool isFilled;
    char fillType;
    int x, y, width, height;
    Block* block;
    Cell* neighbourBottom = nullptr;
    Cell* neighbourRight = nullptr;
    Cell* neighbourLeft = nullptr;
    // Colour colour;
    // XWindow* window;

public:
    void setFill(char fill /*, Colour c */);
    // setCoords(int x, int y, int width, int height, XWindow* window);
    // void draw();
    bool cellFilled();
    bool bottomFilled();
    bool rightFilled();
    bool leftFilled();
    Block* getBlock();
    void addBlock(Block* block);

    // add operator<< later cause im lazy
};

#endif // __CELL_H__
