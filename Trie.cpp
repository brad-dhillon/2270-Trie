#include "Trie.h"

Trie::Trie() {
    root = new Trie_node;       // create root node
}
Trie::~Trie(){
    clear(root);               // removed all nodes from heap
}

bool Trie::insert(string word){
Trie_node* cursor = root;       //begin at root

for ( char c : word){          // loop through all characters
    if (cursor->children.find(c) == cursor->children.end()) {
        cursor->children[c] = new Trie_node;      // create child if not present
    }
    cursor = cursor->children[c];  // move down one level
    
}
cursor->endWord = true;          //mark end of work

    return  true;
}

bool Trie::search(string word){
    Trie_node* node = findNode(word);          // find node for last char in word

    if (node == nullptr){               // if nullptr it doesnt exist
        return false;
    }

    if (node->endWord == true){             // if it is the end of a word retrun true
        return true;
    }
    return false;


}

bool Trie::startsWith(string word){
    Trie_node* node = findNode(word);        //find node for last charactr in prefix
    if (node != nullptr){                     // if its not nullptr return true
        return true;
    }
    return false;

}

void Trie::erase(string word){
    

    if (!word.empty()){              //if its an empty word do nothing
        erase(root, word, 0);
    }

}


bool Trie::erase(Trie_node* currentNode, string word, int depth){

    if (currentNode == nullptr){        // if you reach a empty branch
        return false;
    }

    if (depth == word.length()){          //if you reach the last character of a key
        if (currentNode->endWord){
            currentNode->endWord = false;                 // mark word not end of word
            return currentNode->children.empty();        // true if node is deleteable
        }
        return false;

    }

    char c = word[depth];            // current character
    if (currentNode->children.find(c) == currentNode->children.end()){

        return false;           //no path
    }

    bool shouldDeleteChild = erase(currentNode->children[c], word, depth +1);

    if (shouldDeleteChild){       //if child node becomes empty from erase()
        delete currentNode->children[c];    //remove it from heap
        currentNode->children.erase(c);      // remove n ode from map
        return !currentNode->endWord && currentNode->children.empty();
    }                      // node can be deleted if not the end of a word and has no other children

    return false;

}


Trie_node* Trie::findNode(string word){
    Trie_node* cursor = root;     // start at root

    for (char c : word){
        if (cursor->children.find(c) == cursor->children.end()) {
        return nullptr;     // if path breaks down return null
        }

        cursor =cursor->children[c];  // move down
    }

    return cursor;
    
}

void Trie::clear(Trie_node* node){
    if (node == nullptr){  // no path case
        return;
    }

    for (auto pair : node->children){  //loop through all branches
        clear(pair.second);    //recurse down the tree
    }
    delete node;                // free memory

}

string Trie::longestCommonPrefix(){

    string pre;      // emptry string to collect letters of prefix
    Trie_node* cursor = root;    // start at root
    while (cursor){
        if (cursor->endWord){    // stop if wordEnd detected
            break;
        }
        if (cursor->children.size() != 1){     //stop if you find any branches
            break;
        }
        auto iter = cursor->children.begin();  // make child an iterator
        pre.push_back(iter->first);       // add iterator key to prefix string
        cursor = iter->second;     // move down the tree
    }
    return pre;     //return the collected prefix


}