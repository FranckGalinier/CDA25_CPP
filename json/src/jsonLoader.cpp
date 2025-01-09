#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

struct Car {
  string brand;
  string model;

  Car(): brand(""), model("") {};
  Car(string brand, string model): brand(brand), model(model) {};

//méthode qui va permettre de convertir un objet json en objet de type Car
  void jsonToStruct(const json& j){
    brand = j["marque"];
    model = j["model"];
  }

//méthode qui va permettre d'afficher les informations de l'objet de type Car
  void afficher() const {
    cout << "Marque : " << brand << endl;
    cout << "Modèle : " << model << endl << endl;
  }

//méthode qui va permettre de convertir un objet de type Car en objet json
  void addJsonArray(json& jsonArray) const {
    json voitureJson = {
      {"marque", brand},
      {"model", model}
    };
    jsonArray.push_back(voitureJson);
  }

};

int main(){

  vector<Car> Voiture;

  ifstream file("/home/FP_ERN_DEV/dev/CDA25_CPP/json/src/db.json");
  if(!file.is_open()){
    cerr << "Error opening file" << endl;
    return 1;
  }


  json jsonData;
  file >> jsonData;

  auto cars = jsonData;


  Car vv("Renault", "Clio");
  vv.addJsonArray(cars);

  

  for(const auto& car : cars){
    // cout << "Marque :" << car["marque"]<<  endl;
    // cout << "Modèle : " << car["model"] << endl <<endl;
    Car c;
    c.jsonToStruct(car);
    Voiture.push_back(c);

  }

  for(const auto& bagnole : Voiture){
    bagnole.afficher();
  }
  return 0;
}