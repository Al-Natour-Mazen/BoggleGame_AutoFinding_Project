#pragma once
#include "Grid.h"
#include "Dictionary.h"
#include <algorithm>


class BoggleGame
{
private:
	Grid grid;
	Dictionary dictionary;
	std::vector<std::string> allWordsInGrid;
public:
	BoggleGame(const std::string& dictionaryFileName, int gridSize = 4);
	void displayGridGame();
	void findAllWordsGrid();
	void findAllPossibleWords();
	void fillGrid(char** lettersArray, int arraySize);
};

