#include <iostream>
#include <sqlite3.h>

#define BLUE "\033[0;34m"
#define RESET "\033[0m"

using namespace std;


int main() {
  sqlite3* db;

  char* errmsg = nullptr;

  int exit = sqlite3_open("test.db", &db);//ouverture de la base de données

  if(exit != SQLITE_OK){ //si l'ouverture de la base de données échoue
    cerr << "Erreur SQL => " << sqlite3_errmsg(db) << endl;
    return -1;
  }else{
    cout << "Base de données ouverte avec succès" << endl;
  }

  const char* sql = "CREATE TABLE IF NOT EXISTS user("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "firstname TEXT NOT NULL,"
                    "lastname TEXT NOT NULL,"
                    "email TEXT NOT NULL"
                    ");";
  exit = sqlite3_exec(db, sql,nullptr, nullptr, &errmsg);

  if(exit != SQLITE_OK){
    cerr << "Erreur création table => " << sqlite3_errmsg(db) << endl;
  }else{
    cout << "Table créée avec succès" << endl;
  }

  sql = "INSERT INTO user(firstname, lastname, email) VALUES('Watson', 'Sherlock', 'sherlock@wtson.uk'),"
        "('Holmes', 'John', 'olmes@joinh.ce');";

  exit = sqlite3_exec(db, sql, nullptr, nullptr, &errmsg);


  if(exit != SQLITE_OK){
    cerr << "Erreur lors de l'insertion " << sqlite3_errmsg(db) << endl;
  }else{
    cout << "Données insérée avec succès" << endl;
  }

  sql = "SELECT * FROM user;";
  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

  cout << "Liste des utilisateurs :" << endl;
  while(sqlite3_step(stmt) != SQLITE_DONE){
    cout << BLUE << "ID: " << sqlite3_column_int(stmt, 0) << endl;
    cout << "Prénom: " << sqlite3_column_text(stmt, 1) << endl;
    cout << "Nom: " << sqlite3_column_text(stmt, 2) << endl;
    cout << "Email: " << sqlite3_column_text(stmt, 3) << endl;
    cout << "------------------------" << RESET << endl;

  };

  sqlite3_finalize(stmt);

  sqlite3_close(db);


  return 0;
}


