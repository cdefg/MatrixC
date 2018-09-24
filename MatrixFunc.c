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
