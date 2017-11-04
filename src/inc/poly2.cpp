/**
 * Titik2 Data Type
 * 
 */

#include <stdlib.h>
#include "titik2.h"
#include "matriks2.h"
#include "poly2.h"

Poly2::Poly2(int n) {
  m_n_edges = n;
  m_corners = (Titik2*) malloc(n * sizeof(Titik2));
}

int Poly2::getEdge() {
  return m_n_edges;
}

Titik2 Poly2::getCorner(int i) {
  return m_corners[i];
}

void Poly2::setCorner(int i, Titik2 corner) {
  m_corners[i] = corner;
}

void Poly2::translate(float dx, float dy) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.translate(dx, dy);
    setCorner(i, corner);
  }
}

void Poly2::dilate(float k) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.dilate(k);
    setCorner(i, corner);
  }
}

void Poly2::rotateOrigin(float deg) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.rotateOrigin(deg);
    setCorner(i, corner);
  }
}

void Poly2::rotate(float deg, float c_x, float c_y) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.rotate(deg, c_x, c_y);
    setCorner(i, corner);
  }
}

void Poly2::reflectByLine(int type) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.reflectByLine(type);
    setCorner(i, corner);
  }
}

void Poly2::reflectByPoint(float c_x, float c_y) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.reflectByPoint(c_x, c_y);
    setCorner(i, corner);
  }
}

void Poly2::shearByX(float k) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.shearByX(k);
    setCorner(i, corner);
  }
}

void Poly2::shearByY(float k) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.shearByY(k);
    setCorner(i, corner);
  }
}

void Poly2::stretchByX(float k) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.shearByX(k);
    setCorner(i, corner);
  }
}

void Poly2::stretchByY(float k) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.shearByY(k);
    setCorner(i, corner);
  }
}

void Poly2::customTransform(float a, float b, float c, float d) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.customTransform(a, b, c, d);
    setCorner(i, corner);
  }
}

void Poly2::transform(Matriks2 m) {
  for (int i=0; i<getEdge(); i++) {
    Titik2 corner = getCorner(i);
    corner.transform(m);
    setCorner(i, corner);
  }
}

