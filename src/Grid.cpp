#include "Grid.h"

Grid::Grid(int size) {
    this->size = size;
    letters = new char* [size];
    for (int i = 0; i < size; i++) {
        letters[i] = new char[size];
    }
}

Grid::Grid(const Grid& other)
{
    size = other.size;
    letters = new char* [size];
    for (int i = 0; i < size; ++i) {
        letters[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            letters[i][j] = other.letters[i][j];
        }
    }
}

Grid& Grid::operator=(const Grid& other)
{
    if (this != &other) {
        for (int i = 0; i < size; ++i) {
            delete[] letters[i];
        }
        delete[] letters;

        size = other.size;
        letters = new char* [size];
        for (int i = 0; i < size; ++i) {
            letters[i] = new char[size];
            for (int j = 0; j < size; ++j) {
                letters[i][j] = other.letters[i][j];
            }
        }
    }
    return *this;
}

Grid::~Grid() {
    for (int i = 0; i < size; i++) {
        delete[] letters[i];
    }
    delete[] letters;
}
void Grid::generateRandomGrid() {
    // Use a random device and Mersenne Twister engine for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a uniform distribution for generating random uppercase letters
    std::uniform_int_distribution<int> distribution('A', 'Z');

    // Populate the grid with random uppercase letters
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            letters[row][col] = static_cast<char>(distribution(gen));
        }
    }
}

void Grid::displayGrid() {
    std::cout << "\n===Boggle Game with a "<< size <<"*"<< size << " grid===\n" << std::endl;
    // Display the contents of the grid 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << letters[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "\n=================================\n" << std::endl;
}

void Grid::fillGridWithArray(char** lettersArray, int arraySize) {
    // Seed the random number generator with the current time
    srand(time(0));

    // Check if the lettersArray is empty
    if (lettersArray == nullptr) {
        generateRandomGrid();
    } else {
        // Fill the grid with letters from the provided array or random letters if the array is insufficient
        for (int i = 0; i < size * size; i++) {
            if (i + 1 < arraySize &&  
                ((lettersArray[i + 1][0] >= 'a' && lettersArray[i + 1][0] <= 'z')
                || (lettersArray[i + 1][0] >= 'A' && lettersArray[i + 1][0] <= 'Z'))
            ){
                // Use uppercase version of the letter if it is lowercase
                char currentLetter = lettersArray[i + 1][0];
                letters[i / size][i % size] = (currentLetter >= 'a' && currentLetter <= 'z') ? toupper(currentLetter) : currentLetter;
            }
            else {
                // Generate a random uppercase letter if no letters are provided, or if there are not enough letters provided, or if the provided character is not a letter
                letters[i / size][i % size] = 'A' + rand() % 26;
            }
        }
    }
}



void Grid::findWords(int row, int col, std::string currentWord, std::vector<std::string>& foundWords) {
    // Check if the current position is out of bounds or contains an empty space
    if (row < 0 || col < 0 || row >= size || col >= size || letters[row][col] == ' ')
        return;

    // Add the current letter to the currentWord
    currentWord += letters[row][col];

    // Check if the currentWord has a length greater than 3, and if so, add it to the list of foundWords
    if (currentWord.length() > 3) {
        foundWords.push_back(currentWord);
    }

    // Save the current letter and mark the current position as visited
    char currentLetter = letters[row][col];
    letters[row][col] = ' ';

    // Define the possible offsets for neighboring positions (top, bottom, left, right, and diagonals)
    int rowOffsets[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int colOffsets[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Explore all neighboring positions
    for (int i = 0; i < 8; i++) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];
        findWords(newRow, newCol, currentWord, foundWords);
    }

    // Restore the original letter at the current position after exploring neighbors
    letters[row][col] = currentLetter;
}



void Grid::getAllWordsLongerThan3(std::vector<std::string>& foundWords) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            std::string currentWord = "";
            findWords( row, col, currentWord, foundWords);
        }
    }
}