#include "Rational.h"
#include <sstream>
#include <cstdlib>

using namespace std;

//no arg constructor
Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

//constructor that converts the decimal to a fraction, unsimplified
Rational::Rational(double x) {
	Rational r = converts(x);
	numerator = r.numerator;
	denominator = r.denominator;
}

//finds the gcd and creates the final numerator and final denominator
Rational::Rational(int numerator, int denominator) {
	int factor = gcd(numerator, denominator);
	this->numerator = (denominator > 0 ? 1 : -1) * numerator / factor;
	this->denominator = abs(denominator) / factor;
}

//get functions for numerator and denominator
int Rational::getNumerator() {
	return numerator;
}
int Rational::getDenominator() {
	return denominator;
}

//converts decimal portion of number to a fraction
Rational Rational::converts(double x) {
	//set the number of times it goes through the loop to zero
	int n = 0;

	//while the decimal portion of the number does not equal zero,
	//multiply the number by ten (gives a whole number)
	double tmp = x - static_cast<int>(x);
	//this gives the amount of error
	while (tmp > 0.000000000001 || tmp < -0.000000000001) {
		x = x * 10;
		n = n + 1;    //n is the number of times going through the loop
		tmp = x - static_cast<int>(x);
	}

	//create new numerator and denominator
	int numerator = x;
	int denominator = pow(10, n);

	//return the new Rational object with this numerator and denominator
	return Rational(numerator, denominator);
}

//find gcd of the numerator and denominator
int Rational::gcd(int n, int d) {
	int n1 = abs(n);
	int n2 = abs(d);
	int gcd = 1;

	for (int k = 1; k <= n1 && k <= n2; k++) {
		if (n1 % k == 0 && n2 % k == 0) {
			gcd = k;
		}
	}
	return gcd;
}

