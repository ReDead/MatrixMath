#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include "Fraction.h"

class Matrix {

private:
   Fraction** matrix;
   int rows, cols;

   void clear();
   void multiplyRow(int index, Fraction multiplier);
   void multiplyAndAddRow(int index1, Fraction multiplier, int index2);

public:
   Matrix();
   Matrix(int r, int c);
   Matrix(int r, int c, std::string nums);
   Matrix(const Matrix& other);
   ~Matrix();

   void setVals();
   void setSize(int r, int c);
   int getRows() const;
   int getCols() const;
   Fraction at(int r, int c) const;
   void set(int r, int c, Fraction f);
   Matrix* subMatrix(int delRow, int delCol);

   Fraction solve();
   int findLongestFraction() const;
   void transpose();
   void invert();

   Matrix& operator*=(Fraction f);
   Matrix* operator*(Fraction f) const;
   Matrix& operator+=(const Matrix& other);

};

Matrix* matrixMultiply(Matrix* m1, Matrix* m2);
Fraction recursiveDeterminant(Matrix* m);

std::ostream& operator<<(std::ostream& s, const Matrix& other);

#endif