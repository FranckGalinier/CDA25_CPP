#include <iostream> 

using namespace std;

int main() {
    // Les variables
    int age = 26;
    float pi= 3.14;
    double e = 2.71;
    char letter = 'A';
    bool isAdult = true;

    letter = 'B';

//    constante
    const double GRAVITY = 9.81;

    // GRAVITY = 10.0; mettrait en erreur la compilation car constante
        // cout << "Gravity is " << GRAVITY << endl;
    // int a,b;
    // a = 5;
    // b = 2;

    // int somme = a + b;
    // float division = a / b;
    // int multiplication = a * b;
    // int soustraction = a - b;
    // float modulo = a % b;

    // cout << "La somme de a et b est " << somme << endl;
    // cout << "La division de a et b est " << division << endl;
    // cout << "La multiplication de a et b est " << multiplication << endl;
    // cout << "La soustraction de a et b est " << soustraction << endl;
    // cout << "Le modulo de a et b est " << modulo << endl;

    // && || !(nonlogique)
    // bool res = (a > b) && (a > b);

    // cout << "Le resultat est " << res << endl;
int number;
cout << "choisir entre 1.prenom 2.for" << endl;
cin >> number;

switch(number){ 
    case '1':

        cout << "Bonjour, veuillez entrer votre nom et prenom" << endl;
        string nom;
        getline(cin, nom);

        cout << "Entrez votre age" << endl;
        int ageUser;
        cin >> ageUser;
        cout << "Bonjour " << nom << endl;
        if (ageUser > 18){
            cout << "Tu as " << ageUser << " ans. Tu es majeur !" << endl;
        } else if (ageUser < 18){
            cout << "Tu as " << ageUser << " ans. Tu es mineur !" << endl;
        } else {
            cout << "Erreur !!" << endl;
        }
    
        char grade;
        cout << "Entrez votre note" << endl;
        cin >> grade;

        switch(grade){
            case 'A':
                cout << "Excellent" << endl;
                break;
            case 'B':
                cout << "Bien" << endl;
                break;
            case 'C':
                cout << "Passable" << endl;
                break;
            case 'D':
                cout << "Mauvais" << endl;
                break;
            default:
                cout << "Note invalide" << endl;
        }
        break;

    case '2':


        for(int i = 0; i>10; i++){
        cout << "La valeur de i est " << i << endl;

        };
    break;

    default:
    cout << "Choix invalide" << endl;



}

    return 0;

}