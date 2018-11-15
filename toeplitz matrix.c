/*
 Program to determine if a matrix is a Toeplitz matrix.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void check(void *p) {
    if (p == NULL) {
        printf("Error!\n");
        exit(1);
    }
}

// Function to determine if matrix is a Toeplitz matrix
int checkT(int **matrix,int N, int M) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 1; j++)
            if (matrix[i][j] != matrix[i + 1][j + 1])
                return 0;
    return 1;
}

int main() {
    int N,M, i, j;
    int **A;
    printf("Enter 2 integers (matrix dimension): ");
    scanf("%d %d", &N,&M);
    
    A = (int **)malloc(N * sizeof(int *));
    check(A);
    for (i = 0; i < N; i++) {
        A[i] = (int *)malloc(M * sizeof(int));
        check(A[i]);
    }
    
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++) {
            printf("A[%d][%d]=", i, j);
            scanf("%d", &A[i][j]);
        }
    
    if (checkT(A,N,M))
        printf("Matrix is a Toepliz matrix.");
    else
        printf("Matrix is not a Toepliz matrix.");
    
    for (i = 0; i < N; i++)
        free(A[i]);
    free(A);
    
    return 0;
}
