#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "blockgenerator.h"


BlockGenerator::BlockGenerator(std::string sequenceFileName) 
    : sequenceFileName{sequenceFileName} {} // constructor


BlockGenerator::~BlockGenerator() {
    reset();
} // destructor <-- ASK: default dtor ok?


void BlockGenerator::reset() {
    isRandom = true;
    noRandomFileName = "";
    
    if (sequenceReader.is_open()) {
        sequenceReader.close();
    } // if

    if (noRandomFileReader.is_open()) {
        noRandomFileReader.close();
    } // if
} // reset


std::string BlockGenerator::generateLevel0() {
    std::string type;

    if (!sequenceReader.is_open()) {
        sequenceReader.open(sequenceFileName.c_str());
    } // if

    sequenceReader >> type;

    if (sequenceReader.fail()) {
        sequenceReader.close();
        sequenceReader.open(sequenceFileName.c_str());
        sequenceReader >> type;
    } // if

    return type;
} // generateLevel0


std::string BlockGenerator::generateLevel1(int random) {
    switch(random) {
        case 0:
            return "S";
        case 1:
            return "Z";
        case 2:
        case 3:
            return "I";
        case 4:
        case 5:
            return "J";
        case 6:
        case 7:
            return "L";
        case 8:
        case 9:
            return "O";
        case 10:
        case 11:
            return "T";
    } // switch

    return "";
} // generateLevel1


std::string BlockGenerator::generateLevel2(int random) {
    switch(random) {
        case 0: 
            return "I";
        case 1:
            return "J";
        case 2:
            return "L";
        case 3:
            return "O";
        case 4:
            return "S";
        case 5:
            return "Z";
        case 6:
            return "T";
    } // switch    

    return "";
} // generateLevel2


std::string BlockGenerator::generateLevel34(int random) {
    if (isRandom) {
        switch(random) {
            case 0:
            case 1:
                return "S";
            case 2:
            case 3:
                return "Z";
            case 4:
                return "I";
            case 5:
                return "J";
            case 6:
                return "L";
            case 7:
                return "O";
            case 8:
                return "T";
        } // switch
    } else {
        std::string type;

        if (!noRandomFileReader.is_open()) {
            noRandomFileReader.open(noRandomFileName.c_str());
        } // if

        noRandomFileReader >> type;

        if (noRandomFileReader.fail()) {
            noRandomFileReader.close();
            noRandomFileReader.open(noRandomFileName.c_str());
            noRandomFileReader >> type;
        } // if

        return type;
    } // if

    return "";
} // generateLevel34 


int BlockGenerator::randNum(int lower, int upper) {
    return (rand() % upper) + lower;
} // randNum


// change to return block later
std::string BlockGenerator::generateBlock(int level) {
    if (level == 0) {
        return generateLevel0();
    } else if (level == 1) {
        return generateLevel1(randNum(0, 11));
    } else if (level == 2) {
        return generateLevel2(randNum(0, 6));
    } else {
        return generateLevel34(randNum(0, 8));
    } // if
} // generateBlock

// ASK: should calling this while noRandomFileReader is already open
// reset it to the beginning of file?
void BlockGenerator::setStream(std::string fileName) {
    if (isRandom) {
        isRandom = false;
        noRandomFileName = fileName;
        noRandomFileReader.open(noRandomFileName.c_str());
    } // if
} // setStream


void BlockGenerator::unsetStream() {
    if (!isRandom) {
        isRandom = true;
        noRandomFileName = "";
        noRandomFileReader.close();
    } // if
} // unsetStream();