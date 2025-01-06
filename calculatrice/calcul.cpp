#include <iostream>
#include "math_utils.h"

using namespace std;



int main(){

  int x = 15, y = 5;

  cout << "Somme : " << addition(x, y) << endl;
  cout << "Difference : " << soustraction(x, y) << endl;
  cout << "Product : " << multiplication(x, y) << endl;
  cout << "Quotient : " << division(x, y) << endl;

  return 0;

}
