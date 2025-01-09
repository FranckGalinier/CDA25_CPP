#include <iostream>
#include <string>
#include "Triangle.h"

using namespace std;


struct Person {
  string name;
  int age;
  float size;
};

struct Rectangle {
  int width, height;

  Rectangle() : width(0), height(0) {};
  Rectangle(int width, int height): width(width),height(height) {};

  int area(){
    return width * height;
  }

  void displayArea(){
    cout << "Area of the rectangle : " << area() << endl;
  }
};

struct Animal {
  string name;

  void eat(){
    cout << name << " is eating something" << endl;
  }
};

struct Dog : public Animal {

  void bark(){
    cout << name << " is barking" << endl;
  }
};


int main(){

  Person p;
  p.name = "John";
  p.age = 25;
  p.size = 1.75;

  // cout << "Name: " << p.name << endl;
  // cout << "Age: " << p.age << endl;
  // cout << "Size: " << p.size << endl;

  Rectangle r(10, 5);

  r.displayArea();

  Rectangle r2;

  r2.height = 10;
  r2.width = 23;
  r2.displayArea();
  

  Dog d;
  d.name = "Oslo";
  d.eat();
  d.bark();

  Animal chat;
  chat.name = "Mimi";
  chat.eat();

  Triangle t1(4,6,8);
  t1.magritte();
  t1.calculateArea();












  return 0;
}