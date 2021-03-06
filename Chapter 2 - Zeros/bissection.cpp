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
	double a = 0, b = 1, m;
	m = (b + a) / 2;

	int n = 0;
	
	//Uso dos 4 critérios de paragem:
	while (n<=(3.3*6+log10(b-a)) && abs(b-a)>=pow(10, -5) && abs((b-a)/m)>=pow(10, -5) && abs(f(b)-f(a))>=pow(10, -5)) {
		if (f(m) == 0)
			break;
		else if (f(a)*f(m) < 0)
			b = m;
		else
			a = m;
		n++;
		m = (b + a) / 2;
	}

	cout << m;

	return 0;
}

