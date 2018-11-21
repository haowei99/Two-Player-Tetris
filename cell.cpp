#include <iostream>
#include "cell.h"
#include "block.h"



Cell::Cell() 
    : isFilled{false}, fillType{'-'}, x{0}, y{0}, width{0}, height{0} {} // constructor


Cell::~Cell() {} // destructor


void Cell::setFill(char fill /*, Colour c */) {
    fillType = fill;
} // setFill


// setCoords(int x, int y, int width, int height, XWindow* window);
// void draw();


bool Cell::cellFilled() {
    return isFilled;
} // cellFilled

void Cell::setCell(){
    isFilled = true;
}

void Cell::unsetCell(){
    isFilled = false;
}

std::ostream& operator<<(std::ostream& out, Cell& cell) {
    out << cell.fillType;
    
    return out;
} // operator<<