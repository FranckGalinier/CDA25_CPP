#include <iostream> 

using namespace std;

void increment(int* a){
    (*a)++;
    cout << "Le résultat " << a << endl;
}

int main() {
    int x;
    cout << "Entrez un nombre : ";
    cin >> x;

    increment(&x);
    cout << " Après l'appel la valeur est de " << x << endl; 

    return 0;
}