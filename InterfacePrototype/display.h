#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <string>
#include <iostream>
#include <vector>
#include "cell.h"

class Display {
    int width, height;
    std::vector<std::vector<Cell>> grid;
    int startLevel;
    int player1Level, player2Level;
    int player1Score = 0;
    int player2Score = 0;
public:
    Display(int width, int height, int startLevel);
    ~Display();
    void init();
    void reset();
    void drawPlayer1Score(int score);
    void drawPlayer2Score(int score);
    //void drawPlayer1Next(Block* block);
    //void drawPlayer2Next(Block* block);

    friend std::ostream& operator<<(std::ostream& out, Display& d);
};

std::ostream& operator<<(std::ostream& out, Display& d);

#endif /** __DISPLAY_H__ **/
