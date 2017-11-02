/**
 * Matriks Data Type
 * 
 */

#include "matriks.h"

Matriks::Matriks(int row, int col)
{
  setRow(row);
  setCol(col);
}

/*************** GETTER ***************/
int Matriks::getRow()
{
  return m_row;
}

int Matriks::getCol()
{
  return m_col;
}

/*************** SETTER ***************/
void Matriks::setRow(int row)
{
  m_row = row;
}

void Matriks::setCol(int col)
{
  m_col = col;
}