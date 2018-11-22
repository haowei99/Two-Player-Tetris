#include "block.h"
#include "cell.h"

Block::Block(int x, int y, int level, Board *board)
    : x{x}, y{y}, level{level}, board{board}, dropSpeed{0}, len{0} {
    if (level >= 3) {
        dropSpeed = 1;
    } // if
} // constructor


Block::~Block() {} // destructor


int Block::getDropSpeed() {
    return dropSpeed;
} // getDropSpeed


void Block::setDropSpeed(int speed) {
    dropSpeed = speed;
} // setDropSpeed


int Block::getPoints() {
    return (level + 1) * (level + 1);
} // getPoints



//implement later
/*bool Block::onBoard() {
    for (int i = 0; i < len;i++) {
        if (cells[i]->getBlock() == this) {
            return true;
        } // if
    } // for

    return false;
} // onBoard
*/

void Block::addCell(Cell* cell) {
    cells[len] = cell;
    len = len + 1;
    std::cout << "Cell at: " << len << *cell << std::endl;
} // addCell

char Block::getBlockType() {
    return blockType;
}
