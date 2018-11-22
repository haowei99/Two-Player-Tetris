#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "block.h"


class Cell {
    bool isFilled, isBlind;
    char fillType;
    int x, y, width, height;
    Block* block = nullptr;
    Cell* neighbourBottom = nullptr;
    Cell* neighbourRight = nullptr;
    Cell* neighbourLeft = nullptr;
    // Colour colour;
    // XWindow* window;

public:
    Cell();
    ~Cell();
    void setFill(char fill /*, Colour c */);
    void toggleBlind();
    void untoggleBlind();
    // setCoords(int x, int y, int width, int height, XWindow* window);
    // void draw();
    bool cellFilled();
    bool bottomFilled();
    bool rightFilled();
    bool leftFilled();
    Block* getBlock();
    void addBlock(Block* block);

    friend std::ostream& operator<<(std::ostream& os, Cell& cell);
};

std::ostream& operator<<(std::ostream& os, Cell& cell);

#endif // __CELL_H__
