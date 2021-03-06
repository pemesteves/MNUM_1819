// Ex. MNUM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double f(double x) {
	return (pow(x, 4) + 2 * pow(x, 3) - x - 1);
}

inline double df(double x) {
	return (4 * pow(x, 3) + 6 * pow(x, 2) - 1);
}

int main()
{
	double x = 1;
	double xn = x - f(x) / df(x);

	while (abs(xn-x) >= pow(10, -5)) {
		cout << x << endl;
		cout << xn << endl;
		if (f(xn) == 0)
			break;
		
		x = xn;
		xn = x - f(x) / df(x);

	}

	cout << xn;

	return 0;
}

