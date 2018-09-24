Matrix : main.c Matrix.o 
	gcc main.c Matrix.o -o Matrix 

Matrix.o : Matrix.c Matrix.h
	gcc Matrix.c -c 

