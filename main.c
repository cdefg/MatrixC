#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Determinant.h"
#include "Inverse.h"

int main(){
	matrix M = initMatrix(4, 4);
	//matrix P = unitMatrix(3);

	Zerolize(M);
	
	M.mat[0][0] = 2;
	M.mat[1][0] = 0;
	M.mat[2][0] = 0;
	M.mat[3][0] = 1;

	
	M.mat[0][1] = 0;
	M.mat[1][1] = 2;
	M.mat[2][1] = 1;
	M.mat[3][1] = 0;


	M.mat[0][2] = 0;
	M.mat[1][2] = 1;
	M.mat[2][2] = 2;
	M.mat[3][2] = 0;


	M.mat[0][3] = 1;
	M.mat[1][3] = 2;
	M.mat[2][3] = 0;
	M.mat[3][3] = 0;

	

	

	Print(M);
	
	matrix InvM = Inverse(M);
	printf("\n");
	Print(InvM);

	destroyMatrix(M);
	//destroyMatrix(P);
	//destroyMatrix(Y);

	return 0;
}
