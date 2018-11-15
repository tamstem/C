/*
 calculates derivative of
f1(x)=4.3cos(2.1x)
f2(x)=1.2(sin(x))^3+x^4-5
 in steps of 0.1 in interval [0,1.5]
*/
#include <stdio.h>
#include <math.h>

double funk1(double x) {
    return 4.3 * cos(2.1 * x);
}
double funk2(double x) {
    return 1.2 * pow(sin(x), 3) + pow(x, 4) - 5;
}
double der(double x, double h, double (*f)(double)) {
    return ((*f)(x + h) - (*f)(x - h)) / (2*h);
}
int main() {
    double step = 0.1;
    
    printf("Derivative f1\n");
    for (double x = 0.0; x <= 1.5; x += step)
        printf("%lf %lf\n", x, der(x, step, &funk1));
    
    printf("Derivative f2\n");
    for (double x = 0.0; x <= 1.5; x += step)
        printf("%lf %lf\n", x, der(x, step, &funk2));
    
    return 0;
}
