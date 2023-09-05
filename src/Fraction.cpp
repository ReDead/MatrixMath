#include "Fraction.h"
#include <string>

using namespace std;

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int n, int d) {
	numerator = n;
	denominator = d;
	reduce();
}

Fraction::Fraction(const Fraction& other) {
	numerator = other.numerator;
	denominator = other.denominator;
}

void Fraction::reduce() {
	if(numerator == 0) {
		denominator = 1;
	} else {
		bool negative = false;
		if(numerator < 0) {
			numerator *= -1;
			negative = true;
		}
		int divisor = gcd(numerator, denominator);
		numerator /= divisor;
		denominator /= divisor;
		if(negative)
			numerator *= -1;
	}
}

int Fraction::gcd(int a, int b) {
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int Fraction::getNumerator() const {
	return numerator;
}

int Fraction::getDenominator() const {
	return denominator;
}

int Fraction::getNumDigits() const {
	int count = isNegative(); // adds one for negative
	if(numerator == 0)
		return count + 1;
	int num = numerator;
	while(num > 0) {
		count++;
		num /= 10;
	}
	if(denominator != 1) {
		count++; //adds one for the '/'
		num = denominator;
		while(num > 0) {
			count++;
			num /= 10;
		}
	}
	return count;
}

void Fraction::setNumerator(int n) {
	numerator = n;
	reduce();
}

void Fraction::setDenominator(int d) {
	denominator = d;
	reduce();
}

bool Fraction::isNegative() const {
	return numerator < 0;
}

Fraction& Fraction::operator*=(int x) {
	numerator *= x;
	reduce();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
	numerator *= other.numerator;
	denominator *= other.denominator;
	reduce();
	return *this;
}

Fraction Fraction::operator*(int x) const {
	Fraction fr = *this;
	fr *= x;
	return fr;
}

Fraction Fraction::operator*(const Fraction& other) const {
	Fraction fr = *this;
	fr *= other;
	return fr;
}

Fraction& Fraction::operator+=(const Fraction& other) {
	Fraction other2 = other;
	if(denominator != other2.denominator) {
		other2 *= denominator;
		numerator *= other.denominator;
		denominator *= other.denominator;
	}
	numerator += other2.numerator;
	reduce();
	return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
	Fraction fr = *this;
	fr += other;
	return fr;
}

Fraction& Fraction::operator-=(const Fraction& other) {
	Fraction other2 = other;
	if(denominator != other2.denominator) {
		other2 *= denominator;
		numerator *= other.denominator;
		denominator *= other.denominator;
	}
	numerator -= other2.numerator;
	reduce();
	return *this;
}

Fraction Fraction::operator-(const Fraction& other) const {
	Fraction fr = *this;
	fr -= other;
	return fr;
}

std::istream& operator>>(std::istream& s, Fraction& other) {
	std::string in;
	s >> in;
	if(in.find('/') == std::string::npos) {
		other.setNumerator(stoi(in));
		other.setDenominator(1);
	} else {
		int loc = in.find('/');
		other.setNumerator(stoi(in.substr(0, loc)));
		other.setDenominator(stoi(in.substr(loc + 1)));
	}
}

std::ostream& operator<<(std::ostream& s, const Fraction& other) {
	s << other.getNumerator();
	if(other.getDenominator() != 1 && other.getNumerator() != 0)
		s << "/" << other.getDenominator();
	return s;
}