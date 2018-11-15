/*
 Enter 3x3 matrix and print its diagonals.
 For
 1 2 3
 4 5 6
 7 8 9
 output:
 1
 2 4
 3 5 7
 6 8
 9
 */

#include <stdio.h>

int main() {
    int N=3, mat[3][3];
    printf("Enter elements of 3x3 matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Diagonals:\n");
    for (int k = 0; k < 2*N - 1; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i + j == k)
                    printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
