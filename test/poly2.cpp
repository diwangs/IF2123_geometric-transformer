/**
 * Matriks Data Type Driver File
 * 
 */

#include <iostream>
#include "../src/inc/poly2.h"

void printPoly2(Poly2 poly) {
  for (int i=0; i<poly.getEdge(); i++) {
    Titik2 corner = poly.getCorner(i);
    std::cout << "(" << corner.getX() << "," << corner.getY() << ")" << std::endl;
    poly.setCorner(i, corner);
  }
}

int main() {
  Poly2 square(4);

  Titik2 corner(0.0f, 0.0f);

  corner = Titik2(0.0f, 1.0f);
  square.setCorner(0, corner);
  corner = Titik2(1.0f, 1.0f);
  square.setCorner(1, corner);
  corner = Titik2(1.0f, 0.0f);
  square.setCorner(2, corner);
  corner = Titik2(0.0f, 0.0f);
  square.setCorner(3, corner);

  printPoly2(square); std::cout << std::endl;

  square.translate(1.0f, 2.0f);

  printPoly2(square); std::cout << std::endl;

  //
}