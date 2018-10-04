#include <stdio.h>
#include <stdlib.h>
#include "Trace.h"
#include "Matrix.h"

double Trace(matrix T){
	if (T.m != T.n){
		printf("Error : not square , no trace value.");
		exit(EXIT_FAILURE);
	}
	
	double trace = 0;
	int i = 0;
	
	for (i = 0; i < T.m; i++){
		trace += T.mat[i][i];
	}
	
	return trace;
}
