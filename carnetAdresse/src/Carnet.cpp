#include "Carnet.h"
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#define GREEN "\033[0;32m"
#define BOLDORANGE "\033[1;34m"
#define RESET "\033[0m"
using namespace std;
using json = nlohmann::json;

Carnet::Carnet() {}
Carnet::Carnet(string nom, string tel): nom(nom), tel(tel) {}

//méthode qui va permettre de convertir un objet json en objet de type Carnet
void Carnet::jsonToStruct(const json& j) {
    nom = j["nom"];
    tel = j["tel"];
    // Ajoutez d'autres champs si nécessaire
}

//méthode qui va permettre d'afficher les informations de l'objet de type Carnet
void Carnet::displaycontact() {
    ifstream file("/home/FP_ERN_DEV/dev/CDA25_CPP/carnetAdresse/src/db.json");
    if(file) {
        json j;
        file >> j;
        file.close();

        for (const auto& contact : j) {
            Carnet c;
            c.jsonToStruct(contact);
            cout << GREEN << "Contact:" << RESET << endl;
            cout << "Nom: " << c.nom << endl;
            cout << "Téléphone: " << c.tel << endl;
            cout << BOLDORANGE << "------------------------" << RESET << endl;
        }
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
}

// méthode qui va permettre de convertir un objet de type Carnet en objet json
void Carnet::addJsonArray(json& jsonArray) const {
    json contact = {
        {"nom", nom},
        {"tel", tel}
    };
    jsonArray.push_back(contact);
}

// méthode qui va permettre d'ajouter un contact
void Carnet::addContact() {
  cout << "Ajouter un contact" << endl;
  cout << "Nom: ";
  cin >> nom;
  cout << "Téléphone: ";
  cin >> tel;

  json j;
  ifstream file("/home/FP_ERN_DEV/dev/CDA25_CPP/carnetAdresse/src/db.json");
  if(file) {
    file >> j;
    file.close();
  }

  addJsonArray(j);

  ofstream oFile("/home/FP_ERN_DEV/dev/CDA25_CPP/carnetAdresse/src/db.json");
  oFile << j;
  oFile.close();
  cout << "Contact ajouté avec succès" << endl;


}

// méthode qui va permettre de rechercher un contact par nom
void Carnet::searchContact() {
    string search;
    cout << "Rechercher un contact par nom" << endl;
    cout << "Nom: ";
    cin >> search;

    ifstream file("/home/FP_ERN_DEV/dev/CDA25_CPP/carnetAdresse/src/db.json");
    if(file) {
        json j;
        file >> j;
        file.close();

        for (const auto& contact : j) {
            Carnet c;
            c.jsonToStruct(contact);
            if (c.nom == search) {
                cout << GREEN << "Contact:" << RESET << endl;
                cout << "Nom: " << c.nom << endl;
                cout << "Téléphone: " << c.tel << endl;
                cout << BOLDORANGE << "------------------------" << RESET << endl;
                return;
            }
        }
        cout << "Contact introuvable" << endl;
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
}

// méthode qui va permettre de supprimer un contact
void Carnet::deleteContact(){
  cout << "Supprimer un contact" << endl;
  cout << "Nom: ";
  cin >> nom;
  ifstream file("/home/FP_ERN_DEV/dev/CDA25_CPP/carnetAdresse/src/db.json");
    if(file) {
        json j;
        file >> j;
        file.close();

        for (auto it = j.begin(); it != j.end(); ++it) {
            Carnet c;
            c.jsonToStruct(*it);
            if (c.nom == nom) {
                j.erase(it);
                ofstream oFile("/home/FP_ERN_DEV/dev/CDA25_CPP/carnetAdresse/src/db.json");
                oFile << j;
                oFile.close();
                cout << "Contact supprimé avec succès" << endl;
                return;
            }
        }
        cout << "Contact introuvable" << endl;
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
}


  
  



