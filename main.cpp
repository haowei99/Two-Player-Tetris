#include "block.h"
#include "board.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    Board b(0, 0);
    b.init();
    cout << "Board:" << endl;
    cout << b << endl;
    string c;
    Board * bp = &b;

    bp->changeBlock('i');
    Block *oblo = bp->getBlock(); //curr block
    bp->set_blocks(oblo, oblo);
    //Block * oblo =  new oBlock(0,0,0,bp);
    cout << "Board next:" << endl;
    cout << b << endl;
    while (cin >> c){
        bool drop = false;
        if (c == "r"){ // right
            //cout << bp->getBlock() << endl;
            oblo->right();
        }
        else if (c == "l"){ //left
            oblo->left();
        }
        else if (c == "drop"){ //down
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('j');
            drop = true;
            //oblo = bp->getBlock();
        }
        else if (c == "dropi"){
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('i');
            drop = true;
        }
        else if (c == "dropl"){
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('l');
            drop = true;
        }
        else if (c == "dropo"){
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('o');
            drop = true;
        }
        else if (c == "drops"){
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('s');
            drop = true;
        }
        else if (c == "dropz"){
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('z');
            drop = true;
        }
        else if (c == "dropt"){
            oblo->drop();
            Block *tmp = oblo;
            bp->addBlock(tmp);
            oblo = bp->changeBlock('t');
            drop = true;
        }
        else if (c == "rC"){
            oblo->rotateClockwise();
        }
        else if (c == "rCC"){
            oblo->rotateCounterClockwise();
        }
        else if(c == "d") {
            oblo->down();
            if (!oblo->canMoveDown()){
                Block *tmp = oblo;
                bp->addBlock(tmp);
                oblo = nullptr;
                oblo = bp->changeBlock('j');
                drop = true;
                //oblo = bp->getBlock(); 
            }
        }
        else if (c == "reset"){
            b.reset();
            b.init();
            bp = &b;
        }
        if (drop) bp->checkRows();
        //check blocks deleted
        int score = 0;
        for(int i =0; i < bp->loBlock.size(); i++){
            int size = bp->loBlock[i]->getCellSize();
            if (size == 0) score++;
        }
        cout << "Score is: " << score << endl;
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

