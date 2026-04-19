#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int m, n, i, j,k, v, u,r,p;
	double eps = 0.000001;
	double z,c;
	cin >> m >> n;
	int* L = new int[n];
	for (i = 0; i < n; i++)L[i] = i;
	double** A = new double* [m];

	double* X = new double[n];

	for (i = 0; i < m; i++)A[i] = new double[n + 1];

	for (i = 0; i < m; i++) {
		for (j = 0; j < n + 1; j++)cin >> A[i][j];
	}//创建矩阵


	i = 0;
	if (n < m)r = n; else r = m;
	while (i < r) {
		v = i; u = i;
		for (j = i; j < m; j++) {
			for (k = i; k < n; k++)if (abs(A[j][k]) > abs(A[v][u])) {
				v = j; u = k;
			}
			//选择主元
		}

		if (abs(A[v][u]) < eps)r = i;
		else {
			if (v != i)for (j = i; j < n + 1; j++) {
				z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
			}


			if (u != i) {
				for (k = 0; k < m; k++) {
					z = A[k][i]; A[k][i] = A[k][u]; A[k][u] = z;
				}
				p = L[i]; L[i] = L[u]; L[u] = p;
			}//行列交换



			c = A[i][i];
			for (j = i; j < n + 1; j++)A[i][j] /= c;//主元行归一

			for (k = 0; k < m; k++) {
				if (k != i) {
					c = A[k][i];
					for (j = i; j < n + 1; j++)A[k][j] -= c * A[i][j];
				}

			}//完全消行
			i++;
		}
	}
		i = r;
		while (i < m && abs(A[i][n]) < eps)i++;
		if (i < m)cout << "don not exist" << endl;
		else if (r == n) {
			for (j = 0; j < n; j++)X[L[j]] = A[j][n];
			cout << "There is a unique solution:" << endl;
			for (j = 0; j < n; j++)cout << X[j] << " ";
		}
		else {
			cout << "There are infinitely many solutions; substitute specific values." << endl;

			for (k = r; k < n; k++)
				cin >> X[L[k]];

			for (j = 0; j < r; j++) {
				X[L[j]] = A[j][n];
				for (k = r; k < n; k++)X[L[j]] -= A[j][k]*X[L[k]];




			}
			for (j = 0; j < n; j++)cout << X[j] << " ";


		}






		delete[] L;
		for (i = 0; i < m; i++)delete[] A[i];
		delete[]A;
		delete[]X;











	return 0;
}