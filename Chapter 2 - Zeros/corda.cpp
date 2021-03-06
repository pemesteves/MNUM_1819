// Ex. MNUM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double f(double x) {
	return (pow(x, 4) + 2 * pow(x, 3) - x - 1);
}

int main()
{
	double a = 0, b = 1, w;

	int n = 0;

	while (n<=(3.3*6+log10(b-a))) {
		w = (a*f(b) - b * f(a)) / (f(b) - f(a));
		
		if (f(w) == 0)
			break;
		else if (f(a)*f(w) < 0)
			b = w;
		else
			a = w;
		n++;
	}

	cout << w;

	return 0;
}

