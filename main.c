#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Determinant.h"
#include "Inverse.h"
#include "Trace.h"
#include "Rank.h"

int main(){
	matrix M = initMatrix(4, 5);
	//matrix P = unitMatrix(3);

	Zerolize(M);
	
	M.mat[0][0] = 0;
	M.mat[1][0] = 0;
	M.mat[2][0] = 0;
	M.mat[3][0] = 0;

	
	M.mat[0][1] = 0;
	M.mat[1][1] = 0;
	M.mat[2][1] = 0;
	M.mat[3][1] = 0;


	M.mat[0][2] = 0;
	M.mat[1][2] = 0;
	M.mat[2][2] = 0;
	M.mat[3][2] = 0;


	M.mat[0][3] = 0;
	M.mat[1][3] = 0;
	M.mat[2][3] = 0;
	M.mat[3][3] = 0;

	
	M.mat[0][4] = 0;
	M.mat[1][4] = 0;
	M.mat[2][4] = 0;
	M.mat[3][4] = 0;
	

	Print(M);
	
	//printf("the trace of M : %.4f", Trace(M));
	printf("rank of the matrix:%d\n", Rank(M));
	//matrix InvM = Inverse(M);
	//printf("Inverse : \n");
	//Print(InvM);

	destroyMatrix(M);
	//destroyMatrix(P);
	//destroyMatrix(Y);

	return 0;
}
