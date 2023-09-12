#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H
#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
    public:
    S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

int GetRows();
int GetColumns();
void SetRows(int rows);
void SetColumns(int columns);

  private:
  int rows_;
  int columns_;
  double** matrix_;

  void CreateMatrix();
  void BringToZero();
  void ClearMatrix();
  void CopyMatrix(const S21Matrix& other);
   void Minor(S21Matrix& result, int rows, int columns);

};

#endif  // SRC_S21_MATRIX_OOP_H