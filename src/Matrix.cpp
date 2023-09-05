#include "Matrix.h"
#include <sstream>

using namespace std;

Matrix::Matrix() {
	rows = 1;
	cols = 1;
	matrix = new Fraction*[1];
	matrix[0] = new Fraction[1];
}

Matrix::Matrix(int r, int c) {
	rows = r;
	cols = c;
	matrix = new Fraction*[r];
	for(int i=0; i<r; i++) {
		matrix[i] = new Fraction[c];
	}
}

Matrix::Matrix(int r, int c, std::string nums) {
	stringstream s(nums);
	rows = r;
	cols = c;
	matrix = new Fraction*[r];
	for(int i=0; i<r; i++) {
		matrix[i] = new Fraction[c];
		for(int j=0; j<c; j++) {
			s >> matrix[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& other) {
	rows = other.rows;
	cols = other.cols;
	matrix = new Fraction*[rows];
	for(int i=0; i<rows; i++) {
		matrix[i] = new Fraction[cols];
		for(int j=0; j<cols; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
	clear();
	rows = 0;
	cols = 0;
}

void Matrix::clear() {
	for(int i=0; i<rows; i++) {
		delete [] matrix[i];
	}
	delete [] matrix;
}

void Matrix::setVals() {
	std::cout << "This is a " << rows << "x" << cols << " Matrix." << std::endl << "Please enter in values for it separated by whitespace: " << std::endl;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
	std::cout << "Thank you." << std::endl;
}

void Matrix::setSize(int r, int c) {
	clear();
	rows = r;
	cols = c;
	matrix = new Fraction*[r];
	for(int i=0; i<r; i++) {
		matrix[i] = new Fraction[c];
	}
}

int Matrix::getRows() const {
	return rows;
}

int Matrix::getCols() const {
	return cols;
}

Fraction Matrix::at(int r, int c) const {
	return matrix[r][c];
}

void Matrix::set(int r, int c, Fraction f) {
	matrix[r][c] = f;
}

Fraction Matrix::solve() {
	Fraction f;
	return f; //FIX ME
}

void Matrix::multiplyRow(int index, Fraction multiplier) {

}

void Matrix::multiplyAndAddRow(int index1, Fraction multiplier, int index2) {
	
}

void Matrix::transpose() {
	Fraction** t = new Fraction*[cols];
	for(int i=0; i<cols; i++) {
		t[i] = new Fraction[rows];
		for(int j=0; j<rows; j++) {
			t[i][j] = matrix[j][i];
		}
	}
	clear();
	matrix = t;
	int temp = rows;
	rows = cols;
	cols = temp;
}

void Matrix::invert() {
	
}

Matrix& Matrix::operator*=(Fraction f) {
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			matrix[i][j] *= f;
		}
	}
	return *this;
}

Matrix* Matrix::operator*(Fraction f) const {
	Matrix* m = new Matrix(*this);
	*m *= f;
	return m;
}

Matrix& Matrix::operator+=(const Matrix& other) {
	if(rows != other.rows || cols != other.cols)
		throw std::invalid_argument("Matrices are not the same size.");
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}

int Matrix::findLongestFraction() const {
	int largest = 0;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			int curr = matrix[i][j].getNumDigits();
			if(curr > largest)
				largest = curr;
		}
	}
	return largest;
}

Matrix* matrixMultiply(Matrix* m1, Matrix* m2) {
	Matrix* out = new Matrix(m1->getRows(), m2->getCols());
	for(int i=0; i<out->getRows(); i++) {
		for(int j=0; j<out->getCols(); j++) {
			Fraction dp;
			for(int k=0; k<m1->getCols(); k++) {
				dp += m1->at(i, k) * m2->at(k, j);
			}
			out->set(i, j, dp);
		}
	}
	return out;
}

Matrix* Matrix::subMatrix(int delRow, int delCol) {
	Matrix* out = new Matrix(rows - 1, cols - 1);
	int row = 0;
	for(int i=0; i<rows; i++) {
		int col = 0;
		if(i != delRow) {
			for(int j=0; j<cols; j++) {
				if(j != delCol) {
					out->matrix[row][col] = matrix[i][j];
					col++;
				}
			}
			row++;
		}
	}
	return out;
}

Fraction recursiveDeterminant(Matrix* m) {
	if(m->getRows() != m->getCols())
		throw std::invalid_argument("Matrix is not nxn.");
	if(m->getRows() == 0 || m->getCols() == 0)
		throw std::invalid_argument("Matrix is empty.");
	if(m->getRows() == 1)
		return m->at(0, 0);
	Fraction f;
	for(int i=0; i<m->getCols(); i++) {
		if(i % 2 == 0)
			f += m->at(0, i) * recursiveDeterminant(m->subMatrix(0, i));
		else
			f -= m->at(0, i) * recursiveDeterminant(m->subMatrix(0, i));
	}
	return f;
}

std::ostream& operator<<(std::ostream& s, const Matrix& other) {
	for(int i=0; i<other.getRows(); i++) {
		s << "| ";
		for(int j=0; j<other.getCols(); j++) {
			s << other.at(i, j);
			int mostDigits = other.findLongestFraction();
			int digits = other.at(i, j).getNumDigits();
			for(int i=0; i<mostDigits + 1 - digits; i++) {
				s << " ";
			}
		}
		s << "|" << endl;
	}
	return s;
}
