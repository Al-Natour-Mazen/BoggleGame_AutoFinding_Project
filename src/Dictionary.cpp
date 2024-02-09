#include "Dictionary.h"


Dictionary::Dictionary(const std::string& filename) {
    root = new TrieNode();
    totalWords = 0;
    loadDictionary(filename);
}

Dictionary::Dictionary(const Dictionary& other)
{
    totalWords = other.totalWords;
    root = new TrieNode(*other.root);
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
    if (this != &other) {
        delete root;

        totalWords = other.totalWords;
        root = new TrieNode(*other.root); 
    }
    return *this;
}

Dictionary::~Dictionary()
{
    if (root != nullptr)
    {
        delete root;
        root = nullptr;
    }
}

/*
     Function to insert a word into the trie data structure. It iterates through each character in the provided word,
     checks if the corresponding child node exists in the current trie node, and creates it if it doesn't exist, 
     effectively navigating through the tree structure. Once the loop is finished, the node corresponding to the last 
     character of the word is marked as the end of a valid word, and the total word count is incremented. This allows 
     for the efficient construction of a dictionary of words in a trie structure for fast lookup.
*/
void Dictionary::insertNode(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';  //Only lowercase alphabets.
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
    totalWords++;
}

/*
    Function to load words from a dictionary file.The function opens the specified dictionary file, reads each line, 
    cleans the words by removing non-alphabetic characters and converting them to lowercase, and then inserts these 
    cleaned words into a data structure (likely a trie), measuring the time it takes to load the dictionary and printing 
    the total word count.
*/
void Dictionary::loadDictionary(const std::string& dictionaryFilePath) {
    std::ifstream dictionaryFile(dictionaryFilePath);
    if (!dictionaryFile.is_open()) {
        std::cerr << "Error opening dictionary file" << std::endl;
        return;
    }

    std::string line;
    // Measure the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    while (std::getline(dictionaryFile, line)) {
        // Remove any non-alphabetic characters and convert to lowercase.
        std::string cleanedWord;
        for (char c : line) {
            if (isalpha(c)) {
                cleanedWord += tolower(c);
            }
        }
        if (!cleanedWord.empty()) {
            insertNode(cleanedWord);
        }
    }
    // Measure the end time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << ">> Dictionary loaded in " << duration.count() << " milliseconds, total words: " << totalWords << "." << std::endl;
}


/*
  The function traverses the trie data structure to determine if the input word is present in the dictionary.
  The function starts traversing the trie data structure to check if the input word exists in the dictionary. 
  It does this character by character, where each character in the input word is used to navigate deeper into the trie structure.
  - For each character in the input word, it calculates an index based on the character's position in the alphabet 
   (assuming a lowercase alphabet).
  - It checks if the corresponding child node exists in the current node of the trie. If not, it immediately returns false, 
    indicating that the word is not in the dictionary.

*/
bool Dictionary::isWordInDictionary(const std::string& word)
{
    // Measure the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    // Measure the end time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    return node && node->isEndOfWord; //if the node variable is pointing to a node with isEndOfWord set to true, it means that the word exists in the dictionary.
}