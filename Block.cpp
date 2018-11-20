#include "block.h"
#include "board.h"
#include "cell.h"

Block::Block(int x, int y, int level, Board* board)
    : x{x}, y{y}, level{level}, board{board}, dropSpeed{0}, len{0} {
    if (level >= 3) {
        dropSpeed = 1;
    } // if
} // constructor


int Block::getDropSpeed() {
    return dropSpeed;
} // getDropSpeed


void Block::setDropSpeed(int speed) {
    dropSpeed = speed;
} // setDropSpeed


int Block::getPoints() {
    return (level + 1) * (level + 1);
} // getPoints


bool Block::onBoard() {
    for (int i = 0; i < len;i++) {
        if (cells[i]->getBlock == this) {
            return true;
        } // if
    } // for

    return false;
} // onBoard


void Block::addCell(Cell* cell) {
    cells[len] = cell;
    len += 1;
} // addCell