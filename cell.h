#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>


class Cell {
    bool isFilled, isBlind;
    char fillType;
    int x, y, width, height;
    // Colour colour;
    // XWindow* window;

public:
    Cell();
    ~Cell();
    //void setFill(char fill /*, Colour c */);
    // setCoords(int x, int y, int width, int height, XWindow* window);
    // void draw();
    bool cellFilled();
//    void addBlock(Block* block); should be deleted

    void setCell(char blockType);
    void unsetCell();
    int get_X();
    int get_Y();
    void set_X(int xCoor);
    void set_Y(int yCoor);


    friend std::ostream& operator<<(std::ostream& os, Cell& cell);
};

std::ostream& operator<<(std::ostream& os, Cell& cell);

#endif // __CELL_H__
