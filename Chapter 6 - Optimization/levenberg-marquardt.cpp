#include <iostream>
#include <cmath>

using namespace std;

inline double f(double x, double y) {
	return pow(x + 1, 2) + pow(y - 4, 2);
}

inline double gradient_x(double x, double y) {
	return 2 * x + 2;
}

inline double gradient_y(double x, double y) {
	return 2 * y - 8;
}

inline double hessian(double x, double y) {
	return 1.0 / 4.0;
}

inline double f1(double x, double y) {
	return pow(y, 2) - 2 * x*y - 6 * y + 2 * pow(x, 2) + 15 * cos(10 * x);
}

inline double gradient_x1(double x, double y) {
	return -2 * y + 4 * x - 10 * sin(10 * x);
}

inline double gradient_y1(double x, double y) {
	return 2 * y - 2 * x - 6;
}

inline double hessian1(double x, double y) {
	return -1.0 / (200 * cos(10 * x) - 4);
}

void levenbergMarquardt(double x, double y, double step, int tol, double f(double, double), double gradient_x(double, double), double gradient_y(double, double), double hessian(double, double)) {
	double xn = x, yn = y;
	double hLM_x = 0, hLM_y = 0;
	do {
		x = xn; y = yn;
		hLM_x = hessian(x, y) * gradient_x(x, y) + step * gradient_x(x, y);
		xn = x - hLM_x;
		hLM_y = hessian(x, y) * gradient_y(x, y) + step * gradient_y(x, y);
		yn = y - hLM_y;
		if (f(xn, yn) < f(x, y))
			step /= 2;
		else if (f(xn, yn) > f(x, y))
			step *= 2;
		else
			break;

	} while (abs(xn - x) >= pow(10, tol) || abs(yn - y) >= pow(10, tol));

	cout << "Minimo: ";
	cout << (xn + x) / 2 << "; " << (yn + y) / 2 << endl;
}

int main() {
	lavembergMarquardt(0, 0, 0.1, -5, f, gradient_x, gradient_y, hessian);
	lavembergMarquardt(1, 1, 0.01, -3, f1, gradient_x1, gradient_y1, hessian1);
	system("pause");
	return 0;
}
