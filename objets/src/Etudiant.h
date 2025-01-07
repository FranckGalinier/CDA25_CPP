#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <string>
#include "Person.h"

using namespace std;

class Etudiant : public Person{//déclaration de la classe Etudiant qui hérite de la classe Person
  private:
    string grade;
    string school;
  
  public:
  // Constructors
    Etudiant();
    Etudiant(string grade, string school);
    Etudiant(string grade, string school, string firstname, string lastname, string email, int age);
    ~Etudiant();

    // accessors
    string getGrade() const;
    string getSchool() const;

    // mutators
    void setGrade(string grade);
    void setSchool(string school);

    //other methods

    void toString() const;

};
#endif