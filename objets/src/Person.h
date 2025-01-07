#ifndef PERSON_H//si il n'est pas défini
#define PERSON_H//on le défini
#include <string>

using namespace std;

class Person{
  private:
    string firstname;
    string lastname;
    string email;
    int age;

  public:
  // Definition of Constructors
    Person();
    Person(string firstname, string lastname, string email, int age);
    ~Person();

    // Définition of accessors
    string getFirstname() const;
    string getLastname() const;
    string getEmail() const;
    int getAge() const;

    //Définition of  mutators
    void setFirstname(string firstname);
    void setLastname(string lastname);
    void setEmail(string email);
    void setAge(int age);

    // Définition of other methods
    void displayInfo() const;

};

#endif