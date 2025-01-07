#ifndef CAT_H
#define CAT_H
#include <string>
#include "Animal.h"
using namespace std;

class Cat : public Animal{
  private:
    int nbrOfLives;

  public:
    Cat();
    Cat(string name, int age, float weight, string color, string sexe, int nbrOfLives);
    ~Cat();
    
    int getNbrOfLives() const;
    
    void setNbrOfLives(int nbrOfLives);
    
    void displayInfo() const;

};

#endif