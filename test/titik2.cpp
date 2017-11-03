/**
 * Titik Data Type Driver File
 * 
 */

#include <iostream>
#include "../src/inc/titik2.h"

int main() {

  Titik2 t(1.0f, 2.3f);
  std::cout << t.getX() << " " << t.getY() << std::endl;
  t = t.dilate(2);
  std::cout << t.getX() << " " << t.getY() << std::endl;
}