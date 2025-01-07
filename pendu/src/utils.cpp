#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <sstream>

using namespace std;

std::string getRandomWord(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier");
    }

    std::string line;
    while (std::getline(file, line)) {
        // Optionnel : nettoyage de la ligne
        if (!line.empty()) {
            words.push_back(line);
        }
    }

    if (words.empty()) {
        throw std::runtime_error("Aucun mot trouvé dans le fichier");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);

    return words[dis(gen)];
}


std::string replaceWithUnderscores(const std::string& randomWord){
    std::string wordToGuess;
    for(int i = 0; i < randomWord.size(); i++){
         wordToGuess += "_ ";
    }
    return wordToGuess;
};

bool checkIfLetterIsUsed(char letter, std::string letterUsed){
    
    if(letterUsed.find(letter) != std::string::npos){
    std::cout << "Vous avez déjà utilisé cette lettre" << std::endl;
        return false;
    } else {
        return true;
    }
}

void drawPendu(int score){
    if(score == 7){
        cout << "           " << endl;
        cout << "     |     " << endl;
        cout << "     |     " << endl;
        cout << "           " << endl;
       
    }else if(score == 6){
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "           " << endl;
        
    }else if(score == 5){
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "          " << endl;
    }else if(score == 4){
        cout << "     ______" << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "          " << endl;
    }else if(score == 3){
        cout << "     ______" << endl;
        cout << "     |    |" << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "          " << endl;
    }else if(score == 2){
        cout << "     ______" << endl;
        cout << "     |    |" << endl;
        cout << "     |    O" << endl;
        cout << "     |    " << endl;
        cout << "     |    " << endl;
        cout << "          " << endl;
    }else if(score == 1){
        cout << "     ______" << endl;
        cout << "     |    |" << endl;
        cout << "     |    O" << endl;
        cout << "     |   /|" << endl;
        cout << "     |    " << endl;
        cout << "          " << endl;
    }else if(score == 0){
        cout << "     ______" << endl;
        cout << "     |    |" << endl;
        cout << "     |    O" << endl;
        cout << "     |   /|\\" << endl;
        cout << "     |    |" << endl;
        cout << "         / \\" << endl;
    }
}