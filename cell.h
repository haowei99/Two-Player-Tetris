#ifndef __CELL_H__
#define __CELL_H__
#include "Block.h"


class Cell{
    bool isFilled = false;
    char fillType;
    int x;
    int y;
    int width;
    int height;
    //Block * block;
    //XWindow * window;

    public:
    Cell(bool isFilled, char fillType, int x, int y, int width, int height);
    //void setFill(char block, Colour c)
    //setCoords(int x, int y, int width, int height);
    // void draw();
    void addBlock(Block * block);
    bool cellFilled();

};

#endif //CELL_H
