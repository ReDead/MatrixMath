#include "UI.h"
#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
	m = enterMatrix();

	printOptions();
	int choice;
	cin >> choice;
	while(choice < 1 || choice > 9) {
		cout << "Please enter an integer between 1 and 9." << endl;
		cin >> choice;
	}
	cout << endl;

	while(choice != 9) {
		doStuff(choice);
		printOptions();
		cin >> choice;
		while(choice < 1 || choice > 9) {
			cout << "Please enter an integer between 1 and 9." << endl;
			cin >> choice;
		}
		cout << endl;
	}

	cout << "Thank you. Goodbye." << endl;
	delete m;
	return 0;
}

void printOptions() {
	cout << endl << *m;
	cout << "What would you like to do with your matrix?" << endl;
	cout << "1. Add another matrix" << endl;
	cout << "2. Multiply by a scalar" << endl;
	cout << "3. Multiply by another matrix" << endl;
	cout << "4. Transpose" << endl;
	cout << "5. Solve (WIP)" << endl;
	cout << "6. Find the determinant" << endl;
	cout << "7. Invert (WIP)" << endl;
	cout << "8. Edit your matrix" << endl;
	cout << "9. Exit" << endl;
}

Matrix* enterMatrix() {
	int rows, cols;
	cout << "Please enter the following information for a matrix." << endl;
	cout << "Number of rows: ";
	cin >> rows;
	cout << "Number of columns: ";
	cin >> cols;
	cout << endl;
	Matrix* m1 = new Matrix(rows, cols);
	m1->setVals();
	return m1;
}

Matrix* enterMatrix(int rows, int cols) {
	cout << endl;
	Matrix* m1 = new Matrix(rows, cols);
	m1->setVals();
	return m1;
}

void doStuff(int num) {
	switch(num) {
		case 1:
			addMatrix();
			break;
		case 2:
			multiplyScalar();
			break;
		case 3:
			multiplyMatrix();
			break;
		case 4:
			m->transpose();
			break;
		case 5:
			m->solve();
			break;
		case 6:
			cout << "Determinant = " << recursiveDeterminant(m) << endl;
			wait();
			break;
		case 7:
			m->invert();
			break;
		case 8:
			edit();
			break;
	}
}

void addMatrix() {
	cout << "Please enter the matrix to add to the current one.";
	Matrix* m2 = enterMatrix(m->getRows(), m->getCols());
	cout << endl << *m << " + " << endl << *m2 << " = " << endl;
	*m += *m2;
	cout << *m;
	delete m2;
	wait();
}

void multiplyScalar() {
	cout << "Enter a scalar to multiply by (can be a fraction): ";
	Fraction f;
	cin >> f;
	cout << f << endl << " * " << endl << *m;
	*m *= f;
	cout << " = " << endl << *m << endl;
	wait();
}

void multiplyMatrix() {
	cout << "Please enter the matrix to multiply to this one." << endl;
	Matrix* m2 = enterMatrix();
	if(m->getCols() != m2->getRows()) {
		cout << "Matrix sizes do not match properly for multiplying." << endl;
		return;
	}
	cout << endl << *m << " * " << endl << *m2 << " = " << endl;
	Matrix* m3 = matrixMultiply(m, m2);
	delete m;
	delete m2;
	m = m3;
	cout << *m;
	wait();
}

void printEditMenu() {
	cout << endl << *m;
	cout << "How would you like to edit your matrix?" << endl;
	cout << "1. Change a value" << endl;
	cout << "2. Re-enter your matrix" << endl;
	cout << "3. Go back" << endl;
}

void edit() {
	int choice;
	printEditMenu();
	cin >> choice;
	while(choice < 0 || choice > 3) {
		cout << "Please enter an integer between 1 and 3." << endl;
		cin >> choice;
	}
	cout << endl;
	while(choice != 3) {
		editMatrix(choice);
		printEditMenu();
		cin >> choice;
		while(choice < 0 || choice > 3) {
			cout << "Please enter an integer between 1 and 3." << endl;
			cin >> choice;
		}
		cout << endl;
	}
}

void editMatrix(int num) {
	switch(num) {
		case 1:
			changeValue();
			break;
		case 2:
			delete m;
			m = enterMatrix();
			break;
	}
}

void changeValue() {
	cout << *m << "Select which value to change by entering a row folled by a column: ";
	int row, col;
	cin >> row >> col;
	if(row < 0 || row >= m->getRows() || col < 0 || col > m->getCols()) {
		cout << "Invalid input." << endl;
		return;
	}
	cout << "What would you like to change it to? ";
	Fraction val;
	cin >> val;
	m->set(row, col, val);
}

void wait() {
	cout << "Press 1 to continue.";
	int choice;
	cin >> choice;
	while(choice != 1) {
		cin >> choice;
	}
}