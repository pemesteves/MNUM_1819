#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

void rowop(vector<vector<double>> &matrix, size_t i, size_t j, double value) {
	for (size_t k = 0; k < matrix[0].size(); k++) {
		matrix[i][k] -= value * matrix[j][k];
	}
}

void sistemasEquacoesLineares(vector<vector<double>> &matrix) {
	for (size_t i = 0; i < matrix.size(); i++) {
		rowop(matrix, i, i, 1 - 1 / matrix[i][i]);
		for (size_t j = 0; j < matrix.size(); j++) {
			if (i != j)
				rowop(matrix, j, i, matrix[j][i]);
		}
	}
}

double f(double x1, double x2, double x3) {
	return (7 - x2 - x3) / 3;
}

double g(double x1, double x2, double x3) {
	return (4 - x1 - 2 * x3) / 4;
}

double h(double x1, double x2, double x3) {
	return (5 - 2 * x2) / 5;
}

void gaussJacobi(double x1, double x2, double x3) {
	double xn1 = f(x1, x2, x3), xn2 = g(x1, x2, x3), xn3 = h(x1, x2, x3);
	unsigned i = 1;
	while (abs(xn1 - x1) >= pow(10, -5) || abs(xn2 - x2) >= pow(10, -5) || abs(xn3 - x3) >= pow(10, -5)) {
		x1 = xn1; x2 = xn2; x3 = xn3;
		xn1 = f(x1, x2, x3);
		xn2 = g(x1, x2, x3);
		xn3 = h(x1, x2, x3);
		i++;
	}
	cout << x1 << "; " << x2 << "; " << x3 << endl;
	cout << i << endl;
}

void gaussSeidel(double x1, double x2, double x3) {
	double xn1 = f(x1, x2, x3), xn2 = g(xn1, x2, x3), xn3 = h(xn1, xn2, x3);
	unsigned i = 1;
	while (abs(xn1 - x1) >= pow(10, -5) || abs(xn2 - x2) >= pow(10, -5) || abs(xn3 - x3) >= pow(10, -5)) {
		x1 = xn1; x2 = xn2; x3 = xn3;
		xn1 = f(x1, x2, x3);
		xn2 = g(xn1, x2, x3);
		xn3 = h(xn1, xn2, x3);
		i++;
	}
	cout << x1 << "; " << x2 << "; " << x3 << endl;
	cout << i << endl;
}

int main() {
	vector<vector<double>> matrix;
	vector<double> line;
	line = { 3, -1, 2, -1 };
	matrix.push_back(line);
	line = { 1, 1, 1, 8 };
	matrix.push_back(line);
	line = { 2, 0, 1, 5 };
	matrix.push_back(line);
	line.clear();
	sistemasEquacoesLineares(matrix);

	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	gaussJacobi(0, 0, 0);
	gaussSeidel(0, 0, 0);
	return 0;
}
