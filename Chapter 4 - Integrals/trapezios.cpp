// trapezios.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double f(double x) {
	return sin(x);
}

double soma(const double &inValue, const double &h, const unsigned int &n) {
	double soma = 0;
	for (unsigned int i = 1; i < n; i++) {
		soma += f(inValue + h * i);
	}
	return soma;
}

int main()
{
	double a = 0;
	double b = 2 * atan(1); // pi:2
	double h, integral = 0;
	unsigned int n;
	cout << "n? "; cin >> n;
	h = (b - a) / n;

	integral = h * (f(a) + f(b) + 2*soma(a, h, n))/2;

	cout << integral;

	return 0;
}

