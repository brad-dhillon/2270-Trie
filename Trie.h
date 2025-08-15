#ifndef TRIE_H__
#define TRIE_H__


#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

struct Trie_node {
    bool endWord = false;
    unordered_map<char, Trie_node*> children;

};

class Trie {

public:

    Trie();
    ~Trie();

    bool insert(string word);

    bool search(string word);

    bool startsWith(string word);

    void erase(string word);

    string longestCommonPrefix();


private:

    Trie_node* root;

    Trie_node* findNode(string word);

    void clear(Trie_node* node);

    bool erase(Trie_node* currentNode, string word, int depth);
};


#endif