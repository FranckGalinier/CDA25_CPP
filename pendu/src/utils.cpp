#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <sstream>

std::string getRandomWord(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    std::string line;

    // Lire le fichier ligne par ligne
    while (std::getline(file, line)) {
        // Chercher la clé "words" et extraire les mots
        if (line.find("\"words\":") != std::string::npos) {
            // Extraire la ligne contenant les mots
            while (std::getline(file, line) && line.find("]") == std::string::npos) {
                // Enlever les espaces et les guillemets
                line.erase(remove(line.begin(), line.end(), ' '), line.end());
                line.erase(remove(line.begin(), line.end(), '\"'), line.end());
                
                // Séparer les mots par des virgules
                std::istringstream ss(line);
                std::string word;
                while (std::getline(ss, word, ',')) {
                    if (!word.empty()) {
                        words.push_back(word);
                    }
                }
            }
            break; // On sort de la boucle après avoir trouvé les mots
        }
    }

    // Vérifier si des mots ont été lus
    if (words.empty()) {
        throw std::runtime_error("Aucun mot trouvé dans le fichier");
    }

    // Générer un index aléatoire
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);

    // Retourner un mot aléatoire
    return words[dis(gen)];
}
