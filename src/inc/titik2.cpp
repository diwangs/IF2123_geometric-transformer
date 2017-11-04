/**
 * Titik2 Data Type
 * 
 */

#include "titik2.h"
#include "matriks2.h"
#include <cmath>

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

void Titik2::translate(float dx, float dy) {
  setX(getX() + dx);
  setY(getY() + dy);
}

void Titik2::dilate(float k) {
  Matriks2 m(2);
  float mat[2][2] = {
    {   k, 0.0f},
    {0.0f,    k}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::rotateOrigin(float deg) {
  Matriks2 m(2);
  float mat[2][2] = {
    {cos(rad(deg)), -sin(rad(deg))},
    {sin(rad(deg)),  cos(rad(deg))}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::rotate(float deg, float c_x, float c_y) {
  translate(-c_x, -c_y);
  rotateOrigin(deg);
  translate(c_x, c_y);
}

void Titik2::reflectByLine(int type) {
  Matriks2 m(2);
  float mat[2][2] = {{0,0},{0,0}};

  if (type == 0) {
    mat[0][0] = 1;
    mat[1][1] = -1;
  } else if (type == 1) {
    mat[0][0] = -1;
    mat[1][1] = 1;
  } else if (type == 2) {
    mat[0][1] = 1;
    mat[1][0] = 1;
  } else if (type == 3) {
    mat[0][1] = -1;
    mat[1][0] = -1;
  }

  m.setAll(mat);

  transform(m);
}

void Titik2::reflectByPoint(float c_x, float c_y) {
  setX(2*c_x - getX());
  setY(2*c_y - getY());
}

void Titik2::shearByX(float k) {
  Matriks2 m(2);
  float mat[2][2] = {
    {1, k},
    {0, 1}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::shearByY(float k) {
  Matriks2 m(2);
  float mat[2][2] = {
    {1, 0},
    {k, 1}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::stretchByX(float k) {
  Matriks2 m(2);
  float mat[2][2] = {
    {k, 0},
    {0, 1}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::stretchByY(float k) {
  Matriks2 m(2);
  float mat[2][2] = {
    {1, 0},
    {0, k}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::customTransform(float a, float b, float c, float d) {
  Matriks2 m(2);
  float mat[2][2] = {
    {a, b},
    {c, d}
  };

  m.setAll(mat);

  transform(m);
}

void Titik2::transform(Matriks2 m) {
  float x = getX();
  float y = getY();
  setX(x * m.getElmt(0,0) + y * m.getElmt(0,1));
  setY(x * m.getElmt(1,0) + y * m.getElmt(1,1));
}
