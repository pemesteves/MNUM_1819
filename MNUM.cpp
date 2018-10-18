// MNUM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double somatorio(double ini, int n, double h);
double somatorioPar(double ini, int n, double h);
double somatorioImpar(double ini, int n, double h);
inline double f(double x);
double regraTrapezios(int n);
double metodoSimpson(int n);
int controloErroTrapezios();
int controloErroSimpson();

void callFunctions(int n) {
	double value;
	cout << n << endl;
	value = regraTrapezios(n);
	cout << "Trap: " << 2 - value << endl;
	value = metodoSimpson(n);
	cout << "Simp: " << 2 - value << endl;
}

int main()
{
	/*
	callFunctions(2);
	callFunctions(4);
	callFunctions(8);
	callFunctions(10);
	callFunctions(20);
	callFunctions(40);*/

	cout << controloErroTrapezios() << endl;
	cout << controloErroSimpson() << endl;
	return 0;
}

double regraTrapezios(int n)
{
	double xn = 4 * atan(1), h, x0 = xn / 4;

	h = (xn - x0) / n;

	double soma = h * (f(0) + f(xn) + 2 * somatorio(x0 + h, n, h)) / 2;

	return soma;
}

double metodoSimpson(int n)
{
	double xn = 4 * atan(1), h, x0 = 0;

	h = (xn - x0) / (2 * n);

	double soma = h * (f(0) + f(xn) + 4 * somatorioImpar(x0, n, h) + 2 * somatorioPar(x0, n, h)) / 3;

	return soma;
}

double f(double x) {
	return sin(x);
}

double somatorio(double x, int n, double h) {
	double soma = 0;

	for (int i = 1; i < n; i++) {
		soma += f(x);
		x += h;
	}

	return soma;
}

double somatorioPar(double x, int n, double h) {
	double soma = 0;

	for (int i = 2; i <= (2 * n - 2); i = i + 2) {
		soma += f(x + i * h);
	}

	return soma;
}

double somatorioImpar(double x, int n, double h) {
	double soma = 0;

	for (int i = 1; i <= (2 * n - 1); i = i + 2) {
		soma += f(x + i * h);
	}

	return soma;
}

int controloErroTrapezios() {
	int n = 2, n1 = 4, n2 = 8;
	double S = 2 - regraTrapezios(n), S1 = 2 - regraTrapezios(n1), S2 = 2 - regraTrapezios(n2);

	while (abs((S1 - S) / (S2 - S1)) > (4 + pow(10, -1))) {
		n = n1; n1 = n2; n2 *= 2;
		S = S1; S1 = S2; S2 = 2 - regraTrapezios(n2);
	}

	return n2;
}

int controloErroSimpson() {
	int n = 2, n1 = 4, n2 = 8;
	double S = 2 - regraTrapezios(n), S1 = 2 - regraTrapezios(n1), S2 = 2 - regraTrapezios(n2);

	while (abs((S1 - S) / (S2 - S1)) > (16 + pow(10, -1))) {
		n = n1; n1 = n2; n2 *= 2;
		S = S1; S1 = S2; S2 = 2 - regraTrapezios(n2);
	}

	return n2;
}