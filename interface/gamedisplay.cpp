#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "cell.h"
#include "board.h"
#include "gamedisplay.h"


GameDisplay::GameDisplay(int width, int height, int startLevel) 
    : width{width}, height{height},
      grid{std::vector<std::vector<Cell>> (height, std::vector<Cell> (width))},
      startLevel{startLevel} {
} // constructor


GameDisplay::~GameDisplay() {
    for (int i = 0;i < height;i++) {
        grid.at(i).clear();
    } // for

    grid.clear();
} // destructor


void GameDisplay::init() {
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


void GameDisplay::reset() {
    player1Score = 0;
    player2Score = 0;
    init(); 
} // reset


void GameDisplay::updateHighscore(int highscore) {
    this->highscore = highscore;
    // draw highscore to correct coordinate
} // updateHighscore


void GameDisplay::updatePlayer1Score(int score) {
    // draw score to the correct coordinate
    player1Score = score;
} // updatePlayer1Score


void GameDisplay::updatePlayer2Score(int score) {
    // draw score to the correct coordinate
    player2Score = score;
} // updatePlayer2Score


//void Display::updatePlayer1Next(Block* block) {
    // draw block to the correct coordinate
//} // updatePlayer1Next


//void Display::updatePlayer2Next(Block* block) {
    // draw block to the correct coordinate
//} // updatePlayer2Next


std::ostream& operator<<(std::ostream& out, GameDisplay& d) {
    /***
     * for graphical display, maybe store each indiviual msg
     * in a string using a stringstream, then draw those strings
     * to the Xwindow using drawstring at the correct coordinates
     * As for the text display, just out << msg from stringstream
     * ***/
    out << "Highscore: " << d.highscore << std::endl;
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
