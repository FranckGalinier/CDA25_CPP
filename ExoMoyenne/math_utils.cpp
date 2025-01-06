#include "math_utils.h"
#include <vector>
// Définition des fonctions
float calculMoyenne(const std::vector<float>& notes){

  float somme = 0;
  for(float i = 0; i < notes.size(); i++){
    somme += notes[i];
  }
  return somme / notes.size();

}

