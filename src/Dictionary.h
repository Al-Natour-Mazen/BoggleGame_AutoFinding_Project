#pragma once
#include <fstream>
#include <iostream>
#include <chrono>
#include <string>
#include "TrieNode.h"

class Dictionary
{
private:
    TrieNode* root;
    int totalWords;
public:
    Dictionary(const std::string& dictionaryFilePath);
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);
     ~Dictionary();
    void insertNode(const std::string& word);
    void loadDictionary(const std::string& dictionaryFilePath);
    bool isWordInDictionary(const std::string& word);
};

