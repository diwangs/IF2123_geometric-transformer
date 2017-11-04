/**
 * Polygon Data Type
 * 
 */

#ifndef POLY2_H
#define POLY2_H

#include "titik2.h"

class Poly2
{
private:
  int m_n_edges;
  Titik2* m_corners;

public:
  /* create Poly2 with n edges
   * all corners are in (0,0) */
  Poly2(int n);

  /* get number of edges */
  int getEdge();
  /* get all corners */
  Titik2 getCorners();
  /* get i-th corner */
  Titik2 getCorner(int i);
  /* move i-th corner to corner */
  void setCorner(int i, Titik2 corner);

  /* translate the Poly2 */
  void translate(float dx, float dy);
  /* dilate the Poly2 from (0,0) */
  void dilate(float k);
  /* rotate the Poly2 from (0,0) */
  void rotateOrigin(float deg);
  /* rotate the Poly2 from (c_x,c_y) */
  void rotate(float deg, float c_x, float c_y);
  /* reflect the Poly2 by line type:
   * 0 is absis
   * 1 is ordinate
   * 2 is x=y line
   * 3 is x=-y line
   * type is valid number */
  void reflectByLine(int type);
  /* reflect the Poly2 by point */
  void reflectByPoint(float c_x, float c_y);
  /* shear the Poly2 in x direction by k factor */
  void shearByX(float k);
  /* shear the Poly2 in y direction by k factor */
  void shearByY(float k);
  /* shear the Poly2 in x direction by k factor */
  void stretchByX(float k);
  /* shear the Poly2 in y direction by k factor */
  void stretchByY(float k);
  /* transform the Poly2 by Matriks2 m
   * m element is
   * a b 
   * c d */
  void customTransform(float a, float b, float c, float d);
  /* transform the Titik2 by Matriks2 m
   * m is valid Matriks2 */
  void transform(Matriks2 m);

};

#endif