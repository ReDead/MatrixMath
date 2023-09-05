#ifndef UI_H
#define UI_H

#include "Matrix.h"

Matrix* m;

int main();

void printOptions();
Matrix* enterMatrix();
Matrix* enterMatrix(int rows, int cols);

void doStuff(int num);
void addMatrix();
void multiplyScalar();
void multiplyMatrix();

void printEditMenu();
void edit();
void editMatrix(int num);
void changeValue();

void wait();

#endif