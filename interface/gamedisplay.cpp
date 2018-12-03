#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "board.h"
#include "gamedisplay.h"
#include "window.h"

std::string GameDisplay::intToStr(int n) {
    std::stringstream ss("");
    ss << n;
    return ss.str();
} // intToStr


void GameDisplay::setupInfo() {
    if (window != nullptr) {
        window->fillRectangle(0, 0, 700, 100, Xwindow::White);
        
        window->drawBigString(10, 25, "High:");
        window->drawBigString(10, 50, "Level:");
        window->drawBigString(10, 75, "Score:");
        window->drawBigString(60, 25, intToStr(player1Highscore));
        window->drawBigString(60, 50, intToStr(player1Level));
        window->drawBigString(60, 75, intToStr(player1Score));

        window->drawBigString(435, 25, "High:");
        window->drawBigString(435, 50, "Level:");
        window->drawBigString(435, 75, "Score:");
        window->drawBigString(485, 25, intToStr(player2Highscore));
        window->drawBigString(485, 50, intToStr(player2Level));
        window->drawBigString(485, 75, intToStr(player2Score));
    } // if
} // setupInfo


GameDisplay::GameDisplay(int startLevel, Xwindow* window) 
    : startLevel{startLevel}, window{window} {} // constructor


GameDisplay::~GameDisplay() {
} // destructor


void GameDisplay::init(Board* board1, Board* board2) {
    this->board1 = board1;
    this->board2 = board2;
    player1Level = startLevel;
    player2Level = startLevel;
    
    setupInfo();
} // init


void GameDisplay::reset() {
    player1Score = 0;
    player2Score = 0;
} // reset


void GameDisplay::updatePlayer1Score(int score) {
    // draw score to the correct coordinate
    player1Score = score;

    setupInfo();
} // updatePlayer1Score


void GameDisplay::updatePlayer2Score(int score) {
    // draw score to the correct coordinate
    player2Score = score;

    setupInfo();
} // updatePlayer2Score


void GameDisplay::updatePlayer1Highscore(int score) {
    player1Highscore = score;

    setupInfo();
} // updatePlayer1Highscore
    
    
void GameDisplay::updatePlayer2Highscore(int score) {
    player2Highscore = score;

    setupInfo();
} // updatePlayer2Highscore


void GameDisplay::updatePlayer1Level(int level) {
    player1Level = level;

    setupInfo();
} // updatePlayer1Level


void GameDisplay::updatePlayer2Level(int level) {
    player2Level = level;

    setupInfo();
} // updatePlayer2Level


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
