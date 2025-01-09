#ifndef CARNET_H
#define CARNET_H

#include <vector>
#include <string>


using namespace std;

struct Carnet {
  string nom;
  string tel;

  Carnet();
  Carnet(string nom, string tel);
 
  void displaycontact();
  void addContact();
  void searchContact();
  void deleteContact();

};

#endif