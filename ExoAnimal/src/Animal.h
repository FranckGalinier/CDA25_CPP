#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal{
  private:
    string name;
    float weight;
    string color;
    int age;
    string sexe;
    
  public:
    Animal();
    Animal(string name, int age, float weight, string color, string sexe);
    ~Animal();
    
    string getName() const;
    int getAge() const;
    float getWeight() const;
    string getColor() const;
    string getSexe() const;
    
    void setName(string name);
    void setAge(int age);
    void setWeight(float weight);
    void setColor(string color);
    void setSexe(string sexe);
    
    void displayInfo() const;
};

#endif
