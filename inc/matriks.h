/**
 * Matriks Data Type
 * 
 */

#ifndef MATRIKS_H
#define MATRIKS_H

class Matriks
{
private:
  int m_row;
  int m_col;

public:
  Matriks(int row, int col);
  
  int getRow();
  int getCol();

  void setRow(int row);
  void setCol(int col);
  
};

#endif