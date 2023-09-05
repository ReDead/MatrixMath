#include "../src/Matrix.h"
#include "TestMatrix.h"
#include <iostream>

using std::cout, std::endl;

void testSubMatrix() {
	Matrix* m1 = new Matrix(3, 3, "1 2 3 4 5 6 7 8 9");

	Matrix* m2 = m1->subMatrix(1, 1);

	cout << *m1 << endl;
	cout << *m2 << endl;

	delete m1;
	delete m2;
}

void testDeterminant() {
	Matrix* m1 = new Matrix(1, 1, "5");
	cout << *m1;
	cout << recursiveDeterminant(m1) << " = 5" << endl;

	Matrix* m2 = new Matrix(2, 2, "3 8 4 6");
	cout << *m2;
	cout << recursiveDeterminant(m2) << " = -14" << endl;

	Matrix* m3 = new Matrix(3, 3, "6 1 1 4 -2 5 2 8 7");
	cout << *m3;
	cout << recursiveDeterminant(m3) << " = -306" << endl;
}

int main() {
	testDeterminant();

	return 0;
}