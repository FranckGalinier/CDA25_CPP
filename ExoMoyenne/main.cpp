#include <iostream>
#include <vector>
#include <iomanip> 
#include "math_utils.h"

using namespace std;


int main(){

  vector<float> notes; 
  int option;
  cout << "Calcul de moyenne" << endl;

  do{ 
    float note;

    do{
    cout << "Entrez une note (entre 0 et 20) : " << endl;
    cin >> note;
    if (note <= 0 || note > 20) {//si la note est inférieur ou égale à 0 ou supérieur à 20
        cout << "Erreur : Veuillez entrer une note entre 0 et 20." << endl;//affiche le message d'erreur
        cin.clear(); // Réinitialise l'état de cin
    }
    }while(note <= 0 || note > 20);//tant que la note est inférieur ou égale à 0 ou supérieur à 20
    notes.push_back(note);//ajoute la note à la fin du vecteur notes


    do{
    cout << "Voulez-vous entrer une autre note ? (1: oui, 0: non)" << endl;
    cin >> option;
    if (option != 0 && option != 1) {
        cout << "Erreur : Veuillez entrer 0 ou 1." << endl;
        cin.clear(); // Réinitialise l'état de cin
    }
    }while(option != 0 && option != 1);
    
  }while(option == 1);

  float moyenne = calculMoyenne(notes);

  cout << "Vous avez " << notes.size() << " notes et votre moyenne est de " << setprecision(4) << moyenne << "/20" << endl;

  

  if(moyenne < 10){
    cout << "Vous êtes recalé." << endl;
  }else if(moyenne < 12){
    cout << "Vous êtes reçu." << endl;
  }else if(moyenne < 14){
    cout << "Vous êtes reçu avec mention assez bien." << endl;
  }else if(moyenne < 16){
    cout << "Vous êtes reçu avec mention bien." << endl;
  }else if(moyenne < 18){
    cout << "Vous êtes reçu avec mention très bien." << endl;
  }else{
    cout << "Vous êtes reçu avec mention excellente." << endl;
  }
  return 0;

}