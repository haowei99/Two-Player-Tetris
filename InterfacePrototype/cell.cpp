#include <iostream>
#include <string>
#include "cell.h"


Cell::Cell()
    : fill{' '}, cellFilled{false}, cellBlinded{false} {} // constructor


Cell::~Cell() {} // destructor


void Cell::blind() {
    cellBlinded = true;
} // blind


void Cell::unblind() {
    cellBlinded = false;
} // unblind


void Cell::setFill(char fillType) {
    fill = fillType;
    // calls draw
} // setFill


bool Cell::isFilled() {
    return cellFilled;
} // isFilled


std::ostream& operator<<(std::ostream& out, Cell& c) {
    /**
     * NOTE: when drawing blinded cells to Xwindow, Cell::draw will have
     * to be called EXPLICITLY, and NOT THROUGH SETFILL
     * ***/
    
    if (c.cellBlinded) {
        out << '?';
    } else {
        out << c.fill;
    } // if

    return out;
} // operator<<