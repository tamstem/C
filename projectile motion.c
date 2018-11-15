/*
 projectile motion with air resistance
 */

#include <stdio.h>
#include <math.h>
#define g 9.81
typedef struct{
    float x;
    float y;
}Vector;

Vector velocity(Vector v0, float t, float k, float m){
    Vector v;
    v.x=v0.x*exp(-k*t/m);
    v.y=-g*m/k + g*m/k*(1+k/(m*g)*v0.y)*(exp(-k*t/m));
    return v;
}
Vector position(Vector v0, float t, float k, float m){
    Vector s;
    s.x=v0.x *m*(1-exp(-k*t/m))/k;
    s.y=-g*m*t/k + g*m*m/(k*k)*(1+k/(m*g)*v0.y)*(1-exp(-k*t/m));
    return s;
}

int main()
{
    float v_0, alpha,alpha_deg, t=0, dt=0.1,k,m;
    Vector v0, v, s;
    
    printf ("Enter initial velocity and elevation angle\n");
    scanf("%f %f", &v_0, &alpha_deg);
    alpha=3.14159/180*alpha_deg;
    v0.x=v_0*cos(alpha);
    v0.y=v_0*sin(alpha);
    printf ("Enter mass of the projectile\n");
    scanf("%f", &m);
    printf ("Enter coefficient of air resistance k\n");
    scanf("%f", &k);
    printf ("Position and velocity (until the projectile is in motion)\n");
    do{
        v=velocity(v0,t,k,m);
        s=position(v0,t,k,m);
        printf("%.2f %10f %10f %10f %10f\n",t,v.x,v.y,s.x,s.y);
        t+=dt;
    }while (s.y>=0);
    return 0;
}     
