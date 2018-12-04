#ifndef __NUMBERGENERATOR_H__
#define __NUMBERGENERATOR_H__


class NumberGenerator {
public:
    NumberGenerator(bool willSetSeed, int seed);
    ~NumberGenerator();
    int randNum(int lower, int upper);
};


#endif /** __NUMBERGENERATOR_H__ **/