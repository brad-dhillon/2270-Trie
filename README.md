# 2270-Trie

Walkthrough Part 1: Using the Trie class

To use the Trie class you need to first initialize a Trie object and then perform actions on it with the public function. I tried to follow OOP guidelines here so you can only access the functions you absolutely need to the rest hidden as private class data members/functions. 

To insert a word into the Trie you need to simply call the insert() function with your string as an argument. To find if a word is in the Trie you call the search() function with the string as an argument and it will return true if it is there, and flase otherwise. To find if a prefix is in the Trie you call the startsWith() function with the prefix as an argument and it will return true if it is there, and flase otherwise. To remove a word form the Trie all you need to do is call the erase() function with your word as an argument.

To find out what the longest prefix shared by all words in the trie is, you simpyl need to call the longestCommonPrefix method on the Trie object and It will return the string of the longest common prefix or an empty string if there is not shared prefix.

To see these in action please run main.ccp


Walkthrough Part 2: Anatomy of Trie class

Inside the Trie header file but outside the class itself is the Trie_node struct. These nodes have data members endWord that is a bool, and children that is a unordered_map<char, Trie_node*>.

The first public function is the constructor which creates the object and initializes a pointer to a new Trie_node on the heap and sets this equal to root. 

Next the destructor which goes calls clear (private function) which deleted all pointers in use in the tree.

The insert function goes through the characters in the word to be inserted. This char is used as a key to find the node pointer for that letter in the Trie. Then that node is searched for the next character, if it doesn't exist it is created, the cursor then points to the next node. After the last character, the current cursor node has its endWord bool set to true. In this way words can be inserted twice and it will not affect the tree. 

The search function uses the findNode (private) function to find the node that is the final character in the string, if it is null it does not exist in the Trie.

The startsWith uses the findNode (private) function to find the node that is the final character in the supplied prefix. 

The longest common prefix is a solution to the leetcode question by the same name. It will return the longest common prefix shared by all strings in the Trie. It starts with an empty string, and a cursor Trie_node pointer that points to the root. A while loop starts on the condition that the cursor is not equal to nullptr. If the cursor node has the endWord bool equal to true, or the cursor’s children map is not of size 1, the loop breaks. Next an iterator pointer is stored as a variable. The first data field of the iterator (the key) is appended to the empty string. The second data field of the iterator (value) is set to the cursor. Once this loop breaks the prefix string had been constructed and is returned (if there is no LCP the string is empty).

In the private section there is a data member root that is a Trie_node pointer that points to the top of the Trie. 

The findNode function which sets a cursor Trie_node pointer to the root, and loops through every char in the supplied string. If the current char is not in the children map of the cursor node a nullptr is returned. If it is found the pointer corresponding to that key is made the next cursor and the loop continues. If the loop is completed without returning nullptr, the cursor is returned.

The clear function starts at a given node and recursively loops through every member of that node's children map, and calls itself on them. Once the loop has been run the node it was called on is deleted.

The erase function is overloaded with a public and a private version. The public one just takes a string as an argument. It checks if the string is empty, and if not it calls the private one with the root pointer, the string it was give, and 0 for depthThe private one takes, a Trie_node pointer, a string, and a int depth. The function recursively walks down the Trie using depth to pic the next character. At the end of the word it flips endWord and returns true if that node has no children. When coming back of if a child became empty it deleted that child, removes it from children, and returns whether the current node is now empty and not the end of a word.

Errors and reflection:

Once challenge I had while doing this project was building the whole achitechure of the class file and header file for myself. Up to this point in the semester we have had to work with classes but their skeletons were completed, and the furthest I had to go was to add a private helper function or data member. For a student taking this class next semester I would say they should study this more on their own time before the final project so that they may be able to build out a program like this more fluidly!

One thing I had to debug was the erase pruning function. Initially I was only declared the last letter in an erased word not to the be the end of the word. This would leave many branches that did not contain words still on the heap. To fix this I made a public and private version of erase. On just took a string the other took a Trie_node, and int, and a string. The thing I had to debug was getting the function to come back up the Trie deleting nodes without deleting ones that still had children. It was an easy solution but it took me a long time to fully fix.

A mistake I made was placing both of the erase functions in the private delcarion fo the class. I had assumed this because The recursive erase would take a pointer as an argument and I did not want this exposed to the user, but if it was private it would not be useful to the user. In the end I found out you could have one version of an overloaded function as private and one as public.
