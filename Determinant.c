#include "Determinant.h"
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

double Determinant(matrix T){
	//to check if T is a square matrix
	if (T.m != T.n){
		printf("Error : Input is not a square matrix when calculating its determinant.\n");
		exit(EXIT_FAILURE);
	}

	matrix S = Copy(T);
	//create another matrix to make sure T not modified

	return Step(S);
	destroyMatrix(S);
}

double Step(matrix T){
	if (T.m == 1){
		return T.mat[0][0];
	}
	double multiplier = 1;
	//to proceed the matrix
	if (T.mat[0][0] == 0){
		int k;
		double isallzero;//if isallzero is 0, then return 0 directly
		for (k = 0; k < T.m; k++){
			isallzero += (T.mat[k][0])*(T.mat[k][0]);
			if (T.mat[k][0] != 0){
				T = swapRow(T, 0, k);
				multiplier *= -1;
				break;
			}
		}
		if (isallzero == 0){
			return 0;
		}
	}

	//calculate with recursion

	int i;
	for (i = 1; i < T.m; i ++){
		T = AddMultipliedRow(T, i, 0, -1 * T.mat[i][0]/T.mat[0][0]);
	}//the first column has been transformed into zero except T.mat[0][0]
	

	matrix nextT = initMatrix(T.m - 1, T.m - 1);
	int p, q;
	for (p = 0; p < nextT.m; p++){
		for (q = 0; q < nextT.m; q++){
			nextT.mat[p][q] = T.mat[p + 1][q + 1];
		}
	}

	//copy the T into the next matrix to make recursion
	return multiplier * T.mat[0][0] * Step(nextT);
}