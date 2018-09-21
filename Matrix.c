#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double ** mat;
	int m, n;
} matrix;

matrix initMatrix(int m , int n);
//to fill the matrix with zero 
void destroyMatrix(matrix T);
//to free the memory of a matrix
void Print(matrix T);
void Zerolize(matrix T);


matrix initMatrix(int m , int n){
	double ** pt;
	int i = 0;
	pt = (double ** ) malloc(m * sizeof(double *));
	for (i = 0; i < m; i ++){
		pt[i] = (double * ) malloc(n * sizeof(double));
	}
	matrix T;
	T.m = m;
	T.n = n;
	T.mat = pt;

	return T;
}

void destroyMatrix(matrix T){
	int i ;
	for (i = 0; i < T.m; i ++){
		free(T.mat[i]);
	}
	free(T.mat);
}

void Zerolize(matrix T){
	int i, j;
	for(i = 0 ; i < T.m; i ++){
		for (j = 0 ; j < T.n; j ++){
			T.mat[i][j] = 0;
		}
	}
}

void Print(matrix T){
	int i, j;
	for (i = 0; i < T.m; i++){
		for (j = 0; j < T.n; j++){
			printf("%.3f ", T.mat[i][j] );
		}
		printf("\n");
	}
}

int main(){
	matrix M = initMatrix(3, 4);
	printf("%f\n", M.mat[2][1]);
	Zerolize(M);
	Print(M);
	destroyMatrix(M);
	return 0;
}