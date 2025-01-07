#include "Person.h"
#include <iostream>
#include <string>

using namespace std;
// constructors
Person::Person() : firstname(""), lastname(""), email(""), age(0) {};
Person::Person(string firstname, string lastname, string email, int age): firstname(firstname), lastname(lastname), email(email), age(age){};
Person::~Person(){};

// accessors
void Person::setFirstname(string firstname){ this->firstname = firstname; }
void Person::setLastname(string lastname){ this->lastname = lastname; }
void Person::setEmail(string email){ this->email = email; }
void Person::setAge(int age){ this->age = age; }

// mutators
string Person::getFirstname() const{ return this->firstname; };
string Person::getLastname() const{ return this->lastname; }
string Person::getEmail() const{ return this->email; }
int Person::getAge() const{ return this->age; }

// other methods
void Person::displayInfo() const{
  cout << "Informations du contact : " << endl;
  cout << "Nom : " << this->firstname << endl;
  cout << "Prénom : " << this->lastname << endl;
  cout << "Email : " << this->email << endl;
  cout << "Age : " << this->age << endl;
}
