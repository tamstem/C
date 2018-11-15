/*
 Sort matrix row-wise with respect to the value of a function sin so that the element with the smallest walue of the function sin is first in a sorted row. Repeat this procedure column-wise. Use Selection sort.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void input(int** A, int n) {
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            printf("A[%d][%d]=", i, j);
            scanf("%d", &A[i][j]);
        }
}

void output(int** A, int n) {
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");}
}

double fun(int x){
    return sin(x);
}


void transpose(int **mat, int n)
{
    int tmp,i,j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++) {
            // swappelement at index (i, j) by element at (j, i)
            tmp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=tmp;
        }
}


void selectionSort(int **A, int n){
    int i, j, k, min_idx;
    int tmp;
    for(k=0;k<n;k++){
        for (i = 0; i < n-1; i++){
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (fun(A[k][j]) < fun(A[k][min_idx]))
                    min_idx = j;
            
            tmp=A[k][min_idx];
            A[k][min_idx]=A[k][i];
            A[k][i]=tmp;
        }
    }
}

int main() {
    int n, i;
    int** A;
    
    printf("Enter the dimension of matrix A: ");
    scanf("%d", &n);
    
    A=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        A[i]=(int*)malloc(n*sizeof(int));
    }
    printf("\n");
    input(A, n);
    printf("\n");
    printf("Sorted row-wise\n");
    selectionSort(A, n);
    output(A, n);
    
    printf("Sorted column-wise\n");
    transpose(A, n); //transpose to sort row-wise
    selectionSort(A, n);
    transpose(A, n); //transpose again to get a matrix sorted column-wise
    output(A, n);
    
    for(i=0; i<n; i++)
        free(A[i]);
    free(A);
    
    return 0;
}

