#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<double>> matrix;

void rowop(matrix &m, size_t i, size_t j, double value) {
	for (size_t k = 0; k < m[0].size(); k++) {
		m[i][k] -= value * m[j][k];
	}
}

void pivotagem_parcial(matrix &m) {

	for (size_t i = 0; i < m.size(); i++) {
		size_t maior_elem = i;
		for (size_t j = i + 1; j < m.size(); j++) {
			if (m[i][j] > m[i][maior_elem])
				maior_elem = j;
		}

		if (maior_elem != i) {
			for (size_t j = 0; j < m[i].size(); j++) {
				double tmp = m[i][j];
				m[i][j] = m[maior_elem][j];
				m[maior_elem][j] = tmp;
			}
		}

		rowop(m, i, i, 1 - 1 / m[i][i]);
		for (size_t j = 0; j < m.size(); j++) {
			if (i != j)
				rowop(m, j, i, m[j][i]);
		}
	}
}
int main() {

	matrix m = { {0.00001, 2, 5, 200}, {1, -0.2, 1, 4}, {3, 0.5, -4, 2} };
	pivotagem_parcial(m);

	for (size_t i = 0; i < m.size(); i++) {
		for (size_t j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
