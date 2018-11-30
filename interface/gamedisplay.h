#ifndef __GAMEDISPLAY_H__
#define __GAMEDISPLAY_H__
#include <string>
#include <iostream>
#include <vector>
#include "cell.h"
#include "board.h"

class GameDisplay {
    int width, height;
    std::vector<std::vector<Cell>> grid;
    int startLevel;
    int player1Level, player2Level;
    int player1Score = 0;
    int player2Score = 0;
    int highscore = 0;
public:
    GameDisplay(int width, int height, int startLevel);
    ~GameDisplay();
    void init();
    void reset();
    void updatePlayer1Score(int score);
    void updatePlayer2Score(int score);
    //void updatePlayer1Next(Block* block);
    //void updatePlayer2Next(Block* block);
    void updateHighscore(int highscore);

    friend std::ostream& operator<<(std::ostream& out, GameDisplay& d);
};

std::ostream& operator<<(std::ostream& out, GameDisplay& d);

#endif /** __GAMEDISPLAY_H__ **/
