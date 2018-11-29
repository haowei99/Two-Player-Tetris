#include <cstdlib>
#include "numbergenerator.h"


NumberGenerator::NumberGenerator(bool willSetSeed, int seed) {
    if (willSetSeed) {
        srand(seed);
    } // if
} // constructor


NumberGenerator::~NumberGenerator() {} // destructor


int NumberGenerator::randNum(int lower, int upper) {
    return (rand() % upper) + lower;
} // randNum