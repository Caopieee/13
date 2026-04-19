#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
using namespace std;
int main() {
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	int m, n,i,j,r,v,k;
	fscanf(in, "%d %d", &m, &n);
	double** A = new double* [m];
	for (i = 0; i < m; i++) {
		A[i] = new double[n + 1];
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n+1; j++)fscanf(in, "%lf", &A[i][j]);
	}


	double z,c;
	double eps = 0.000001;
	for (r = 0, i = 0; (r < m) && (i < n ); i++) {
		v = r;
		for (j = r; j < m; j++)if (fabs(A[j][i]) > fabs(A[v][i]))v = j;
		if (fabs(A[v][i]) < eps)continue;
		else {
			if(v!=r)
				for (j = i; j < n + 1; j++) {
					z = A[r][j]; A[r][j] = A[v][j]; A[v][j] = z;
				}
			for (j = r + 1; j < m; j++) {
				c = A[j][i] / A[r][i];
					for(k = i; k < n + 1; k++)A[j][k] -= c * A[r][k];


			}
			r++;


		}








	}














	for (i = 0; i < m; i++) {
		for (j = 0; j < n+1; j++)fprintf(out, "%lf\t", A[i][j]);
		fprintf(out, "\n");
	}



	fclose(in);
	fclose(out);

	for (i = 0; i < m; i++) delete[] A[i];
	delete[] A;


	return 0;
}