#include <iostream>
#include <fstream>
#include <random>

#include <utils.h>

using namespace std;

int main() {
    cout << "Bienvue dans le jeu du pendu !" << endl;

    try {
        string randomWord = getRandomWord("words.json");
        cout << "Mot choisi : " << randomWord << std::endl;
    } catch (const std::exception& e) {
        cerr << "Erreur : " << e.what() << std::endl;
    }
    

    //Affichage du mot à deviner
    return 0;
}