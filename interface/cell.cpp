#include <iostream>
#include "cell.h"
#include "block.h"
#include "window.h"


Cell::Cell() 
    : isFilled{false}, isBlind{false}, fillType{'-'}, x{0}, y{0}, width{0}, height{0} {} // constructor


Cell::~Cell() {} // destructor


void Cell::setFill() {
    if ( fillType == 'I'){
        colour = Xwindow::Cyan;
    }
    else if ( fillType == 'Z'){
        colour = Xwindow::Red;
    }
    else if ( fillType == 'S'){
        colour = Xwindow::Green;
    }
    else if ( fillType == 'T'){
        colour = Xwindow::Magenta;
    }
    else if ( fillType == 'O'){
        colour = Xwindow::DarkGreen;
    }
    else if ( fillType == 'J'){
        colour = Xwindow::Orange;
    }
    else if ( fillType == 'L'){
        colour = Xwindow::Brown;
    }
    else if ( fillType == '*'){
        colour = Xwindow::Yellow;
    }
    else if ( fillType == '-'){
        colour = Xwindow::Black;
    } 
    else {
        colour = Xwindow::White;
    }

    if (isBlind) {
        colour = Xwindow::Black;
    }
} // setFill


void Cell::setCoords(int x, int y, int w, int h, Xwindow *window) {
    xcoord = x;
    ycoord = y;
    width= w;
    height = h;
    win = window;
}


void Cell::draw() {
    setFill();
    // must shrink the size a little bit smaller

    if (win != nullptr) {
        win->fillRectangle(xcoord + 1,ycoord + 1 ,width - 1,height - 1, colour); //need a color
    } // if
}


void Cell::undraw() {
    if (win != nullptr) {
        win->fillRectangle(xcoord + 1,ycoord + 1 ,width - 1,height - 1, 0); //need a default color
    } // if
}


bool Cell::cellFilled() {
    return isFilled;
} // cellFilled


void Cell::setCell(char blockType){
    isFilled = true;
    fillType = blockType;
    draw();
}


void Cell::unsetCell(){
    isFilled = false;
    undraw();
}


int Cell::get_X() {
    return x;
}


int Cell::get_Y() {
    return y;
}


void Cell::set_X(int xCoor){
    x = xCoor;
}


void Cell::set_Y(int yCoor){
    y = yCoor;
}


void Cell::blind(){
    isBlind = true;
    draw();
}


void Cell::unblind(){
    isBlind = false;
    if ( this->isFilled ){
        draw();
    }
    else {
        undraw();
    }
}


std::ostream& operator<<(std::ostream& out, Cell& cell) {
    if (cell.isBlind) out << "?";
    else if (cell.isFilled) out << cell.fillType;
    else out << " "; 
    return out;
} // operator<<