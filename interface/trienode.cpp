#include <string>
#include <sstream>
#include "commandinterpreter.h"


std::string CommandInterpreter::TrieNode::charToStr(char c) {
    std::stringstream ss;

    ss << c;
    return ss.str();
} // charToStr


CommandInterpreter::TrieNode::TrieNode() : usedIn{0} {
    for (int i = 0;i < 26;i++) {
        children[i] = nullptr;
    } // for
} // constructor
    

CommandInterpreter::TrieNode::~TrieNode() {
    for (int i = 0;i < 26;i++) {
        delete children[i];
    } // for
} // destructor


void CommandInterpreter::TrieNode::addCommand(std::string command) {
    usedIn += 1;

    if (command.length() > 0) {
        char c = command[0];
        int index = c - 'a';

        if (children[index] == nullptr) {
            children[index] = new TrieNode();
        } // if

        children[index]->addCommand(command.substr(1));
    } // if
} // addCommand


std::string CommandInterpreter::TrieNode::interpret(std::string command, std::string retval) {
    if (command.length() > 0) {
        char c = command[0];
        int index = c - 'a';

        retval += charToStr(c);

        if (children[index] == nullptr) {
            return "";
        } else {
            return children[index]->interpret(command.substr(1), retval);
        } // if
    } else {
        if (usedIn > 1) {
            return "";
        } else {
            int nextIndex;
            TrieNode* node = nullptr;

            for (int i = 0;i < 26;i++) {
                if (children[i] != nullptr) {
                    node = children[i];
                    nextIndex = i;
                    break;
                } // if
            } // for

            if (node != nullptr) {
                char temp = 'a' + nextIndex;
                retval += charToStr(temp);

                return node->interpret(command, retval);
            } else {
                return retval;
            } // if
        } // if
    } // if
} // interpret