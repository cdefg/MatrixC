#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(){
	matrix M = initMatrix(3, 2);
	//matrix P = unitMatrix(3);

	Zerolize(M);
	
	M.mat[0][0] = 4;
	M.mat[1][0] = 5;
	M.mat[2][0] = 6;
	M.mat[0][1] = 9;
	M.mat[1][1] = 8;
	M.mat[2][1] = 7;


	Print(M);
	Print(AddMultipliedCol(M, 0, 1, 1));
	//Print(P);

	destroyMatrix(M);
	//destroyMatrix(P);
	//destroyMatrix(Y);

	return 0;
}