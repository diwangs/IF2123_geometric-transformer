/**
 * Matriks Data Type
 * 
 */

#ifndef MATRIKS2_H
#define MATRIKS2_H

class Matriks2
{
private:
  int m_row;
  int m_col;
  float m_mat[2][2];

public:
  Matriks2(int row);
  
  /* get number of rows */
  int getRow();
  /* get number of cols */
  int getCol();
  /* return element of Matriks2 at row and col given
   * row and col is valid number */
  float getElmt(int row, int col);

  /* set Matriks2 row
   * if row is expanded, the element is unset
   * (can be zero or random number) */
  void setRow(int row);
  /* set element of Matriks2 at row and col given to elmt
   * row and col is valid number */
  void setElmt(int row, int col, float elmt);
  /* set element of Matriks2 at row and col given to mat elmt */
  void setAll(float mat[2][2]);

};

#endif