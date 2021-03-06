// rk4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double df(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

inline double dy1(double x, double y, double h) {
	return h * df(x, y);
}

inline double dy2(double x, double y, double h) {
	return h * df(x + h / 2, y + dy1(x, y, h) / 2);
}

inline double dy3(double x, double y, double h) {
	return h * df(x + h / 2, y + dy2(x, y, h) / 2);
}

inline double dy4(double x, double y, double h) {
	return h * df(x + h, y + dy3(x, y, h));
}

int main()
{
	double x = 0, y = 0, h = 0.1;

	for (; x <= 1.4; x += h) {
		y += dy1(x, y, h) / 6 + dy2(x, y, h) / 3 + dy3(x, y, h) / 3 + dy4(x, y, h) / 6;
	}
	double S = y, S1, S2;

	cout << y << endl;

	x = 0; y = 0; h = h / 2;
	for (; x <= 1.4; x += h) {
		y += dy1(x, y, h) / 6 + dy2(x, y, h) / 3 + dy3(x, y, h) / 3 + dy4(x, y, h) / 6;
	}
	S1 = y;

	cout << y << endl;

	x = 0; y = 0; h = h / 2;
	int n = 0;
	for (; n < 56; n++) {
		y += dy1(x, y, h) / 6 + dy2(x, y, h) / 3 + dy3(x, y, h) / 3 + dy4(x, y, h) / 6;
		x += h;
	}
	S2 = y;

	cout << y << endl;

	cout << "QC: " << (S1 - S) / (S2 - S1) << endl;

	cout << "Epsilon: " << (S2 - S1) / 15 << endl;

	return 0;
}
