#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;

int main(){

  vector <Animal> animals;

  Animal a1;
  a1.setName("Rex");
  a1.setAge(5);
  a1.setWeight(25.5);
  a1.setColor("Noir");
  a1.setSexe("M");

  Dog d1("Oslo", 3, 50.5, "blanc","M", "BoullMastiff Anglais");
  d1.displayInfo();

  Cat c1("Mistigri", 2, 10.5, "noir", "F", 9);
  c1.displayInfo();


  animals.push_back(a1);
  animals.push_back(d1);
  animals.push_back(c1);

  cout << "Liste des animaux : " << endl;

  for (const auto &an : animals){
    an.displayInfo();
    cout << endl;
  }
}
