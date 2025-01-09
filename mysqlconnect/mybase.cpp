#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

int main(){
  try
  {
    // Création de la connexion
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3310", "cpp", "mycpp"));

    //connexion à la bdd
    con->setSchema("cpp");

    //création de la table
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    stmt->execute("CREATE TABLE IF NOT EXISTS user("
                    "id INT PRIMARY KEY AUTO_INCREMENT,"
                    "firstname VARCHAR(50) NOT NULL,"
                    "lastname VARCHAR(50) NOT NULL,"
                    "email VARCHAR(200) NOT NULL"
                    ");");

    stmt->execute("INSERT INTO user(firstname, lastname, email) VALUES('Sherlock', 'Watson', 'watson@sherlock.eu');");

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM user;"));
    while(res->next()){
      std::cout << "id = " << res->getInt("id") << std::endl;
      std::cout << "firstname = " << res->getString("firstname") << std::endl;
      std::cout << "lastname = " << res->getString("lastname") << std::endl;
      std::cout << "email = " << res->getString("email") << std::endl;
    }
  }
  catch(sql::SQLException &e)
  {
    std::cerr << "Erreur MySQL: " << e.what() << std::endl;

  }
  

}
