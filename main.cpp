#include <iostream>
#include "Trie.h"
using namespace std;
int main() {

    Trie t;

    // insert first trie
    cout << "inserting hello, help, apple, ape" << endl;
    t.insert("hello");
    t.insert("help");
    t.insert("apple");
    t.insert("ape");

    cout << boolalpha;

    // search
    cout << "\nsearching apple: " << t.search("apple") << endl;
    cout << "searching world: " << t.search("world") << endl;

    // startsWith
    cout << "\nstarts with 'ap': " << t.startsWith("ap") << endl;
    cout << "starts with 'hel': " << t.startsWith("hel") << endl;
    cout << "starts with 'xyz': " << t.startsWith("xyz") << endl;

    // erase
    cout << "\nremoving apple + ape" << endl;
    t.erase("apple");
    t.erase("ape");


    // testing erase node pruning
    cout << "searching apple: " << t.search("apple") << endl;
    cout << "starts with 'ap': " << t.startsWith("ap") << endl;


    Trie t2;

    // insert new trie
    cout << "\ninserting apple,ape,appendix to new Trie" << endl;
    t2.insert("apple");
    t2.insert("ape");
    t2.insert("appendix");

    // lCP

    cout << "Longest Common Prefix in new Trie : " << t2.longestCommonPrefix() << endl;





    return 0;
}