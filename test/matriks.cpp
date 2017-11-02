/**
 * Matriks Data Type Driver File
 * 
 */

#include <iostream>
#include "../inc/matriks.h"

int main() {
  Matriks m(2,5);
  std::cout << m.getRow() << " " << m.getCol() << std::endl;
}