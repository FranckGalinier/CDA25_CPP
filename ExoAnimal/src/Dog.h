#ifndef DOG_H
#define DOG_H
#include <string>
#include "Animal.h"
using namespace std;

class Dog : public Animal{
  private:
    string breed;
    
  public:
    Dog();
    Dog(string name, int age, float weight, string color, string sexe, string breed);
    ~Dog();
    
    string getBreed() const;
    
    void setBreed(string breed);
    
    void displayInfo() const;
};

#endif
