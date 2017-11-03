/**
 * Matriks2 Data Type
 * 
 */

#include "matriks2.h"

Matriks2::Matriks2(int row) {
  setRow(row);
  m_col = 2;
}

/*************** GETTER ***************/
int Matriks2::getRow() {
  return m_row;
}

int Matriks2::getCol() {
  return m_col;
}

float Matriks2::getElmt(int row, int col) {
  return m_mat[row][col];
}

/*************** SETTER ***************/
void Matriks2::setRow(int row) {
  m_row = row;
}

void Matriks2::setElmt(int row, int col, float elmt)
{
  m_mat[row][col] = elmt;
}

void Matriks2::setAll(float mat[2][2]) {
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      setElmt(i,j,mat[i][j]);
    }
  }
}
