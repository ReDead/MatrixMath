#include <iostream>
#include "../src/Fraction.h"

using std::cout, std::endl;

int main() {
	Fraction fr;
	cout << fr << " = 0" << endl;

	Fraction fr2(2, 3);
	cout << fr2 << " = 2/3" << endl;

	fr.setNumerator(2);
	fr.setDenominator(3);
	cout << fr << " = 2/3" << endl;

	fr *= 5;
	fr2 = fr2 * 5;
	cout << fr << " = 10/3" << endl;
	cout << fr2 << " = 10/3" << endl;

	Fraction fr3(1, 3);
	Fraction fr4(1, 2);
	Fraction fr5 = fr3 + fr4;
	fr3 += fr4;
	cout << fr3 << " = 5/6" << endl;
	cout << fr5 << " = 5/6" << endl;

	fr3 += fr5;
	cout << fr3 << " = 5/3" << endl;

	Fraction fr6(10, 2);
	Fraction fr7(11, 22);
	Fraction fr8(15, 20);
	cout << fr6 << " = 5" << endl;
	cout << fr7 << " = 1/2" << endl;
	cout << fr8 << " = 3/4" << endl;

	Fraction fr9(2, 3);
	Fraction fr10(1, 3);
	Fraction fr11 = fr9 - fr10;
	fr9 -= fr10;
	cout << fr9 << " = 1/3" << endl;
	cout << fr11 << " = 1/3" << endl;

	//negatives
	Fraction fr12(2, 3);
	Fraction fr13(1, 3);
	fr13 -= fr12;
	cout << fr13 << " = -1/3" << endl;

	Fraction fr14(-15, 20);
	cout << fr14 << " = -3/4" << endl;
	Fraction fr15(-3, 3);
	cout << fr15 << " = -1" << endl;
	Fraction fr16(-1, 3);
	cout << fr16 << " = -1/3" << endl;

	Fraction fr17;
	Fraction fr18(5, 2);
	fr17 += fr18;
	cout << fr17 << " = 5/2" << endl;


	return 0;
}