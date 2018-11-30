#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>

class Cell {
    char fill;
    bool cellFilled, cellBlinded;
    // int x, y, width, height;
public:
    Cell();
    ~Cell();
    void blind();
    void unblind();
    void setFill(char fillType);
    bool isFilled();
    // void draw(), calld by setFill
    // need a reset function? Cell is no longer exclusive to board

    friend std::ostream& operator<<(std::ostream& out, Cell& c);
};

std::ostream& operator<<(std::ostream& out, Cell& c);

#endif /** __CELL_H__ **/