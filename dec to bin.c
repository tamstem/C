// Using recursive functions convert decimal number to binary number.


#include<stdio.h>

long convertDtoB(int D){
    if(D == 0) return 0;
    else return (D%2+10*convertDtoB(D/2));
}

int main(){
    long B;
    int D;
    printf(" Decimal number: ");
    scanf("%d",&D);
    printf("Binary number: %ld", convertDtoB(D));
    return 0;
}


