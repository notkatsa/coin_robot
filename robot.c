#include <stdio.h>
#include <stdlib.h>
#include "robotrec.h"

int main(){
    int n, m, **A;
    scanf("%d", &n);
    scanf(" %d", &m);
    int i, j;
    A = malloc(n * sizeof(int*));
    if (A == NULL){
	printf("Sorry we couldn't allocate memory");
	return -1;
    }

    for (j=0; j<n; j++){
	 A[j] = malloc(m * sizeof(int));
	 if(A[j] == NULL){
	     printf("Sorry couldn't allccate memory");
	     return -1;
	 }
    }

    j=0, i=0;
    char ch=getchar(); //so it skips first \n
    while ((ch=getchar()) != EOF){
	if (ch=='.'){
	    A[i][j]=0;
	    j++;
	}
	else if(ch=='C'){
	    A[i][j]=1;
	    j++;
	}
	else{ // means we found \n so next line from the start
		j=0;
		i++;
	}
    }

    n--;
    m--;
// decrease n and m so I can work easier inside solve
    solve(n, m, A);
    for (j = 0; j<n; j++)
	    free(A[i]);
    free(A);
}
