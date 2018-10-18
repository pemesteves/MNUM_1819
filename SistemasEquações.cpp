// SistemasEquações.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

double g1(double x, double y) {
	return  ((y + 5) / 2 - 1 / (2 * x));
}

double g2(double x, double y) {
	return (sqrt(x+3*log(x)));
}

double dg1x(double x, double y) {
	return(1 / (2 * pow(x, 2)));
}

double dg1y(double x, double y) {
	return(1 / 2);
}
/*double dg2x(double x, double y) {
	return((3/x);
}

double dg2y(double x, double y) {
	return(-(3*log(x) + x)/pow(y, 2));
}*/


void picardPeano()
{
	double x0, y0, xn, yn;

	cout << "x0? "; cin >> x0;
	cout << "y0? "; cin >> y0;

	unsigned int i = 0;

	if (abs(dg1x(x0, y0)) < 1 && abs(dg1y(x0, y0)) < 1)// && abs(dg1y(x0, y0)) < 1 && abs(dg2y(x0, y0)) < 1)
	{
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
	}
	else
	{
		//Definir outra função g(x) cuja derivada no ponto seja inferior a 1
		//g(x) = e^((x-5)/2)

		xn = exp((x0 - 5) / 2);

		while (abs(xn - x0) >= pow(10, -5))
		{
			if (exp((xn - 5) / 2) == 0)
				break;

			x0 = xn;

			xn = exp((x0 - 5) / 2);

			i++;
		}

	}

	cout << "xn = " << xn << endl << "yn = " << yn << endl << "Number of iterations: " << i << endl << endl;
}



int main()
{
	picardPeano();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
