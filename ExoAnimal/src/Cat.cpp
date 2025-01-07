#include "Cat.h"
#include <iostream>
#include <string>

using namespace std;

Cat::Cat() : Animal(), nbrOfLives(0) {};
Cat::Cat(string name, int age, float weight, string color, string sexe, int nbrOfLives) : Animal(name, age, weight, color, sexe), nbrOfLives(nbrOfLives) {};
Cat::~Cat(){};

int Cat::getNbrOfLives() const{ return this->nbrOfLives; }

void Cat::setNbrOfLives(int nbrOfLives){ this->nbrOfLives = nbrOfLives; }

void Cat::displayInfo() const{
  cout << "Informations du chat : " << endl;
  cout << "Nom : " << this->getName() << " | Age : " << this->getAge() << endl;
  cout << "Nombre de vies : " << this->nbrOfLives << endl;
  cout << endl;
}