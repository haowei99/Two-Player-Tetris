#ifndef CELL_H
#define CELL_H

class Cell{
    bool isFilled = false;
    char fillType;
    int x;
    int y;
    int width;
    int height;
    Block * block;
    XWindow * window;

    public:
    //void setFill(char block, Colour c)
    //setCoords(int x, int y, int width, int height);
};

#endif //CELL_H
