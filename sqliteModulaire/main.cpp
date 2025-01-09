#include <stdio.h>
#include "sqlite_module.h"

int print_callback(void* data, int argc, char** argv, char** colName){

  for(int i = 0; i < argc; i++){
    printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(){

  SQLiteConnection con;

  //init connexion
  if(sqlite_init(&con, "sql.db") != SQLITE_OK){
    fprintf(stderr, "Erreur connexion => %s\n", con.lastError);
    return -1;
  }

  //creation table
 const char* sql = "CREATE TABLE IF NOT EXISTS user("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "firstname TEXT NOT NULL,"
                    "lastname TEXT NOT NULL,"
                    "email TEXT NOT NULL"
                    ");";
  if(sqlite_execute(&con, sql) != SQLITE_OK){
    fprintf(stderr, "Erreur création table => %s\n", con.lastError);
    return -1;
  }

  sql = "INSERT INTO user(firstname, lastname, email) VALUES('Watson', 'Sherlock', 'sherlock@fsfs.uo');"; 
   if(sqlite_execute(&con, sql) != SQLITE_OK){
    fprintf(stderr, "Erreur création table => %s\n", con.lastError);
    return -1;
  }
  
  sql = "SELECT * FROM user;";
  if(sqlite_query(&con, sql, print_callback, nullptr) != SQLITE_OK){
    fprintf(stderr, "Erreur lors de la requête => %s\n", con.lastError);
    return -1;
  }

  sqlite_close(&con);
  return 0;
}