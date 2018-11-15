/*
 calculate the integral of
f(x)=abs(x)exp(-x^2)
 in the interval [a,b] using
 -trapezoidal rule
 -Monte-Carlo integration
 */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x) {
    return fabs(x) * exp(-x * x);
}
double Trapeze(double (*fun)(double), double a, double b, int N) {
    double x, y, integral = 0.0;
    for (int i = 0; i <= N; i++) {
        x = a + (b - a)*(double)i / (double)N;
        y = (*fun)(x);
        if (i == 0 || i == N)
            integral += 0.5 * y;
        else
            integral += y;
    }
    integral *= (b - a) / (double)N;
    return integral;
}
double MonteCarlo(double (*fun)(double), double a, double b, int N) {
    double x, y, integral = 0.0;
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        x = a + (b - a) * ((double)rand()) / ((double)RAND_MAX);
        y = (*fun)(x);
        integral += y;
    }
    integral *= (b - a) / (double)N;
    return integral;
}

int main() {
    double a, b;
    int N;
    printf("Integral limits:");
    scanf("%lf %lf", &a, &b);
    printf("Enter number of points N:");
    scanf("%d", &N);
    printf("Trapeze= %lf\n", Trapeze(&f, a, b, N));
    printf("MonteCarlo= %lf\n", MonteCarlo(&f, a, b, N));
}
