#include <iostream>
#include "cell.h"
#include "block.h"
#include "window.h"



Cell::Cell() 
    : isFilled{false}, isBlind{false}, fillType{'-'}, x{0}, y{0}, width{0}, height{0} {} // constructor


Cell::~Cell() {} // destructor



void Cell::setFill() {
    if ( fillType = 'I'){
        colour = Xwindow::Cyan;
    }
    else if ( fillType = 'Z'){
        colour = Xwindow::Red;
    }
    else if ( fillType = 'S'){
        colour = Xwindow::Green;
    }
    else if ( fillType = 'T'){
        colour = Xwindow::Magenta;
    }
    else if ( fillType = 'O'){
        colour = Xwindow::DarkGreen;
    }
    else if ( fillType = 'J'){
        colour = Xwindow::Orange;
    }
    else if ( fillType = 'L'){
        colour = Xwindow::Brown;
    }
    else if ( fillType = '*'){
        colour = Xwindow::Yellow
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
    win->fillRectangle(xcoord,ycoord,width,height, colour); //need a color
};

void Cell::undraw() {
    win->fillRectangle(xcoord,ycoord,width,height, 0); //need a default color
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
    // fillType = '_';
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
}

void Cell::unblind(){
    isBlind = false;
}




std::ostream& operator<<(std::ostream& out, Cell& cell) {
    if (cell.isBlind) out << "?";
    else if (cell.isFilled) out << cell.fillType;
    else out << " "; //debugging reasons
    return out;
} // operator<<