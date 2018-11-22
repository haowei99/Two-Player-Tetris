#include <iostream>
#include "cell.h"
#include "block.h"


Cell::Cell() 
    : isFilled{false}, isBlind{false}, fillType{'-'}, x{0}, y{0}, width{0}, height{0} {} // constructor


Cell::~Cell() {} // destructor


void Cell::toggleBlind() {
    isBlind = true;
}

void Cell::untoggleBlind(){
    isBlind = false;
}


void Cell::setFill(char fill /*, Colour c */) {
    fillType = fill;
} // setFill


// setCoords(int x, int y, int width, int height, XWindow* window);
// void draw();


bool Cell::cellFilled() {
    return isFilled;
} // cellFilled


bool Cell::bottomFilled() {
    if (neighbourBottom != nullptr) {
        return neighbourBottom->cellFilled();
    } // if

    return false;
}


bool Cell::rightFilled() {
    if (neighbourRight != nullptr) {
        return neighbourRight->cellFilled();
    } // if

    return false;
} // rightFilled


bool Cell::leftFilled() {
    if (neighbourLeft != nullptr) {
        return neighbourLeft->cellFilled();
    } // if

    return false;
} // leftFilled


Block* Cell::getBlock() {
    return block;
} // getBlock


void Cell::addBlock(Block* block) {
    this->block = block;
} // addBlock


std::ostream& operator<<(std::ostream& out, Cell& cell) {
    if (isBlind) {
        out << '?'
    } else {
        out << fillType;
    } // if
    
    return out;
} // operator<<