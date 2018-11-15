//Enter an integer and check if it is a palindrome.

#include <stdio.h>
int main(){
    int N, inverted = 0, rest, originalN;
    printf("Enter an integer: ");
    scanf("%d", &N);
    originalN = N;
    while( N!=0 ){
        rest = N%10;
        inverted = inverted*10 + rest;
        N /= 10;
    }
    if (originalN == inverted)
        printf("%d is a palindrome.", originalN);
    else
        printf("%d is not a palindrome.", originalN);
    return 0;
}
