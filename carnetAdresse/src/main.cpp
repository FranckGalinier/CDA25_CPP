#include <vector>
#include <string>
#include <fstream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>
#include "Carnet.h"

#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

using namespace std;

  
int main() {

  try
  {
    // Création de la connexion
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3310", "cpp", "mycpp"));

    //connexion à la bdd
    con->setSchema("cpp");

    //création de la table
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    stmt->execute("CREATE TABLE IF NOT EXISTS carnet("
                    "id INT PRIMARY KEY AUTO_INCREMENT,"
                    "nom VARCHAR(50) NOT NULL,"
                    "tel VARCHAR(50) NOT NULL"
                    ");");
  }

  catch(sql::SQLException &e)
  {
    std::cerr << "Erreur MySQL: " << e.what() << std::endl;

  }

  int choix;
  Carnet carnet;
  do{
  cout << MAGENTA << " Bienvenue dans votre carnet d'adresses !" << RESET << endl;
  cout << " 1. Ajouter un contact" << endl;
  cout << " 2. Afficher tous les contacts" << endl;
  cout << " 3. Rechercher un contact par nom " << endl;
  cout << " 4. Supprimer un contact " << endl;
  cout << " 5 Quitter " << endl;
  cin >> choix;

  switch(choix){
    case 1:
      carnet.addContact();
      break;
    case 2:
      carnet.displaycontact();
      break;
    case 3:
       carnet.searchContact();
      break;
    case 4:
      carnet.deleteContact();
      break;
    case 5:
      cout << "Merci et à la prochaine ;) !" << endl;
      break;
    default:
      cout << "Choix invalide" << endl;
  }

  }while(choix != 5);



  return 0;
}