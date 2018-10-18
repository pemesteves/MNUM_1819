// TP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
	return (x - 2 * log(x) - 5);
}

double g(double x)
{
	return (2 * log(x) + 5);
}

double df(double x)
{
	return (1 - 2 / x);
}

double dg(double x)
{
	return (2 / x);
}

void bissection()
{
	double a, b, xn, ya, yxn;

	cout << "a? "; cin >> a;
	cout << "b? "; cin >> b;

	unsigned int i = 0;

	while (abs(a - b) >= pow(10, -5)) //abs: || ; pow: potencia(base, expoente)
	{
		xn = (a + b) / 2;

		ya = f(a); yxn = f(xn);

		cout << "f(a) = " << ya << " , f(b) = " << f(b) << " , f(xn) = " << yxn << endl;

		if (ya*yxn < 0)
			b = xn;
		else if (ya*yxn > 0)
			a = xn;
		else if (ya == 0)
		{
			cout << "Root: " << a << endl << "Number of iterations: " << i << endl << endl;
			return;
		}
		else
		{
			cout << "Root: " << xn << endl << "Number of iterations: " << i << endl << endl;
			return;
		}

		i++;
	}

	cout << "xn = " << xn << endl << "Number of iterations: " << i << endl << endl;
}

void falsePosition()
{
	double a, b, xn, ya, yb, yxn;

	cout << "a? "; cin >> a;
	cout << "b? "; cin >> b;

	unsigned int i = 0;

	while (abs(a - b) >= pow(10, -5)) //Está errado: condição de paragem xn - xn-1 < 10^-5
	{
		ya = f(a); yb = f(b);

		xn = (a*yb - b * ya) / (f(b) - f(a));

		yxn = f(xn);

		cout << "f(a) = " << ya << " , f(b) = " << f(b) << " , f(xn) = " << yxn << endl;

		if (yxn == 0)
		{
			cout << "Root: " << xn << endl << "Number of iterations: " << i << endl << endl;
			return;
		}

		b = xn;

		i++;
	}

	cout << "xn = " << xn << endl << "Number of iterations: " << i << endl << endl;
}

void newton()
{
	double x0, xn;

	cout << "x0? "; cin >> x0;

	xn = x0 - f(x0) / df(x0);

	unsigned int i = 0;

	while (abs(xn - x0) >= pow(10, -5))
	{
		if (df(x0) == 0)
		{
			cout << "df(x0) = 0";
			return;
		}

		x0 = xn;

		xn = x0 - f(x0) / df(x0);

		i++;
	}

	cout << "xn = " << xn << endl << "Number of iterations: " << i << endl << endl;
}

void picardPeano()
{
	double x0, xn;

	cout << "x0? "; cin >> x0;

	unsigned int i = 0;

	if (abs(dg(x0)) < 1)
	{
		xn = g(x0);

		while (abs(xn - x0) >= pow(10, -5))
		{
			if (g(xn) == 0)
				break;

			x0 = xn;

			xn = g(x0);

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

	cout << "xn = " << xn << endl << "Number of iterations: " << i << endl << endl;
}

int main()
{
	bissection();

	falsePosition();

	newton();

	picardPeano();

	return 0;
}
