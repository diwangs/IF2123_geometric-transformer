/**
 * Matriks Data Type
 * 
 */

#ifndef TITIK2_H
#define TITIK2_H

#include "matriks2.h"

class Titik2
{
private:
  float m_x;
  float m_y;

public:
  /* create Titik2 with
   * 1st dimension is x
   * 2nd dimension is y */
  Titik2(float x, float y);
  
  /* get the 1st dimension element of Titik2 */
  float getX();
  /* get the 2nd dimension element of Titik2 */
  float getY();

  /* set the 1st dimension element of Titik2 */
  void setX(float x);
  /* set the 1st dimension element of Titik2 */
  void setY(float y);
  
  /* translate the Titik2 */
  Titik2 translate(float dx, float dy);
  /* dilate the Titik2 from (0,0) */
  Titik2 dilate(float k);
  /* rotate the Titik2 from (0,0) */
  Titik2 rotateOrigin(float deg);
  /* rotate the Titik2 from (c_x,c_y) */
  Titik2 rotate(float deg, float c_x, float c_y);
  /* reflect the Titik2 by line type:
   * 0 is absis
   * 1 is ordinate
   * 2 is x=y line
   * 3 is x=-y line
   * type is valid number */
  Titik2 reflectByLine(int type);
  /* reflect the Titik2 by point */
  Titik2 reflectByPoint(float c_x, float c_y);
  /* shear the Titik2 in x direction by k factor */
  Titik2 shearByX(float k);
  /* shear the Titik2 in y direction by k factor */
  Titik2 shearByY(float k);
  /* shear the Titik2 in x direction by k factor */
  Titik2 stretchByX(float k);
  /* shear the Titik2 in y direction by k factor */
  Titik2 stretchByY(float k);
  /* transform the Titik2 by Matriks2 m
   * m is valid Matriks2 */
  Titik2 transform(Matriks2 m);

};

#endif