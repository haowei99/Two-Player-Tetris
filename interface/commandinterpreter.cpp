#include <string>
#include "commandinterpreter.h"


// helper function for converting a string to all lower case
// this makes input case insensitive
std::string CommandInterpreter::toLowerCase(std::string s) {
    int len = s.length();
    
    for (int i = 0;i < len;i++) {
        char c = s[i];
        
        if (c >= 'A' && c <= 'Z') {
            s[i] = c - 'A' + 'a';
        } // if
    } // for
    
    return s;
} // toLowerCase


CommandInterpreter::CommandInterpreter() : trie{new Trie()} {} // constructor


CommandInterpreter::~CommandInterpreter() {
    delete trie;
} // destructor


// adds a command to the trie
void CommandInterpreter::addCommand(std::string command) {
    trie->addCommand(toLowerCase(command));
} // addCommand


// returns "" if command is not a valid command or command shortcut
// returns the whole command that the argument represents if valid
std::string CommandInterpreter::interpret(std::string command) {
    return trie->interpret(toLowerCase(command));
} // interpret