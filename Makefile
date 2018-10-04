main : main.c Matrix.o Determinant.o Inverse.o
	gcc main.c Matrix.o Determinant.o Inverse.o -o Matrix 

Matrix.o : Matrix.c Matrix.h
	gcc Matrix.c -c 

Determinant.o : Determinant.c Determinant.h
	gcc Determinant.c -c
	
Inverse.o : Inverse.c Inverse.h
	gcc Inverse.c -c

