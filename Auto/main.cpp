#include <iostream>
#define CYAN "\033[0;36m"
#define RESET  "\033[0m"

using namespace std;

int main()
{
  cout << CYAN << "Bonjour, Vous avez décider de travailler." << endl << "Tapez 1: créer un nouveau projet ou Tapez 2: Ouvrir un projet existant" << RESET << endl;
  int choix;
  cin >> choix;

  switch(choix){
    case 1:
      cout << "Vous avez choisi de créer un nouveau projet" << endl;
      break;
    case 2:
      cout << "Vous avez choisi d'ouvrir un projet existant" << endl;
      break;
    default:
      cout << "Choix invalide" << endl;
      break;
  }

  return 0;
}
