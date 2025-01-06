#include <iostream> 

using namespace std;

int main() {

    string nom; //Déclaration de la variable nom

    cout << "Quel est votre nom ?" << endl; //Affichage de la question
    cin >> nom; //Récupération de la réponse

    cout << "Bonjour " << nom << " !" << endl; //Affichage du message de bienvenue

    return 0;

}