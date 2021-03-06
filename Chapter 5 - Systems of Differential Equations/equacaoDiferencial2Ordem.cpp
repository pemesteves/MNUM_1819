#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>
using namespace std;

inline double dy(double x, double y, double z) { //dy/dx
	return z;
}

inline double dz(double x, double y, double z) { //dz/dx
	return x - 3 * z - 2 * y;
}

inline double dy1(double x, double y, double z, double h) {
	return h * dy(x, y, z);
}

inline double dz1(double x, double y, double z, double h) {
	return h * dz(x, y, z);
}

inline double dy2(double x, double y, double z, double h) {
	return h * dy(x + h / 2, y + dy1(x, y, z, h) / 2, z + dz1(x, y, z, h) / 2);
}

inline double dz2(double x, double y, double z, double h) {
	return h * dz(x + h / 2, y + dy1(x, y, z, h) / 2, z + dz1(x, y, z, h) / 2);
}

inline double dy3(double x, double y, double z, double h) {
	return h * dy(x + h / 2, y + dy2(x, y, z, h) / 2, z + dz2(x, y, z, h) / 2);
}

inline double dz3(double x, double y, double z, double h) {
	return h * dz(x + h / 2, y + dy2(x, y, z, h) / 2, z + dz2(x, y, z, h) / 2);
}

inline double dy4(double x, double y, double z, double h) {
	return h * dy(x + h, y + dy3(x, y, z, h), z + dz3(x, y, z, h));
}

inline double dz4(double x, double y, double z, double h) {
	return h * dz(x + h, y + dy3(x, y, z, h), z + dz3(x, y, z, h));
}

pair<double, double> rk4(double x, double y, double z, double h) {
	double yn = 0, zn = 0;
	int i = 0.5 / h;
	ofstream f;
	f.open("file.txt");
	f << "plot2d([discrete,[";
	for (; i > 0; i--) {
		f << "[" << x << ", " << y << "],";
		yn = y + dy1(x, y, z, h) / 6 + dy2(x, y, z, h) / 3 + dy3(x, y, z, h) / 3 + dy4(x, y, z, h) / 6;
		zn = z + dz1(x, y, z, h) / 6 + dz2(x, y, z, h) / 3 + dz3(x, y, z, h) / 3 + dz4(x, y, z, h) / 6;
		y = yn;  z = zn;
		x += h;
	}
	f << "[" << x << ", " << y << "]]]); " << endl;
	cout << "(" << x << ", " << y << ", " << z << ")" << endl << endl;
	pair<double, double> p = make_pair(y, z);
	f.close();
	return p;
}

int main() { //TODO As 3 funções são iguais exceto o passo -> agrupar partes iguais e fazer funções para o passo
	double h = 0.05;
	pair<double, double> p, p1, p2;
	p = rk4(0, 0, 0, h);
	p1 = rk4(0, 0, 0, h / 2);
	p2 = rk4(0, 0, 0, h / 4);
	double qcy, qcz;
	qcy = (p1.first - p.first) / (p2.first - p1.first);
	qcz = (p1.second - p.second) / (p2.second - p1.second);
	cout << "QCy: " << qcy << endl;
	cout << "QCz: " << qcz << endl;

	double erroY, erroZ;
	erroY = (p2.first - p1.first) / 15;
	erroZ = (p2.second - p1.second) / 15;
	cout << "Erro Y: " << erroY << endl;
	cout << "Erro Z: " << erroZ << endl;
	return 0;
}
