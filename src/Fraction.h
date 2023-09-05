#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {

private:
   int numerator;
   int denominator;

   void reduce();
   int gcd(int a, int b);

public:
   Fraction();
   Fraction(int n, int d);
   Fraction(const Fraction& other);

   int getNumerator() const;
   int getDenominator() const;
   int getNumDigits() const;
   void setNumerator(int n);
   void setDenominator(int d);

   bool isNegative() const;

   Fraction operator+(const Fraction& other) const;
   Fraction& operator+=(const Fraction& other);
   Fraction operator-(const Fraction& other) const;
   Fraction& operator-=(const Fraction& other);
   Fraction operator*(int x) const;
   Fraction operator*(const Fraction& other) const;
   Fraction& operator*=(int x);
   Fraction& operator*=(const Fraction& other);
};

std::istream& operator>>(std::istream& s, Fraction& other);
std::ostream& operator<<(std::ostream& s, const Fraction& other);

#endif