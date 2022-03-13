#include <stdio.h>
int rec(int n, int m, int** A){
/* solving the problem recursively following the math provided in ekfwnhsh */
	if (n == 0 && m == 0) return A[n][m];
	else if (n == 0) return (A[n][m] + rec(n, (m-1), A));
	else if (m == 0) return (A[n][m] + rec((n-1), m, A));
	else {
		int n1 = rec(n, (m-1), A);
		int n2 = rec((n-1), m, A);
		if ( n1 >= n2 ) return (A[n][m] + n1);
		else return (A[n][m] + n2);
	}
}

int solve(int n, int m, int** A){
	int coins = rec(n,m,A);
	printf("Maximum number of coins to pick up is: %d \n", coins);
}
