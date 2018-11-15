/*
 A program that performs addition, subtraction, multiplication and conjugation of complex numbers using structures.
 */

#include <stdio.h>
typedef struct {
    float real;
    float imag;
}Complex;

Complex plus(Complex n1, Complex n2) {
    Complex tmp;
    tmp.real = n1.real + n2.real;
    tmp.imag = n1.imag + n2.imag;
    return tmp;
}
Complex minus(Complex n1, Complex n2) {
    Complex tmp;
    tmp.real = n1.real - n2.real;
    tmp.imag = n1.imag - n2.imag;
    return tmp;
}
Complex times(Complex n1, Complex n2) {
    Complex tmp;
    tmp.real = n1.real * n2.real - n1.imag * n2.imag;
    tmp.imag = n1.imag * n2.real + n1.real * n2.imag;
    return tmp;
}
Complex conjugation(Complex n) {
    Complex tmp;
    tmp.real = n.real;
    tmp.imag = -n.imag;
    return tmp;
}
void print(Complex n) {
    if (n.imag >= 0)
        printf("%f + %fi\n", n.real, n.imag);
    else
        printf("%f  %fi\n", n.real, n.imag);
}

int main() {
    Complex n1, n2, n3;
    
    printf("First complex number \n");
    scanf("%f %f", &n1.real, &n1.imag);
    
    printf("Second complex number \n");
    scanf("%f %f", &n2.real, &n2.imag);
    
    n3 = plus(n1, n2);
    print(n3);
    n3 = minus(n1, n2);
    print(n3);
    n3 = times(n1, n2);
    print(n3);
    n3 = conjugation(n1);
    print(n3);
    return 0;
}
