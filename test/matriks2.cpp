/**
 * Matriks Data Type Driver File
 * 
 */

#include <iostream>
#include "../src/inc/matriks2.h"

int main() {
  Matriks2 m(2);

  float mat[2][2] = {
    {1,2},
    {3,4}
  };

  m.setAll(mat);
  std::cout << m.getElmt(0,0) << " " << m.getElmt(0,1) << std::endl;
  std::cout << m.getElmt(1,0) << " " << m.getElmt(1,1) << std::endl;
}