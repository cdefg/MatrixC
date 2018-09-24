main : main.c Matrix.o Determinant.o
	gcc main.c Matrix.o Determinant.o -o Matrix 

Matrix.o : Matrix.c Matrix.h
	gcc Matrix.c -c 

Determinant.o : Determinant.c Determinant.h
	gcc Determinant.c -c

