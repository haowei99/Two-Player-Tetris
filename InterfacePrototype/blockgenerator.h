#ifndef __BLOCKGENERATOR_H__
#define __BLOCKGENERATOR_H__
#include <string>
#include <iostream>
#include <fstream>
#include "numbergenerator.h"

/** TODOS
 * figure out how setseed works for random number generator
 * ***/

class BlockGenerator {
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
public:
    BlockGenerator(NumberGenerator* ng, std::string sequenceFileName);
    ~BlockGenerator();
    std::string generateBlock(int level); // change to return block later
    void setStream(std::string fileName);
    void unsetStream();
    void reset();
};

#endif /** __BLOCKGENERATOR_H__ **/