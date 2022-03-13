#include <stdio.h>
#include <stdlib.h>
int findpath(int n, int m, int** A, int** p);

int solve(int n,int m, int** A){
	int** p;
	int i, j;
	p = malloc(n*sizeof(int*));
	for (j=0; j<=n; j++){
		p[j]=malloc(m*sizeof(int));
	}
/* in the table that was filled with 0, we loop though it and add coins as we go */
	for (i=0; i<=n; i++){
		for (j=0; j<=m; j++){
			if (i==0 && j==0) p[i][j] = A[i][j];
			else if (i==0) p[i][j] = A[i][j] + p[i][j-1];
			else if (j==0) p[i][j] = A[i][j] + p[i-1][j];
			else {
				if (p[i][j-1]>=p[i-1][j]) p[i][j] = p[i][j-1]+A[i][j];
				else p[i][j] = p[i-1][j] +A[i][j];
			}
		}
	}
	printf("Path is:");
	findpath(n, m, A, p);
	printf(" Picked up %d coins\n", p[n][m]);
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
