#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include "cell.h"


class Board;

const int max = 4;

class Block {
    friend Board;
protected:
    int level;
    Board* board;
    int curLevel;
    bool hasHeavy;
    Cell* cells[max];
    int len = 0;
    char blockType;
    //initial rotate state is 1
    int rotateState = 1;
    int numCells = 4;
    bool counted; //for score counting
    
public:
    Block(int level, Board* board);
    virtual ~Block();
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterClockwise() = 0;
    void applyDropSpeed();
    void right();
    void left();
    void down();
    void drop();
    bool canMoveDown(); 
    bool canMoveRight();
    bool canMoveLeft();
    char getBlockType();
    int getDropSpeed();
    void setDropSpeed(int speed);
    int getPoints();
    void addCell(Cell* cell);
    bool in_grid(int x, int y); // check if block is within board
    int getCellSize();
    void applyHeavy();
    void shiftDown(); // shifts the block down by 1
    void setCurLevel(int newCurLevel);
};

#endif // __BLOCK_H__
