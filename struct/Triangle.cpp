#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle(): side1(0), side2(0), side3(0) {};
Triangle::Triangle(int side1, int side2, int side3): side1(side1), side2(side2), side3(side3) {};

void Triangle::magritte() const{
  cout << "This is not a triangle" << endl;
}

void Triangle::calculateArea() const{
  int p = (side1 + side2 + side3) / 2;
  int result = sqrt(p * (p - side1) * (p - side2) * (p - side3));
  cout << "Area of the triangle : " << result << endl;

}
