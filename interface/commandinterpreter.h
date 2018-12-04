#ifndef __COMMANDINTERPRETER_H__
#define __COMMANDINTERPRETER_H__
#include <string>


class CommandInterpreter {
    class TrieNode {
        int usedIn;
        TrieNode* children[26];

        std::string charToStr(char c);
    public:
        TrieNode();
        ~TrieNode();
        void addCommand(std::string command);
        std::string interpret(std::string command, std::string retval);
    };

    class Trie {
        TrieNode* children[26];

        std::string charToStr(char c);
    public:
        Trie();
        ~Trie();
        void addCommand(std::string command);
        std::string interpret(std::string command);
    };

    Trie* trie;

    std::string toLowerCase(std::string s);
public:
    CommandInterpreter();
    ~CommandInterpreter();
    void addCommand(std::string command);
    std::string interpret(std::string command);
};


#endif /** __COMMANDINTERPRETER_H__ **/