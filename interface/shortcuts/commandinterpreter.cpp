#include <string>
#include "commandinterpreter.h"


std::string CommandInterpreter::toLowerCase(std::string s) {
    int len = s.length();
    
    for (int i = 0;i < len;i++) {
        char c = s[i];
        
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        } // if
    } // for
    
    return s;
} // toLowerCase

CommandInterpreter::CommandInterpreter() : trie{new Trie()} {} // constructor


CommandInterpreter::~CommandInterpreter() {
    delete trie;
} // destructor


void CommandInterpreter::addCommand(std::string command) {
    trie->addCommand(toLowerCase(command));
} // addCommand


std::string CommandInterpreter::interpret(std::string command) {
    return trie->interpret(toLowerCase(command));
} // interpret