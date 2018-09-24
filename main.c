#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Determinant.h"

int main(){
	matrix M = initMatrix(4, 4);
	//matrix P = unitMatrix(3);

	Zerolize(M);
	
	M.mat[0][0] = 7;
	M.mat[1][0] = 5;
	M.mat[2][0] = 3;
	M.mat[3][0] = 8;


	M.mat[0][1] = 9;
	M.mat[1][1] = 3;
	M.mat[2][1] = 6;
	M.mat[3][1] = 4;


	M.mat[0][2] = 6;
	M.mat[1][2] = 5;
	M.mat[2][2] = 1;
	M.mat[3][2] = 1;


	M.mat[0][3] = 7;
	M.mat[1][3] = 8;
	M.mat[2][3] = 8;
	M.mat[3][3] = 9;


	M.mat[0][4] = 9;
	M.mat[1][4] = 6;
	M.mat[2][4] = 2;
	M.mat[3][4] = 3;



	Print(M);
	double detM = Determinant(M);
	printf("%.6f\n", detM );
	//Print(P);

	destroyMatrix(M);
	//destroyMatrix(P);
	//destroyMatrix(Y);

	return 0;
}