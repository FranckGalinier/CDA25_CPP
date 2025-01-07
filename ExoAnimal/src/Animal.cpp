#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

Animal::Animal() : name(""), age(0) {};
Animal::Animal(string name, int age, float weight, string color, string sexe) : name(name), age(age), weight(weight), color(color), sexe(sexe){};
Animal::~Animal(){};

string Animal::getName() const{ return this->name; }
int Animal::getAge() const{ return this->age; }
float Animal::getWeight() const{ return this->weight; }
string Animal::getColor() const{ return this->color; }
string Animal::getSexe() const{ return this->sexe; }

void Animal::setName(string name){ this->name = name; }
void Animal::setAge(int age){ this->age = age; }
void Animal::setWeight(float weight){ this->weight = weight; }
void Animal::setColor(string color){ this->color = color; }
void Animal::setSexe(string sexe){ this->sexe = sexe; }

void Animal::displayInfo() const{
  cout << "Informations de l'animal : " << endl;
  cout << "Nom : " << this->name << endl;
  cout << "Age : " << this->age << endl;
  cout << "Poids : " << this->weight << endl;
  cout << "Couleur : " << this->color << endl;
  cout << "Sexe : " << this->sexe << endl;
  cout << endl;
}
