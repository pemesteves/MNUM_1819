// simpson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double f(double x) {
	return sin(x);
}

double somaImpar(const double &inValue, const double &h, const unsigned int &n) {
	double soma = 0;
	for (unsigned int i = 1; i < 2*n-1; i=i+2) {
		soma += f(inValue + h * i);
	}
	return soma;
}

double somaPar(const double &inValue, const double &h, const unsigned int &n) {
	double soma = 0;
	for (unsigned int i = 2; i < 2*n-2; i=i+2) {
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
	h = (b - a) / (2*n);

	integral = h * (f(a) + f(b) + 4*somaImpar(a, h, n) + 2*somaPar(a, h, n))/3;

	cout << integral;

	return 0;
}

