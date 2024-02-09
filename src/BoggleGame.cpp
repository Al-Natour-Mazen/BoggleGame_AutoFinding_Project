#include "BoggleGame.h"

BoggleGame::BoggleGame(const std::string& dictionaryFileName, int gridSize) : grid(gridSize), dictionary(dictionaryFileName) {}

void BoggleGame::displayGridGame() {
    // Display the current state of the Boggle grid
    grid.displayGrid();
}

void BoggleGame::findAllWordsGrid() {
    // Measure the start time
    auto start = std::chrono::high_resolution_clock::now();

    // Find all words in the Boggle grid longer than 3 characters
    grid.getAllWordsLongerThan3(allWordsInGrid);

    // Measure the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the execution duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\n>> Time to find all words : " << duration.count() << " milliseconds." << std::endl;
}

void BoggleGame::findAllPossibleWords() {
    // Measure the start time
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> wordsInDictionary;

    // Iterate through all words found in the grid
    for (const std::string& word : allWordsInGrid) {
        // Convert the word to lowercase
        std::string lowercaseWord = word;
        for (char& c : lowercaseWord) {
            c = std::tolower(c);
        }

        // Check if the lowercase word is in the dictionary and add it to the list
        if (dictionary.isWordInDictionary(lowercaseWord)) {
            if (std::find(wordsInDictionary.begin(), wordsInDictionary.end(), word) == wordsInDictionary.end()) {
                wordsInDictionary.push_back(word);
            }
        }
    }

    // Measure the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the execution duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\n>> Time to find all possible words : " << duration.count() << " milliseconds." << std::endl;

    // Write the found words to file
    std::ofstream outFile("possibleWords.txt");
    if (!wordsInDictionary.empty()) {
        outFile << "Words of length greater than 3 in the grid which are in the dictionary : " << std::endl;
        for (const std::string& word : wordsInDictionary) {
            outFile << word << " \n";
        }
    } else {
        outFile << "Sorry, no words were found that are possible in the dictionary. :(" << std::endl;
    }
    outFile.close();
}

void BoggleGame::fillGrid(char** lettArray, int arrSize) {
    // Fill the Boggle grid with letters from the provided array
    grid.fillGridWithArray(lettArray, arrSize);
}
