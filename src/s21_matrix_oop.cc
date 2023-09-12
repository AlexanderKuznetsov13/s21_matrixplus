#include "s21_matrix_oop.h"
using namespace std;

S21Matrix::S21Matrix() { this->BringToZero(); }

S21Matrix::S21Matrix(int rows, int columns) {
  if (rows < 1 || columns < 1) {
    throw std::length_error("Rows or Columns less than 1 !!!");
  }
  this->rows_ = rows;
  this->columns_ = columns;
  this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other) { this->CopyMatrix(other); }

S21Matrix::S21Matrix(S21Matrix &&other) {
  this->CopyMatrix(other);
  other.ClearMatrix();
}

S21Matrix::~S21Matrix() { this->ClearMatrix(); }

void S21Matrix::CreateMatrix() {
  if (this->rows_ < 1 || this->columns_ < 1) {
    throw std::length_error("Rows or Columns less than 1 !!!");
  }
  this->matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[columns_]();
  }
}

void S21Matrix::BringToZero() {
  this->rows_ = 0;
  this->columns_ = 0;
  this->matrix_ = nullptr;
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  this->rows_ = other.rows_;
  this->columns_ = other.columns_;
  this->CreateMatrix();
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::ClearMatrix() {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < this->rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    this->matrix_ = nullptr;
  }
  this->rows_ = 0;
  this->columns_ = 0;
}

void S21Matrix::Minor(S21Matrix &result, int rows, int columns) {
  for (int i = 0, a = 0; i < this->rows_; i++) {
    if (columns != i) {
      for (int j = 0, b = 0; j < this->rows_; j++) {
        if (rows != j) {
          result.matrix_[a][b] = this->matrix_[i][j];
          b++;
        }
      }
      a++;
    }
  }
}

int S21Matrix::GetRows() { return this->rows_; }

int S21Matrix::GetColumns() { return this->columns_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::length_error("Rows is less 1 !!!");
  }
  S21Matrix tmp(rows, this->columns_);
  int less_rows = rows;
  if (rows > this->rows_) {
    less_rows = this->rows_;
  }
  for (int i = 0; i < less_rows; i++) {
    for (int j = 0; j < this->columns_; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
}

void S21Matrix::SetColumns(int columns) {
  if (columns < 1) {
    throw std::length_error("Columns is less 1 !!!");
  }
  S21Matrix tmp(this->rows_, columns);
  int less_columns = columns;
  if (columns > this->columns_) {
    less_columns = this->columns_;
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < less_columns; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
}