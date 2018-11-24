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
    cell->set_X(cell->get_X()); //wont get coordinates!
    cell->set_Y(cell->get_Y());
    len = len + 1;
    std::cout << "Cell at: " << len << *cell << std::endl;
} // addCell

char Block::getBlockType() {
    return blockType;
}

bool Block::in_grid(int x, int y) {
    if ((x >= 0 && x < 11) && (y >= 0 && y < 18)) return true;
    else return  false;
}