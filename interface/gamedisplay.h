#ifndef __GAMEDISPLAY_H__
#define __GAMEDISPLAY_H__
#include <string>
#include <iostream>
#include "board.h"

class GameDisplay {
    int startLevel;
    Board *board1;
    Board *board2;
    int player1Level, player2Level;
    int player1Score = 0;
    int player2Score = 0;
    int player1Highscore = 0;
    int player2Highscore = 0;

public:
    GameDisplay(int startLevel);
    ~GameDisplay();
    void init(Board* board1, Board* board2);
    void reset();
    void updatePlayer1Score(int score);
    void updatePlayer2Score(int score);
    void updatePlayer1Highscore(int score);
    void updatePlayer2Highscore(int score);

    friend std::ostream& operator<<(std::ostream& out, GameDisplay& d);
};

std::ostream& operator<<(std::ostream& out, GameDisplay& d);

#endif /** __GAMEDISPLAY_H__ **/
