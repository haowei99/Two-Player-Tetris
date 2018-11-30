#include <string>
#include <sstream>
#include "commandinterpreter.h"


std::string CommandInterpreter::Trie::charToStr(char c) {
    std::stringstream ss;

    ss << c;
    return ss.str();
} // charToStr


CommandInterpreter::Trie::Trie() {
    for (int i = 0;i < 26;i++) {
        children[i] = nullptr;
    } // for
} // constructor


CommandInterpreter::Trie::~Trie() {
    for (int i = 0;i < 26;i++) {
        delete children[i];
    } // for
} // destructor


void CommandInterpreter::Trie::addCommand(std::string command) {
    if (command.length() > 0) {
        char c = command[0];
        int index = c - 'a';

        if (children[index] == nullptr) {
            children[index] = new TrieNode();
        } // if

        children[index]->addCommand(command.substr(1));
    } // if
} // addCommand


std::string CommandInterpreter::Trie::interpret(std::string command) {
    if (command.length() > 0) {
        char c = command[0];
        int index = c - 'a';

        if (children[index] == nullptr) {
            return "";
        } else {
            return children[index]->interpret(command.substr(1), charToStr(c));
        } // if
    } else {
        return "";
    } // if
} // interpret
