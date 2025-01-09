#include "Carnet.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

#define GREEN "\033[0;32m"
#define BOLDORANGE "\033[1;34m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
using namespace std;


Carnet::Carnet() {}
Carnet::Carnet(string nom, string tel): nom(nom), tel(tel) {}



//méthode qui va permettre d'afficher les informations de l'objet de type Carnet
void Carnet::displaycontact() {
    try
    {
        // Création de la connexion

        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3310", "cpp", "mycpp"));
        //connexion à la bdd
        con->setSchema("cpp");
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM carnet;"));
        
        while(res->next()){
            std::cout << GREEN << "Contact n° " << res->getInt("id") << RESET << std::endl;
            std::cout << "Nom : " << res->getString("nom") << std::endl;
            std::cout << "Téléphone = " << res->getString("tel") << std::endl;
            cout << BOLDORANGE << "----------------" << RESET << endl << endl;
    }

    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur MySQL: " << e.what() << std::endl;
    }
    
}


// méthode qui va permettre d'ajouter un contact
void Carnet::addContact() {
  cout << "Ajouter un contact" << endl;
  cout << "Nom: ";
  cin >> nom;
  cout << "Téléphone: ";
  cin >> tel;
    try{
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3310", "cpp", "mycpp"));
        con->setSchema("cpp");
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        stmt->execute("INSERT INTO carnet(nom, tel) VALUES('"+nom+"', '"+tel+"');");

        std::cout << GREEN << "Contact ajouté avec succès" << RESET << std::endl;
       
    }catch(const std::exception& e)
    {
        std::cerr << "Erreur MySQL: " << e.what() << std::endl;
    }

}

// méthode qui va permettre de rechercher un contact par nom
void Carnet::searchContact() {
    string search;
    cout << "Rechercher un contact par nom" << endl;
    cout << "Nom: ";
    cin >> search;

    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3310", "cpp", "mycpp"));
    con->setSchema("cpp");
    unique_ptr<sql::Statement> stmt(con->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM carnet WHERE nom = '"+search+"';"));
    if(res->rowsCount() == 0){
        cout << RED << "Aucun contact trouvé" << RESET  << endl;
    }else{
        while(res->next()){
            cout << "id : " << res->getInt("id") << endl;
            cout << "Nom : " << res->getString("nom") << endl;
            cout << "Téléphone = " << res->getString("tel") << endl;
        }
    }

}

// méthode qui va permettre de supprimer un contact
void Carnet::deleteContact(){
  cout << "Supprimer un contact" << endl;
  cout << "Nom: ";
  cin >> nom;
  try{

  sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3310", "cpp", "mycpp"));
    con->setSchema("cpp");
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    stmt->execute("DELETE FROM carnet WHERE nom = '"+nom+"';");
    if(stmt->getUpdateCount() == 0){
        std::cout << RED << "Aucun contact trouvé" << RESET << std::endl;
    }else{
        std::cout << BOLDORANGE << "Contact supprimé avec succès" << RESET << std::endl;
    }
    }catch(const std::exception& e)
    {
        std::cerr << "Erreur MySQL: " << e.what() << std::endl;
    }
  
}


  
  



