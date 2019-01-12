#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

inline double f(double x) {
	return (pow(2 * x + 1, 2) - 5 * cos(10 * x));
}

void tercos(double x1, double x2) {
	double x3 = 0, x4 = 0;
	while (abs(x2 - x1) >= pow(10, -3)) {
		x3 = x1 + (x2 - x1) / 3;
		x4 = x1 + 2 * (x2 - x1) / 3;

		if (f(x4) < f(x3))
			x1 = x3;
		else if (f(x4) > f(x3))
			x2 = x4;
		else
			break;
	}
	double result = 0;
	if (f(x3) < f(x4))
		result = x4;
	else 
		result = x3;

	cout << "Tercos: " << result << endl;
}

void regraAurea(double x1, double x2, bool maximo) {
	double x3, x4;
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	while (abs(x2 - x1) >= pow(10, -3)) {
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
		if (!maximo) {
			if (f(x3) < f(x4))
				x2 = x4;
			else if (f(x3) > f(x4))
				x1 = x3;
			else
				break;
		}
		else {
			if (f(x3) < f(x4))
				x1 = x3;
			else if (f(x3) > f(x4))
				x2 = x4;
			else
				break;
		}
	}

	double result; 

	if (maximo) {
		cout << "Maximo: ";
		if (f(x3) >= f(x4))
			result = x3;
		else if (f(x3) < f(x4))
			result = x4;
	}
	else {
		cout << "Minimo: ";

		if (f(x3) >= f(x4))
			result = x4;
		else if (f(x3) < f(x4))
			result = x3;
	}
	cout << result << endl;
}


inline double f(double x, double y) {
	return pow(y, 2) - 2 * x*y - 6 * y + 2 * pow(x, 2) + 12;
}

inline double f1(double x, double y) {
	return (2 * x*y + 2 * x - pow(x, 2) - 2 * pow(y, 2));
}

void metodoDoGradiente(double x, double y, double h, bool maximo) {
	//gradiente: -2*y+4*x; 2*y-2*x-6
	double xn = x, yn = y;


	do {
		x = xn;
		y = yn;
		if (!maximo) {
			xn = x - h * (-2 * y + 4 * x);
			yn = y - h * (2 * y - 2 * x - 6);
			if (f(xn, yn) > f(x, y))
				h /= 2;
			else if (f(xn, yn) < f(x, y))
				h *= 2;
			else
				break;
		}
		else {
			xn = x + h * (2 * y + 2 - 2 * x);
			yn = y + h * (2 * x - 2 * y);
			if (f1(xn, yn) < f1(x, y))
				h /= 2;
			else if (f1(xn, yn) > f1(x, y))
				h *= 2;
			else
				break;
		}
	} while (abs(xn - x) >= pow(10, -3) || abs(yn - y) >= pow(10, -3));

	if (maximo) {
		cout << "Maximo: ";
	}
	else {
		cout << "Minimo: ";
	}

	cout << (xn + x) / 2 << "; " << (yn + y) / 2 << endl;
}

void metodoDaQuadrica(double x, double y, bool maximo) {
	//gradiente: -2*y+4*x; 2*y-2*x-6
	double xn = x, yn = y;
	double H;
	if (maximo)
		H = (double)1 / 4;
	else
		H = (double)1 / 12; //Inverso do determinante da matriz hessiana

	do {
		x = xn; y = yn;
		if (!maximo) {
			xn = x - H * (-2 * y + 4 * x);
			yn = y - H * (2 * y - 2 * x - 6);
		}
		else {
			xn = x + H * (2 * y + 2 - 2 * x);
			yn = y + H * (2 * x - 4 * y);
		}
	} while (abs(xn - x) >= pow(10, -3) || abs(yn - y) >= pow(10, -3));

	if (maximo)
		cout << "Maximo: ";
	else
		cout << "Minimo: ";

	cout << (xn + x) / 2 << "; " << (yn + y) / 2 << endl;
}

int main() {
	tercos(-1, 0);
	system("pause");
	regraAurea(-1, 0, false);
	regraAurea(-1, 0, true);
	system("pause");
	metodoDoGradiente(1, 1, 1, false);
	metodoDoGradiente(1, 1, 1, true);
	system("pause");
	metodoDaQuadrica(1, 1, false);
	metodoDaQuadrica(1, 1, true);
	return 0;
}