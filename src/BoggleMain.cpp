#include "BoggleGame.h"

int main(int argc,char* argv[])
{
    std::cout << "\n" <<std::endl;

    const std::string dictionaryFileName = "dico.txt";

    // Check if the dictionary file exists
    if (!std::ifstream(dictionaryFileName)) {
        std::cerr << ">> Error: Dictionary file '" << dictionaryFileName << "' not found.\n" << std::endl;
        return 1;
    }
 
    // Create a BoggleGame with the provided dictionary file name
    BoggleGame game(dictionaryFileName);
    
    // Fill the Boggle grid with letters from the command line arguments
    game.fillGrid(argv, argc);

    // Diisplay the Boggle grid
    //game.displayGridGame();

    // Find and display all words in the Boggle grid
    game.findAllWordsGrid();

    // Find all possible words in the Boggle grid that are in the dictionary
    game.findAllPossibleWords();

    std::cout << "\n" <<std::endl;
}
