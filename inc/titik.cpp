/**
 * Titik Data Type
 * 
 */

#include "titik.h"

Titik::Titik(float x, float y, float z)
{
  setX(x);
  setY(y);
  setZ(z);
}

/*************** GETTER ***************/
float Titik::getX()
{
  return m_x;
}

float Titik::getY()
{
  return m_y;
}

float Titik::getZ()
{
  return m_z;
}

/*************** SETTER ***************/
void Titik::setX(float x)
{
  m_x = x;
}

void Titik::setY(float y)
{
  m_y = y;
}

void Titik::setZ(float z)
{
  m_z = z;
}
