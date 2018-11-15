/*
Write a program which prints all numbers from 1 to N whose sum of digit factorials is equal to the original number.
 Example: 145=1!+4!+5!
 */

#include <stdio.h>
int main(){
    int i, j, n, last, N, fact, sum;
    printf("Enter upper limit: ");
    scanf("%d", &N);
    printf("Strong numbers are:\n");
    for(i=1; i<=N; i++){
        n = i;
        sum = 0;
        while(n > 0){
            fact=1;
            last = n % 10;
            for( j=1; j<=last; j++)
                fact = fact * j;
            sum += fact;
            n/= 10;
        }
        if(sum == i)
            printf("%d ", i);
    }
    return 0;
}
