#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

double SquareSumOfRow(matrix T, int row){
	if (row >= T.m ){
		printf("Error : Row index exceeds the minimal of m or n.");
		exit(EXIT_FAILURE);
	}
	
	double sum = 0;
	int i;
	for (i = 0; i < T.n; i++){
		sum += (T.mat[row][i])*(T.mat[row][i]);
	}
	
	return sum;
}

int Rank(matrix T){
	int rank = 0;
	//default : 0 as no value
	
	matrix S = Copy(T);
	
	if (S.m > S.n){
		S = Transpose(S); 
	}//to make m < n , so we only need to use row transformations.
	
	int i, j, k;
	//identifiers to loop
	
	for (i = 0; i < S.m; i++){
		if (S.mat[i][i] == 0){
			for (j = i + 1; j < S.m; j++ ){
				if ( S.mat[j][i] != 0){
					swapRow(S, i, j);
				}
			}
			if (j = S.m){
				continue;
			}
		}
		
		for (k = i + 1; k < S.m; k++){
			S = AddMultipliedRow(S, k, i, -1 * ((S.mat[k][i])/(S.mat[i][i])));
		}
	}
	//to make the matrix a row-stage matrix
	
	for (i = 0; i < S.m; i++){
		if(SquareSumOfRow(S, i) > 0){
			rank += 1;
		}
	}
	
	return rank;
	
	destroyMatrix(S);
	//clean the memory
} 
