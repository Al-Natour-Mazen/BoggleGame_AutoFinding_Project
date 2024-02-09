
#include "TrieNode.h"

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
    isEndOfWord = false;
}

TrieNode::TrieNode(const TrieNode& other)
{
    isEndOfWord = other.isEndOfWord;
    for (int i = 0; i < 26; ++i) {
        if (other.children[i] != nullptr) {
            children[i] = new TrieNode(*other.children[i]);
        }
        else {
            children[i] = nullptr;
        }
    }
}

TrieNode& TrieNode::operator=(const TrieNode& other)
{
    if (this != &other) {
        for (int i = 0; i < 26; ++i) {
            delete children[i];
        }

        isEndOfWord = other.isEndOfWord;
        for (int i = 0; i < 26; ++i) {
            if (other.children[i] != nullptr) {
                children[i] = new TrieNode(*other.children[i]);
            }
            else {
                children[i] = nullptr;
            }
        }
    }
    return *this;
}

TrieNode::~TrieNode()
{
    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            delete children[i];
            children[i] = nullptr;
        }
    }
}
