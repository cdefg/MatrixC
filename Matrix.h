//this file include the struct data and the function prototype

/*
 *struct : a matrix A [m x n]
 *row: m ; column : n ; array : mat
 */
#ifndef _MATRIX_
#define _MATRIX_

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

#endif