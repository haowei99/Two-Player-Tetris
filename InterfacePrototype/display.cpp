#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "display.h"


Display::Display(int width, int height, int startLevel) 
    : width{width}, height{height},
      grid{std::vector<std::vector<Cell>> (height, std::vector<Cell> (width))},
      startLevel{startLevel} {
} // constructor


Display::~Display() {
    for (int i = 0;i < height;i++) {
        grid.at(i).clear();
    } // for

    grid.clear();
} // destructor


void Display::init() {
    player1Level = startLevel;
    player2Level = startLevel;

    for (int i = 0;i < width;i++) {
        if (i < 11 || i > 16) {
            grid.at(0).at(i).setFill('-');
            grid.at(19).at(i).setFill('-');
        } // if
    } // for

    grid.at(20).at(0).setFill('N');
    grid.at(20).at(1).setFill('e');
    grid.at(20).at(2).setFill('x');
    grid.at(20).at(3).setFill('t');
    grid.at(20).at(4).setFill(':');

    grid.at(20).at(18).setFill('N');
    grid.at(20).at(19).setFill('e');
    grid.at(20).at(20).setFill('x');
    grid.at(20).at(21).setFill('t');
    grid.at(20).at(22).setFill(':');
} // init


void Display::reset() {
    player1Score = 0;
    player2Score = 0;
    init(); 
} // reset


void Display::drawPlayer1Score(int score) {
    // draw block to the correct coordinate
    player1Score = score;
} // drawPlayer1Score


void Display::drawPlayer2Score(int score) {
    // draw block to the correct coordinate
    player2Score = score;
} // drawPlayer2Score


//void Display::drawPlayer1Next(Block* block) {
    // draw block to the correct coordinate
//} // drawPlayer1Next


//void Display::drawPlayer2Next(Block* block) {
    // draw block to the correct coordinate
//} // drawPlayer2Next


std::ostream& operator<<(std::ostream& out, Display& d) {
    /***
     * for graphical display, maybe store each indiviual msg
     * in a string using a stringstream, then draw those strings
     * to the Xwindow using drawstring at the correct coordinates
     * As for the text display, just out << msg from stringstream
     * ***/
    out << "Level: ";
    out << std::setfill(' ') << std::setw(4) << d.player1Level;

    for (int i = 0;i < 6;i++) {
        out << " ";
    } // for

    out << "Level: ";
    out << std::setfill(' ') << std::setw(4) << d.player2Level;
    out << std::endl;

    out << "Score: ";
    out << std::setfill(' ') << std::setw(4) << d.player1Score;

    for (int i = 0;i < 6;i++) {
        out << " ";
    } // for

    out << "Score: ";
    out << std::setfill(' ') << std::setw(4) << d.player2Score;
    out << std::endl;
    
    for (int i = 0;i < d.height;i++) {
        for (int j = 0;j < d.width;j++) {
            out << d.grid.at(i).at(j);
        } // for

        out << std::endl;
    } // for

    return out;
} // operator<<
