
#include <stdio.h>
#include <stdlib.h>
int rec(int n, int m, int** A, int** p){
/* check to see if that block has been previously calculated, if it hasn't calculate it
and return it, if it has just return it */
	char temp;
	if (n == 0 && m == 0){
		return A[n][m];
	}
	else if (n == 0){
		if (p[n][m]!=-1){
			return (p[n][m]);
		}
		p[n][m] = A[n][m] + rec(n, (m-1), A, p);
		return p[n][m];
	}
	else if (m == 0){
		if(p[n][m]!=-1)return (p[n][m]);
		p[n][m] = A[n][m] + rec((n-1), m, A, p);
		return p[n][m];

	}
	else {
		int n1, n2;
		if (p[n][m-1]==-1){
			p[n][m-1]=rec(n, (m-1), A, p);
		}
		n1=p[n][m-1];

		if (p[n-1][m]==-1){
			p[n-1][m]=rec((n-1), m, A, p);
		}
		n2 = p[n-1][m];
		if (n1 >= n2){
			if (p[n][m]==-1) p[n][m] = A[n][m] + n1;
			return p[n][m];
		}
		else{
			if (p[n][m]==-1) p[n][m] = A[n][m] + n2;
			return p[n][m];
		}
	}
}



int findpath(int n, int m, int** A, int** p){
	char spot;
	if(n==0 && m==0){
		if (A[n][m]==1) spot= 'C';
		else spot='.';
		printf(" %c(%d,%d)/%d", spot, n+1, m+1, A[n][m]);
		return;
	}
	else if (n==0){
		findpath(n,m-1,A,p);
	}
	else if (m==0){
		findpath(n-1,m,A,p);
	}
	else{
		if(p[n-1] > p[n][m-1]) findpath(n-1, m, A, p);
		else findpath(n,m-1,A,p);
	}
	if(A[n][m]==1) spot='C';
	else spot='.';
	printf(" %c(%d,%d)/%d -->", spot, n+1, m+1, p[n][m]);
	return;
}

int solve(int n, int m, int** A){

/* making a table p and filling it with -1. In rec it will
get filled with the amount of coins collected up to that point */
	int **p;
	p = malloc((n+1)*sizeof(int*));
	for (int i=0; i<=n; i++) p[i]=malloc((m+1)*sizeof(int));
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			p[i][j]=-1;
		}
	}

        int coins = rec(n,m,A,p);
	printf("Path is:");
	findpath(n, m, A, p);
	printf(" Picked up %d coins\n", coins);
}
