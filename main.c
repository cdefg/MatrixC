#include <stdio.h>
#include <stdlib.h>
#include "MatrixFunc.h"
#include "MatrixFunc.c"
/*
 *struct : a matrix A [m x n]
 *row: m ; column : n ; array : mat
 */

typedef struct{
	double ** mat;
	int m, n;
} matrix;

matrix initMatrix(int m , int n);
//to create a matrix full of zero 
//One check is used to make sure that m and n is positive
//When other Functions call this function, no need to check whether its dimension is positive.
matrix unitMatrix(int n);
//to generate a unit matrix whose dimension is n
//return a matrix
void destroyMatrix(matrix T);
//to free the memory of a matrix //T destroyed
void Print(matrix T);
//to print a matrix     // no need to be modified
matrix Zerolize(matrix T);
//to get all elements into 0 //T modified
matrix Copy(matrix T);
//to copy a matrix 
//create a new matrix and return to it
matrix Add(matrix T, matrix S);
// One  matrix created and returned
//to get 2 matrixes added  
//T and S not modified
matrix Substract(matrix T, matrix S);//One matrix created
//to calculate T - S
//substract is a special circumstance for Add()
// One matrix created and returned , as it is in Add()
//T and S not modified , as it is in Add()
matrix MinusMatrix(matrix T);
//to get -A  for  matrix A 
//T not modified
//One more Matrix created and returned
//Almost the same with Copy() except the sign to multiply
matrix Multiply(matrix T, matrix S);
//to get the result of T(mxp) x S(pxn) (into result R(mxn))
//create a new matrix, T/S not modified.
matrix Transpose(matrix T);
//to get the transpositon form of matrix T
//create a new matrix and return to it
matrix swapRow(matrix T, int i, int j);
//to swap the j and i row
//create a new matrix and return to it 
//i and j is the order inside C programming language, start from 0, so calling requires modify(GUI)
matrix swapCol(matrix T, int i, int j);
//to swap the j and i column
//create a new matrix and return to it
//i and j is the order inside C programing language, start from 0, so calling requires modiry(GUI)
matrix multiRow(matrix T, int i, double k);
//to make the i-th row of T multiply k
//generate a new matrix and return to it
//same order regulation as swapCol() and swapRow()
matrix multiCol(matrix T, int i, double k);
//to make the i-th column of T multiply k
//generate a new matrix and return to it
//same order regulation as swapCol() and swapRow()
matrix AddMultipliedRow(matrix T, int i, int j, double k);
//as the third kind of elementary transformation
//the i-th row add the j-th row cross k
//i = i + j * k
//generate a new matrix and return to it

matrix AddMultipliedCol(matrix T, int i, int j, double k);
//as the third kind of elementary transformation
//the i-th column add the j-th column cross k
//i = i + j * k
//generate a new matrix and return to it


/*double Determinant(matrix T);
//to calculate the Determinant for Matrix T
//create and return a value 
//Triangulate() is the main part, so this function will never run successfully unless Triangulate() runs stably
matrix Triangulate(matrix T, int );
//to get a Square Matrix into a Triangle Square Matrix
//create a new matrix and return to it, T not modified*/

matrix initMatrix(int m , int n){

	if (!(m > 0 || n > 0)){
		printf("Fatal : the Dimension of a Matrix MUST be positive.\n");
		exit(EXIT_FAILURE);
	}

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

matrix unitMatrix(int n){
	matrix E = Zerolize(initMatrix(n, n));
	int i ;
	for (i = 0; i < n; i++){
		E.mat[i][i] = 1;
	}
	return E;
}

void destroyMatrix(matrix T){
	int i ;
	for (i = 0; i < T.m; i ++){
		free(T.mat[i]);
	}
	free(T.mat);
}

matrix Zerolize(matrix T){
	int i, j;
	for(i = 0 ; i < T.m; i ++){
		for (j = 0 ; j < T.n; j ++){
			T.mat[i][j] = 0;
		}
	}
	return T;
}

matrix Copy(matrix T){
	matrix S =initMatrix(T.m, T.n);
	int i , j;
	for (i = 0; i < T.m; i++){
		for (j = 0; j < T.n; j++){
			S.mat[i][j] = T.mat[i][j];
		}
	}
	return S;
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

matrix Add(matrix T, matrix S){
//to check the two matrix : of same dimension
	if (T.m != S.m || T.n != S.n){
		printf("Dimensions are not Same\n");
		exit(EXIT_FAILURE);
	}
//create a temp matrix
	matrix M = Zerolize(initMatrix(T.m, T.n));
	
	int i , j;
	for (i = 0; i < T.m; i++){
		for (j = 0; j < T.n; j++){
			M.mat[i][j] = T.mat[i][j] + S.mat[i][j];
		}
	}

	return M;
}

matrix MinusMatrix(matrix T){
	matrix S =initMatrix(T.m, T.n);
	int i , j;
	for (i = 0; i < T.m; i++){
		for (j = 0; j < T.n; j++){
			S.mat[i][j] = (-1) * T.mat[i][j];
		}
	}
	return S;
}

matrix Substract(matrix T, matrix S){
	return Add(T, MinusMatrix(S));
}

matrix Multiply(matrix T, matrix S){
	if(T.n != S.m){
		printf("Invalid Multiplication: Dimension Error\n");
		exit(EXIT_FAILURE);
	}

	matrix R = Zerolize(initMatrix(T.m, S.n));

	int i , j, k;
	for (i = 0; i < R.m; i++){
		for (j = 0; j < R.n; j++){
			for (k = 0; k < T.n; k++){
				R.mat[i][j] += T.mat[i][k] * S.mat[k][j];
			}
		}
	}

	return R;
}

matrix Transpose(matrix T){
	matrix R = Zerolize(initMatrix(T.n, T.m));
	int i, j;
	for (i = 0; i < R.m; i++){
		for (j = 0; j < R.n; j++){
			R.mat[i][j] = T.mat[j][i];
		}
	}
	return R;
}

matrix swapRow(matrix T, int i, int j){

	if (i >= T.m || j >= T.m || i < 0 || j < 0 || i == j){
		printf("Error : Row index exceeded.\n");
		exit(EXIT_FAILURE);
	}//check if i, j is between 0 and n-1

	matrix P = unitMatrix(T.m);

	P.mat[i][i] = P.mat[j][j] = 0;
	P.mat[i][j] = P.mat[j][i] = 1;

	return Multiply(P, T);
}

matrix swapCol(matrix T, int i, int j){

	if (i >= T.n || j >= T.n || i < 0 || j < 0 || i == j){
		printf("Error : Row index exceeded.\n");
		exit(EXIT_FAILURE);
	}//check if i, j is between 0 and n-1 or i == j

	matrix P = unitMatrix(T.n);

	P.mat[i][i] = P.mat[j][j] = 0;
	P.mat[i][j] = P.mat[j][i] = 1;

	return Multiply(T, P);
}

matrix multiRow(matrix T, int i, double k){
	if (i >= T.m || i < 0 ){
		printf("Error : Row index exceeded.\n");
		exit(EXIT_FAILURE);
	}

	if (k == 0){
		printf("Warning : You can not multiply 0 in elementary transformation\n");
	}

	matrix P = unitMatrix(T.m);
	P.mat[i][i] *= k;
	return Multiply(P, T);
}

matrix multiCol(matrix T, int i, double k){
	if (i >= T.n || i < 0){
		printf("Error : Column index exceeded.\n");
		exit(EXIT_FAILURE);
	}
	if (k == 0){
		printf("Warning : You can not multiply 0 in elementary transformation\n");
	}

	matrix P = unitMatrix(T.n);
	P.mat[i][i] *= k;
	return Multiply(T, P);
}

matrix AddMultipliedRow(matrix T, int i, int j, double k){
	//i = i + j * k
	if (i >= T.m || j >= T.m || i < 0 || j < 0 || i == j){
		printf("Error : Row index exceeded.\n");
		exit(EXIT_FAILURE);
	}//check if i, j is between 0 and n-1

	matrix P = unitMatrix(T.m);
	P.mat[i][j] = k;

	return Multiply(P, T);
}

matrix AddMultipliedCol(matrix T, int i, int j, double k){
	//i = i + j * k
	if (i >= T.n || j >= T.n || i < 0 || j < 0 || i == j){
		printf("Error : Column index exceeded.\n");
		exit(EXIT_FAILURE);
	}//check if i, j is between 0 and n-1

	matrix P = unitMatrix(T.n);
	P.mat[j][i] = k;

	return Multiply(T, P);
}

/*matrix Triangulate(matrix T){
	if (T.m != T.n){
		printf("Fatal : the Matrix entered is not a square Matrix\n");
		exit(EXIT_FAILURE);
	}



	if (T.m > 1){

	}

	else{
		return T;
	}
}

double Determinant(matrix T){
	if (T.m != T.n){
		printf("Fatal : the Matrix entered is not a square Matrix\n");
		exit(EXIT_FAILURE);
	}

	int i, j;



	double result = 0;

	for (i = 0; i < T.m ; i ++){
		result += T.mat[i][i];
	}
}*/

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