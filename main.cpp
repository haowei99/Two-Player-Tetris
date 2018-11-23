#include "block.h"
#include "board.h"
#include "oBlock.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    int a = 5; 
    int c = 0;
    Board b(0, 0);
    b.init();
    cout << "Board:" << endl;
    cout << b << endl;
    string c;
    Board * bp = &b;
    bp->changeBlock();
    Block *oblo = bp->getBlock();
    //Block * oblo =  new oBlock(0,0,0,bp);
    cout << "Board next:" << endl;
    cout << b << endl;
    while (cin >> c){
        if (c == "r"){ // right
            oblo->right();
        }
        else if (c == "l"){ //left
            oblo->left();
        }
        else if (c == "d"){ //down
            oblo->down();
        }
        else if (c == "rC"){
            oblo->rotateClockwise();
        }
        else if (c == "rCC"){
            oblo->rotateCounterClockwise();
        }
        else if (c == "p"){
            cout << b;
        }
        cout << b << endl;
    }
/*
    vector<vector<int>> new_grid(15, vector<Cell>(11));
    Board * board = nullptr;
    iBlock b = iBlock(0, 0, 1, board);
    b.rotateClockwise();

    */
cout << "Hello World" << endl;

}

