#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

inline double dy(double x, double y, double z) { //dy/dx
	return x * y - z;
}

inline double dz(double x, double y, double z) { //dz/dx
	return x + y + z;
}

void euler(double x, double y, double z, double h) {
	double yn = 0, zn = 0;

	for (; x + h <= 1; x += h) {
		yn = y + h * dy(x, y, z);
		zn = z + h * dz(x, y, z);
		y = yn; z = zn;
	}
	cout << "(" << x << ", " << y << ", " << z << ")" << endl << endl;
}

void rk2(double x, double y, double z, double h) { //TODO Corrigir rk2
	double yn = 0, zn = 0;
	for (; x + h <= 1; x += h) {
		yn = y + h * dy(x + h / 2, y + h * dy(x, y, z) / 2, z + dz(x, y, z) / 2);
		zn = z + h * dz(x + h / 2, y + h * dy(x, y, z) / 2, z + dz(x, y, z) / 2);
		y = yn; z = zn;
	}
	cout << "(" << x << ", " << y << ", " << z << ")" << endl << endl;
}

inline double dy1(double x, double y, double z, double h) {
	return h * dy(x, y, z);
}

inline double dz1(double x, double y, double z, double h) {
	return h * dz(x, y, z);
}

inline double dy2(double x, double y, double z, double h) {
	return h * dy(x + h / 2, y + dy1(x, y, z, h) / 2, z + dz1(x, y, z, h));
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

void rk4(double x, double y, double z, double h) {
	double yn = 0, zn = 0;
	for (; x + h <= 1; x += h) {
		yn = y + dy1(x, y, z, h) / 6 + dy2(x, y, z, h) / 3 + dy3(x, y, z, h) / 3 + dy4(x, y, z, h) / 6;
		zn = z + dz1(x, y, z, h) / 6 + dz2(x, y, z, h) / 3 + dz3(x, y, z, h) / 3 + dz4(x, y, z, h) / 6;
		y = yn;  z = zn;
	}
	cout << "(" << x << ", " << y << ", " << z << ")" << endl << endl;
}

int main() { //TODO As 3 funções são iguais exceto o passo -> agrupar partes iguais e fazer funções para o passo
	double h = 0.1;
	euler(0, 0, 0, h);
	h = 0.1;
	rk2(0, 0, 0, h);
	h = 0.1;
	rk4(0, 0, 0, h);
	return 0;
}