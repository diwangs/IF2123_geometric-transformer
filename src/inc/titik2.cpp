/**
 * Titik2 Data Type
 * 
 */

#include "titik2.h"
#include "matriks2.h"

Titik2::Titik2(float x, float y) {
  setX(x);
  setY(y);
}

/*************** GETTER ***************/
float Titik2::getX() {
  return m_x;
}

float Titik2::getY() {
  return m_y;
}

/*************** SETTER ***************/
void Titik2::setX(float x) {
  m_x = x;
}

void Titik2::setY(float y) {
  m_y = y;
}

/************** OPERATION *************/

Titik2 Titik2::translate(float dx, float dy) {
  Titik2 nt(m_x + dx, m_y + dy);
  return nt;
}

Titik2 Titik2::dilate(float k) {
  Matriks2 m(2);
  float mat[2][2] = {
    {k, 0.0f},
    {0.0f, k}
  };

  m.setAll(mat);

  return transform(m);
}

Titik2 Titik2::rotateOrigin(float deg) {
  //
}

Titik2 Titik2::rotate(float deg, float c_x, float c_y) {
  //
}

Titik2 Titik2::reflectByLine(int type) {
  //
}

Titik2 Titik2::reflectByPoint(float c_x, float c_y) {
  //
}

Titik2 Titik2::shearByX(float k) {
  //
}

Titik2 Titik2::shearByY(float k) {
  //
}

Titik2 Titik2::stretchByX(float k) {
  //
}

Titik2 Titik2::stretchByY(float k) {
  //
}

Titik2 Titik2::transform(Matriks2 m) {
  Titik2 nt(0,0);

  float x = getX();
  float y = getY();

  nt.setX(x * m.getElmt(0,0) + y * m.getElmt(0,1));
  nt.setY(x * m.getElmt(1,0) + y * m.getElmt(1,1));

  return nt;
}
