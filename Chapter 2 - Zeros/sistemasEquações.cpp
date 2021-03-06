// SistemasEquações.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

double g1(double x, double y) {
	return  ((y + 5) / 2 - 1 / (2 * x));
}

double g2(double x, double y) {
	return (sqrt(x + 3 * log(x)));
}

double f1(double x, double y) {
	return (2 * pow(x, 2) - x * y - 5 * x + 1);
}

double f2(double x, double y) {
	return (x + 3 * log(x) - pow(y, 2));
}

double df1(double x, double y) {
	return(4 * x - y - 5);
}

double df2(double x, double y) {
	return (-2 * y);
}


void picardPeano()
{
	double x0, y0, xn, yn;

	cout << "x0? "; cin >> x0;
	cout << "y0? "; cin >> y0;

	unsigned int i = 0;

	xn = g1(x0, y0);
	yn = g2(x0, y0);

	while (abs(xn - x0) >= pow(10, -5) && abs(yn - y0) >= pow(10, -5))
	{
		if (g1(xn, yn) == 0 || g2(xn, yn) == 0)
			break;

		x0 = xn;
		y0 = yn;

		xn = g1(x0, y0);
		yn = g2(x0, y0);

		i++;
	}

	cout << "xn = " << xn << endl << "yn = " << yn << endl << "Number of iterations: " << i << endl << endl;
}

void newton()
{
	double x0, y0, xn, yn;

	cout << "x0? "; cin >> x0;
	cout << "y0? "; cin >> y0;

	xn = x0 - f1(x0, y0) / df1(x0, y0);
	yn = y0 - f2(x0, y0) / df2(x0, y0);

	unsigned int i = 0;

	while (abs(xn - x0) >= pow(10, -5) && abs(yn - y0) >= pow(10, -5))
	{
		if (df1(x0, y0) == 0 || df2(x0, y0) == 0)
		{
			break;
		}

		x0 = xn;
		y0 = yn;

		xn = x0 - f1(x0, y0) / df1(x0, y0);
		yn = y0 - f2(x0, y0) / df2(x0, y0);

		i++;
	}

	cout << "xn = " << xn << endl << "yn = " << yn << endl << "Number of iterations: " << i << endl << endl;
}


int main()
{
	picardPeano();
	newton();
}
