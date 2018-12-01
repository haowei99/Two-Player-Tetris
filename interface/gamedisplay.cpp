#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "board.h"
#include "gamedisplay.h"


GameDisplay::GameDisplay(int startLevel) 
    : startLevel{startLevel} {} // constructor


GameDisplay::~GameDisplay() {
} // destructor


void GameDisplay::init(Board* board1, Board* board2) {
    this->board1 = board1;
    this->board2 = board2;
    player1Level = startLevel;
    player2Level = startLevel;
} // init


void GameDisplay::reset() {
    player1Score = 0;
    player2Score = 0;
} // reset


void GameDisplay::updatePlayer1Score(int score) {
    // draw score to the correct coordinate
    player1Score = score;
} // updatePlayer1Score


void GameDisplay::updatePlayer2Score(int score) {
    // draw score to the correct coordinate
    player2Score = score;
} // updatePlayer2Score


void GameDisplay::updatePlayer1Highscore(int score) {
    player1Highscore = score;
} // updatePlayer1Highscore
    
    
void GameDisplay::updatePlayer2Highscore(int score) {
    player2Highscore = score;
} // updatePlayer2Highscore


std::ostream& operator<<(std::ostream& out, GameDisplay& d) {
    /***
     * for graphical display, maybe store each indiviual msg
     * in a string using a stringstream, then draw those strings
     * to the Xwindow using drawstring at the correct coordinates
     * As for the text display, just out << msg from stringstream
     * ***/
    out << "High: ";
    out << std::setfill(' ') << std::setw(5) << d.player1Highscore;

    for (int i = 0;i < 6;i++) {
        out << " ";
    } // for

    out << "High: ";
    out << std::setfill(' ') << std::setw(5) << d.player2Highscore;
    out << std::endl;


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


    for (int i = 0; i < 22; i++){
        for ( int j = 0; j < 11; j++){
            out << d.board1->getline(i)[j];
        }

        for (int i = 0; i < 6 ; i++) {
            out << " ";
        } // for

        for ( int j = 0; j < 11; j++){
            out << d.board2->getline(i)[j];
        }
        out << std::endl;
    }

    return out;
} // operator<<
