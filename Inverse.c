#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Determinant.h"
#include "Inverse.h"

matrix Inverse(matrix T){
	//to check if T is a square matrix
	if (T.m != T.n){
		printf("Error : the matrix to be inversed is not a square matrix.");
		exit(EXIT_FAILURE);
	}
	
	if (Determinant(T) == 0){
		printf("Error : the matrix to be inversed is not a reversible matrix.");
		exit(EXIT_FAILURE);
		//make sure that one column or row cannot be all 0.
	}
	
	matrix S = Copy(T);//S instead of T is modified.
	matrix R = unitMatrix(S.m);
	
	int i, j, k;//loop identifiers
	
	for (i = 0; i < S.m; i++){
		if (S.mat[i][i] == 0){
			for (k = i + 1; k < S.m; k++){
				if (S.mat[k][i] != 0){
					S = swapRow(S, i, k);
					R = swapRow(R, i, k);
					break;
				}
			}	
		}//to make sure that there is no 0 in the diagonal.
		for (j = i + 1; j < S.m; j++ ){
			R = AddMultipliedRow(R, j, i, -1*((S.mat[j][i])/(S.mat[i][i])));
			S = AddMultipliedRow(S, j, i, -1*((S.mat[j][i])/(S.mat[i][i])));
			//the change of R MUST be before S's.
			//this is FATALLY important!!
		}
		//to make the matrix one up-triangle matrix.
	}
	
	
	for (i = S.m - 1; i > 0; i --) {
		for (j = i - 1; j >= 0; j --){
			R = AddMultipliedRow(R, j, i, -1*((S.mat[j][i])/(S.mat[i][i])));
			S = AddMultipliedRow(S, j, i, -1*((S.mat[j][i])/(S.mat[i][i])));
		}
	}
	//to make the up-triangle matrix a diagonal matrix.
	
	for (i = 0; i < S.m ; i++){
		R = multiRow(R, i, 1/S.mat[i][i]);
		S = multiRow(S, i, 1/S.mat[i][i]);
	}	

	return R;//R is the inversed matrix
	destroyMatrix(R);
	destroyMatrix(S);
}
