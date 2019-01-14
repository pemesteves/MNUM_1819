#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double df(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

int main()
{
	double x = 0, y = 0, h = 0.1;
	double xi1 = 0, yi1 = 0;

	for (; x <= 1.4; x += h) {
		xi1 = x + h / 2.0;
		yi1 = y + h * df(x, y) / 2.0;
		y = y + df(xi1, yi1)*h;
	}
		
	cout << "(" << x << "; " << y << ")" << endl;

	return 0;
}