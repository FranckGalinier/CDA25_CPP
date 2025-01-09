#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Carnet.h"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

using namespace std;


int main() {

  int choix;
  Carnet carnet;
  do{
  cout << MAGENTA << " Bienvenue dans votre carnet d'adresses !" << RESET << endl;
  cout << " 1. Ajouter un contact" << endl;
  cout << " 2. Afficher tous les contacts" << endl;
  cout << " 3. Rechercher un contact par nom " << endl;
  cout << " 4. Supprimer un contact " << endl;
  cout << " 5 Quitter " << endl;
  cin >> choix;

  switch(choix){
    case 1:
      carnet.addContact();
      break;
    case 2:
      carnet.displaycontact();
      break;
    case 3:
       carnet.searchContact();
      break;
    case 4:
      carnet.deleteContact();
      break;
    case 5:
      cout << "Merci et à la prochaine ;) !" << endl;
      break;
    default:
      cout << "Choix invalide" << endl;
  }

  }while(choix != 5);



  return 0;
}