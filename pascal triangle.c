/* A program thet prints first  N rows of a Pascal triangle. For N=6
           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
 1   5  10  10   5   1
 
 */

#include<stdio.h>

long binom(int n, int m){
    if(n==m || m==0) return 1;
    else return (binom(n-1,m)+binom(n-1,m-1));
}

int main()
{
    int i, j, space, N;
    printf("Number of rows:\n");
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        for(space = 1; space <= N-i; space++){
            printf("  ");
        }
        for(j = 0; j <= i; j++){
            printf("%4d",binom(i,j));
        }
        printf("\n");
    }
    return 0;
    
}
