#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <string>
#include <iostream>
#include "cell.h"

class Display {
public:
    void init();
    void reset();
    void setPlayer1Score(int score);
    void setPlayer2Score(int score);
    void setPlayer1Next(Block* block);
    void setPlayer2Next(Block* block);

    friend std::ostream& operator<<(std::ostream& out, Display& d);
};

std::ostream& operator<<(std::ostream& out, Display& d);

#endif /** __DISPLAY_H__ **/
