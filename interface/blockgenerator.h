#ifndef __BLOCKGENERATOR_H__
#define __BLOCKGENERATOR_H__
#include <string>
#include <iostream>
#include <fstream>
#include "block.h"
#include "board.h"
#include "numbergenerator.h"

/** TODOS
 * figure out how setseed works for random number generator
 * ***/

class BlockGenerator {
    Board* board;
    NumberGenerator* ng;
    std::string sequenceFileName;
    std::ifstream sequenceReader;
    std::string noRandomFileName;
    std::ifstream noRandomFileReader;
    bool isRandom = true;

    std::string generateLevel0();
    std::string generateLevel1(int random);
    std::string generateLevel2(int random);
    std::string generateLevel34(int random);
    int randNum(int lower, int upper);
    Block* makeBlock(std::string type, int level);
public:
    BlockGenerator(Board* board, NumberGenerator* ng, std::string sequenceFileName);
    ~BlockGenerator();
    Block* generateBlock(int level);
    void setStream(std::string fileName);
    void unsetStream();
    void reset();
};

#endif /** __BLOCKGENERATOR_H__ **/