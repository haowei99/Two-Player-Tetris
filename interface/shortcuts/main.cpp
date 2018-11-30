#include <iostream>
#include <string>
#include "commandinterpreter.h"
using namespace std;

int main() {
    CommandInterpreter* ci = new CommandInterpreter;

    ci->addCommand("right");
    ci->addCommand("left");
    ci->addCommand("down");
    ci->addCommand("drop");
    ci->addCommand("clockwise");
    ci->addCommand("counterclockwise");
    ci->addCommand("levelup");
    ci->addCommand("leveldown");

    string s;
    
    while (cin >> s) {
        string command = ci->interpret(s);

        if (command == "") {
            cout << "Command not valid" << endl;
        } else {
            cout << "Did you mean: " << command << "?" << endl;
        } // if
    } // while

    delete ci;
} // main