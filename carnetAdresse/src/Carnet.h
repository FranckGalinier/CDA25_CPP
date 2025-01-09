#ifndef CARNET_H
#define CARNET_H

#include <vector>
#include "json.hpp"


using json = nlohmann::json;
using namespace std;

struct Carnet {
  string nom;
  string tel;

  Carnet();
  Carnet(string nom, string tel);
 
  void displaycontact();
  void jsonToStruct(const json& j);
  void addJsonArray(json& jsonArray) const;
  void addContact();
  void searchContact();
  void deleteContact();

};

#endif