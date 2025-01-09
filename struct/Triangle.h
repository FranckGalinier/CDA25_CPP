#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
using namespace std;


struct Triangle{

  int side1, side2, side3;

  Triangle();
  Triangle(int side1, int side2, int side3);

  void magritte() const;

  void calculateArea() const;
    

};

#endif