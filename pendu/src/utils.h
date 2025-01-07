#ifndef UTILS_H//si il n'est pas défini
#define UTILS_H//on le défini

#include <string>

std::string getRandomWord(const std::string& filename);
std::string replaceWithUnderscores(const std::string& randomWord);
bool checkIfLetterIsUsed(char letter, std::string letterUsed);
void drawPendu(int score);
#endif