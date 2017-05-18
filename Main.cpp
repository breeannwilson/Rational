#include <iostream>
#include <cmath>
#include <string>
#include "Rational.h"

using namespace std;

void main() {
	double number;

	cout << "Enter any decimal value: ";
	cin >> number;

	//converts entered number to a fraction
	Rational r(number);

	cout << "The fractional value is: " << r.getNumerator() << "/" << r.getDenominator();


	system("pause");
}