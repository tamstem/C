/*
 -Define function f(x) = sqrt(x)
 -Define function
 void F(int N, double **X, double (*g)(double))
 which for N × N real matrix X and for function g computes g(Xij) for i, j = 1, ..., N.
 
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double f(double x) {
    return sqrt(x);
}

void F(int N, double **X, double (*g)(double)) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i][j] = (*g)(X[i][j]);
        }
    }
}

// main function
int main() {
    int N;
    double **A;
    
    printf("Unesite prirodan broj: ");
    scanf("%d", &N);
    
    A = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        A[i] = (double *)malloc(N * sizeof(double));
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d]=", i, j);
            scanf("%lf", &A[i][j]);
        }
    
    F(N, A, &f);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
