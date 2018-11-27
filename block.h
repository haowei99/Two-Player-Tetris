#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include "cell.h"
//#include "board.h"

class Board;

const int max = 4;

class Block {
    friend Board;
protected:
    int xCoor, yCoor; // coords of top left corner of block NO LONGER NEEDED NO KEEPING TRACK OF top left
    int level;
    Board* board;
    int dropSpeed;
    Cell* cells[max];
    int len = 0;
    char blockType;
    //initial roatate state =1
    int rotateState = 1;
    // XWindow* window;
    int numCells = 4;
    
public:
    Block(int x, int y, int level, Board* board);
    ~Block();
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
   // virtual void rotate(int state) =0; //for state changes
    char getBlockType();
    int getDropSpeed();
    void setDropSpeed(int speed);
    int getPoints();
    bool onBoard();
    void addCell(Cell* cell);
    bool in_grid(int x, int y); // check if block is within board
};

#endif // __BLOCK_H__
