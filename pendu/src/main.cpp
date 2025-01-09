#include <iostream>
#include <fstream>
#include <random>
#include <utils.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

using namespace std;

int main() {
    cout << "Bienvenue dans le jeu du pendu !" << endl;

    // get the random word from the file
    string randomWord = getRandomWord("/home/FP_ERN_DEV/dev/CDA25_CPP/pendu/src/words.txt");
    
    // Replace the word with underscores
    string wordToGuess = replaceWithUnderscores(randomWord);
    cout << "Mots à deviner : " << wordToGuess << endl;

    int score = 7; // number of tries
    string letterUsed; // letters already used in the game

    while (score > 0){//while score >= 0
        drawPendu(score);
        cout << "Vous avez " << score << " essais" << endl;

        char letter;//letter enter by the user
        bool isLetterUsed = false;//if the letter is already used (false) if not use (true)

        while(!isLetterUsed){
            cout << "Entrez une seule lettre : ";
            cin >> letter;
            letter = toupper(letter);//convert the letter to uppercase
            isLetterUsed = checkIfLetterIsUsed(letter, letterUsed);
        }

        letterUsed.push_back(letter) ;//push the letter in the letterUsed
        letterUsed.push_back(' ');//Push a space after the letter

        // Check if the letter is in the word
        if(randomWord.find(letter) != string::npos){
            cout << GREEN << "La lettre est présente" << RESET << endl;

            // Replace the underscore with the letter
            for(int i = 0; i < randomWord.size(); i++){
                if(randomWord[i] == letter){
                    wordToGuess[i * 2] = letter;
                }
            }
            
        } else {
            cout << RED << "La lettre n'est pas présente" << RESET << endl;
            score--;
        }
        
        cout << wordToGuess << endl;
        cout << "Lettres utilisées : " << letterUsed << endl;

        if(wordToGuess.find("_") == string::npos){
            cout << GREEN << "Bravo ! Vous avez trouvé le mot !" << RESET << endl;
            break;
        }
    } 
    cout << "Le mot était : " << randomWord << endl;
    cout << "Fin du jeu !" << endl;

    return 0;
}