#pragma once
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <random>

class Grid {
private:
    char** letters;
    int size;
    void findWords(int row, int col, std::string currentWord, std::vector<std::string>& foundWords);
public:
    Grid(int size);
    Grid(const Grid& other);
    Grid& operator=(const Grid& other);
    ~Grid();
    void generateRandomGrid();
    void displayGrid();
    void fillGridWithArray(char** lettersArray, int arraySize);
    void getAllWordsLongerThan3(std::vector<std::string>& foundWords);
};

