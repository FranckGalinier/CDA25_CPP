#include <sqlite3.h>
#include "sqlite_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// fonction init connexion
int sqlite_init(SQLiteConnection* con, const char* db_file){

  int result = sqlite3_open(db_file, &con->db);
  if(result != SQLITE_OK){
    con->lastError = (char*)sqlite3_errmsg(con->db);
    return result;
  }else{
    con->lastError = nullptr;
    return SQLITE_OK;
  }
}

//fonction pour femer la conenxion
void sqlite_close(SQLiteConnection* con){

  if(con->db){
    sqlite3_close(con->db);
  }
  if(con->lastError){
    free(con->lastError);
    con->lastError = nullptr;
  }
};

//fonction pour executer une requete
int sqlite_execute(SQLiteConnection* con, const char* sql){

  char* errMessage = nullptr;
  int result = sqlite3_exec(con->db, sql, NULL, NULL, &errMessage); 
  if(result != SQLITE_OK){
    con->lastError = strdup(errMessage);
    sqlite3_free(errMessage);
    return result;
  }else{
    con->lastError = nullptr;
    return SQLITE_OK;
  }

};

// fonction read
int sqlite_query(SQLiteConnection* con, const char* sql, int (*callback)(void*, int, char**, char**), void* data){
  char* errMessage = nullptr;
  int result = sqlite3_exec(con->db, sql, callback, data, &errMessage);
  if(result != SQLITE_OK){
    con->lastError = strdup(errMessage);
    sqlite3_free(errMessage);
    return result;
  };
  return SQLITE_OK;
};

