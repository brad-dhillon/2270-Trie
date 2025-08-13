#ifndef TRIE_H__
#define TRIE_H__


#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Trie_node {
    char val;
    bool endWord;
    unordered_map<char, Trie_node*> children;

};

class Trie {

public:

    Trie();
    ~Trie();

    bool insert(string word);

    bool search(string word);

    bool startsWith(string word);

    bool erase(string word);


private:

    Trie_node* root;


};





#endif