/**
 * Matriks Data Type
 * 
 */

#ifndef TITIK_H
#define TITIK_H

class Titik
{
private:
  float m_x;
  float m_y;
  float m_z;

public:
  Titik(float x, float y, float z);
  
  float getX();
  float getY();
  float getZ();

  void setX(float x);
  void setY(float y);
  void setZ(float z);
  
};

#endif