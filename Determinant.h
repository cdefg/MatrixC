#include "Matrix.h"

#ifndef _DETERMINANT_
#define _DETERMINANT_
double Determinant(matrix T);
//to calculate the determinant of a matrix
//this function will return a value
//to test if T is a square determinant before calculate
//using the method of recursion
//recursion is from function Step(), and this function is the kernel of this function
//require a function to make the Determinant a triangle Determinant
//call Step()

double Step(matrix T);
//to get some part of T into stage shape
//finally into trangle matrix to calculate the determinant
//the int has -1 and 1 options
//the function modifies the matrix T(but Determinant() will protect the original data)
//expand the first column when get T.mat[][0] = 0 to recursion

#endif