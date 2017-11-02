/**
 * Titik Data Type Driver File
 * 
 */

#include <iostream>
#include "../inc/titik.h"

int main() {

  Titik t(1.0f, 2.3f, 1.5f);
  std::cout << t.getX() << " " << t.getY() << " " << t.getZ() << std::endl;
}