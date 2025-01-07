#include "Etudiant.h"
#include <iostream>
#include <string>

using namespace std;
// constructors
Etudiant::Etudiant() : grade(""), school("") {};
Etudiant::Etudiant(string grade, string school): grade(grade), school(school){};
Etudiant::Etudiant(string grade, string school, string firstname, string lastname,
                   string email, int age): Person(firstname, lastname, email, age), grade(grade), school(school){};
Etudiant::~Etudiant(){};

// accessors
string Etudiant::getGrade() const{ return this->grade; }
string Etudiant::getSchool() const{ return this->school; }

// mutators
void Etudiant::setGrade(string grade){ this->grade = grade; }
void Etudiant::setSchool(string school){ this->school = school; }

// other methods
void Etudiant::toString() const {

  cout << "Informations de l'étudiant : " << endl;
  
  cout << "Grade : " << this->grade << " |  Ecole : " << this->school << endl;
  cout << endl;

};
