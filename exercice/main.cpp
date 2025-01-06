#include <iostream>
#include <sstream>//convertir un string en int

using namespace std;

int main(){

    cout << "Bienvenue dans la calculatrice simple !" << endl;

    int a, b;
    char op;
   
    
        cout << "Entrez un premier nombre : ";
        cin >> a;
    do{
        cout << "Entrez un opérateur (+, -, *, /) : ";
        cin >> op;
    }while(
        op != '+' && op != '-' && op != '*' && op != '/');

    cout << "Entrez un deuxième nombre : ";
    cin >> b;

    cout << "Le résultat de " << a << op << b << " est : ";
    switch (op)
    {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break; 
        case '*':
            cout << a * b << endl;
            break;
        case '/':
        if(b == 0){
            cout << "Division par zéro impossible" << endl;
            break;
        }
            cout << a / b << endl;
            break;
        default:
            cout << "Opérateur invalide" << endl;
            break;
    }
    
   

    return 0;
}