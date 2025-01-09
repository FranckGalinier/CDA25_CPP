#ifndef SQLITE_MODULE_H
#define SQLITE_MODULE_H
#include <sqlite3.h>

typedef struct{
  sqlite3* db;
  char* lastError;

} SQLiteConnection;

// fonction init connexion
int sqlite_init(SQLiteConnection* con, const char* db_file);

//fonction pour femer la conenxion
void sqlite_close(SQLiteConnection* con);

//fonction pour executer une requete
int sqlite_execute(SQLiteConnection* con, const char* sql);

// fonction read
int sqlite_query(SQLiteConnection* con, const char* sql, int (*callback)(void*, int, char**, char**), void* data);


#endif