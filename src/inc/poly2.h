/**
 * Polygon Data Type
 * 
 */

#ifndef POLY2_H
#define POLY2_H

#include "titik2.h"
#define ANIMATION_STEP 60

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
  /* change poly to have n edge */
  void setEdge(int n);
  /* move i-th corner to corner */
  void setCorner(int i, Titik2 corner);

  /* translate the Poly2 */
  void translate(float dx, float dy);
  void animateTranslate(float dx, float dy, int step);
  /* dilate the Poly2 from (0,0) */
  void dilate(float k);
  void animateDilate(float k, int step);
  /* rotate the Poly2 from (0,0) */
  void rotateOrigin(float deg);
  void animateRotateOrigin(float deg, int step);
  /* rotate the Poly2 from (c_x,c_y) */
  void rotate(float deg, float c_x, float c_y);
  void animateRotate(float deg, float c_x, float c_y, int step);
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
  void animateShearByX(float k, int step);
  /* shear the Poly2 in y direction by k factor */
  void shearByY(float k);
  void animateShearByY(float k, int step);
  /* shear the Poly2 in x direction by k factor */
  void stretchByX(float k);
  void animateStretchByX(float k, int step);
  /* shear the Poly2 in y direction by k factor */
  void stretchByY(float k);
  void animateStretchByY(float k, int step);
  /* transform the Poly2 by Matriks2 m
   * m element is
   * a b 
   * c d */
  void customTransform(float a, float b, float c, float d);
  void animateCustomTransform(float a, float b, float c, float d, int step);
  /* transform the Titik2 by Matriks2 m
   * m is valid Matriks2 */
  void transform(Matriks2 m);

};

#endif