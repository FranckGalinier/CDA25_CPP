#include "Dog.h"
#include <iostream>
#include <string>

using namespace std;

Dog::Dog() : Animal(), breed("") {};
Dog::Dog(string name, int age, float weight, string color, string sexe, string breed) : Animal(name, age, weight, color, sexe), breed(breed) {};
Dog::~Dog(){};

string Dog::getBreed() const{ return this->breed; }

void Dog::setBreed(string breed){ this->breed = breed; }

void Dog::displayInfo() const{
  cout << "Informations du chien : " << endl;
  cout << "Nom : " << this->getName() << " | Age : " << this->getAge() << endl;
  cout << "Race : " << this->breed << endl;
  cout << endl;
}