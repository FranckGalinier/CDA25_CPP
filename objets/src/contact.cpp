#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Etudiant.h"

using namespace std;

int main() {
  
  vector <Person> carnet;

  Person p1;
  p1.setFirstname("Doe");
  p1.setLastname("John");
  p1.setEmail("doe.john@www.fr");
  p1.setAge(25);
  
  carnet.push_back(p1);

  Person p2("Doe", "Jane", "doe.jane@www.fr", 22);

  Etudiant e1("Bac+3", "Université de Paris");
  e1.setFirstname("Galinier");
  e1.setLastname("Franck");
  e1.setEmail("admin@admin.com");
  e1.setAge(26);
  
  Etudiant e2("Bac+5", "Université de Paris", "Hanakhin", "My friend", "admin@admin.com", 25);
  e2.toString();
  carnet.push_back(p2);
  carnet.push_back(e1);
  carnet.push_back(e2);

  for (const auto &pers : carnet){
    pers.displayInfo();
    cout << endl;
  }


  return 0;
}