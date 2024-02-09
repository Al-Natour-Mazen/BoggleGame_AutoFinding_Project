#pragma once
class TrieNode
{
private:
    TrieNode* children[26]; // It is an array of pointers to TrieNodes. This array is intended to represent the children of 
                            //  this trie node. The 26 locations on the board correspond to the 26 letters of the alphabet. 
                            // Each element in the array represents a link to a node associated with a specific letter.
    bool isEndOfWord;
public:
    TrieNode();
    TrieNode(const TrieNode& other);
    TrieNode& operator=(const TrieNode& other);
    ~TrieNode();
    friend class Dictionary;
};

