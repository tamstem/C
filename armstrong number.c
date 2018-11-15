/*
 Armstrong number of order n
 abc...=a^n+b^n+c^n+...
 Check if the entered number is Armstrong number.
 */


#include <stdio.h>
#include <math.h>
int main(){
    int N, tmp, rest, sum = 0, n = 0 ;
    printf("Enter an integer: ");
    scanf("%d", &N);
    tmp = N;
    /*count digits*/
    while (tmp != 0){
        tmp /= 10;
        ++n;
    }
    tmp= N;
    /*sum of n-th powers of digits*/
    while (tmp != 0){
        rest = tmp%10;
        sum += pow(rest, n);
        tmp /= 10;
    }
    if(sum == N)
        printf("%d is Armstrong number.", N);
    else
        printf("%d is not Armstrong number.", N);
    return 0;
}
