/*
 Compute determinant of 3x3 matrix (filled with random numbers [3,9]).
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int det(int mat[][3]){
    int det=0;
    for(int i=0;i<3;i++){
        det += (mat[0][i]*(mat[1][(i+1)%3]*mat[2][(i+2)%3] -
                           mat[1][(i+2)%3]*mat[2][(i+1)%3]));
    }
    return det;
}

int main(){
    int A[3][3];
    printf("Matrica :\n");
    srand(time(NULL));
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            A[i][j]=rand()%7+3;     // 3 to 9
            printf("%ld ",A[i][j]);
        }
        printf("\n");
    }
    printf("Determinant is %d ", det(A));
    return 0;
}
