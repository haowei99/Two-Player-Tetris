#include <iostream>
#include "cell.h"
#include "block.h"



Cell::Cell() 
    : isFilled{false}, isBlind{false}, fillType{'-'}, x{0}, y{0}, width{0}, height{0} {} // constructor


Cell::~Cell() {} // destructor


<<<<<<< HEAD
void Cell::toggleBlind() {
    isBlind = true;
}

void Cell::untoggleBlind(){
    isBlind = false;
}


void Cell::setFill(char fill /*, Colour c */) {
=======
/*
void Cell::setFill(char fill , Colour c ) {
>>>>>>> 3cefc50fb7715329a75217feb331853253023e8e
    fillType = fill;
} // setFill
*/


// setCoords(int x, int y, int width, int height, XWindow* window);
// void draw();


bool Cell::cellFilled() {
    return isFilled;
} // cellFilled

void Cell::setCell(char blockType){
    isFilled = true;
    fillType = blockType;
}

void Cell::unsetCell(){
    isFilled = false;
    // fillType = '_';
}

int Cell::get_X() {
    return x;
}

int Cell::get_Y() {
    return y;
}

std::ostream& operator<<(std::ostream& out, Cell& cell) {
<<<<<<< HEAD
    if (isBlind) {
        out << '?'
    } else {
        out << fillType;
    } // if
    
=======
    if (cell.isFilled) out << cell.fillType;
    else out << "_"; //debugging reasons
>>>>>>> 3cefc50fb7715329a75217feb331853253023e8e
    return out;
} // operator<<