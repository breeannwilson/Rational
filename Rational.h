#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>

using namespace std;

class Rational {
public: 
	Rational();
	Rational(double x);
	Rational(int numerator, int denominator);

	int getNumerator();
	int getDenominator();
	
	//converts a decimal number into a fraction
	static Rational converts(double x);


private:
	int numerator;
	int denominator;
	static int gcd(int n, int d);

};


#endif //RATIONAL_H