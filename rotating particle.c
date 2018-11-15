/*
 Particle of mass m moves in a cicular motion in xy plane around the origin (r=1). In the initial moment (t = 0) the position vector is
 r0 =cos(φ)\hat{x}+sin(φ)\hat{y}+0*\hat{z}. Compute r(t) and the momentum p(t) using rotation matrix R(ω t)
 with angular velocitiy ω. Momentum p⃗ is
 p⃗ = mr
 Compute  angular momentum L⃗
 L⃗ = ⃗r × p⃗
 */
#include <stdio.h>
#include <math.h>

void v_prod(double a[], double b[]){
	int i;
	double c[3]={0,0,0};
	for(i=0;i<3;i++){
		c[i]=a[(i+1)%3]*b[(i+2)%3]-a[(i+2)%3]*b[(i+1)%3];
		printf("%lf ",c[i]);
	}
}

int main(){
	int i,j;
	double m,w,t,phi;
	double r0[3],r[3]={0,0,0},p[3]={0,0,0};
	double R[3][3],Rdot[3][3];
	printf("Enter particle mass m:");
	scanf("%lf",&m);
	printf("Enter angular velocity w:");
	scanf("%lf",&w);
	printf("Enter time t:");
	scanf("%lf",&t);
	printf("\n Rotation matrix around z axis\n");
	R[0][0]=cos(w*t);
	R[0][1]=-sin(w*t);
	R[0][2]=0;
	R[1][0]=sin(w*t);
	R[1][1]=cos(w*t);
	R[1][2]=0;
	R[2][0]=0;
	R[2][1]=0;
	R[2][2]=1;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++)
			printf("%lf ",R[i][j]);
		printf("\n");
	}
	printf("\n Derivative of rotation matrix around z axis\n");
	Rdot[0][0]=-w*sin(w*t);
	Rdot[0][1]=-w*cos(w*t);
	Rdot[0][2]=0;
	Rdot[1][0]=w*cos(w*t);
	Rdot[1][1]=-w*sin(w*t);
	Rdot[1][2]=0;
	Rdot[2][0]=0;
	Rdot[2][1]=0;
	Rdot[2][2]=0;
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++)
			printf("%lf ",Rdot[i][j]);
		printf("\n");
	}
	printf("Position vector for t=0: \n");
	printf("Enter the angle: \n");
	scanf("%lf",&phi);
	r0[0]=cos(phi);
	r0[1]=sin(phi);
	r0[2]=0;
	printf("\n Position vector for t=0: \n");
	for(i=0;i<3;i++)
			printf("%lf ",r0[i]);
	printf("\n Position vector for time t: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			r[i]+=R[i][j]*r0[j];
		}
		printf("%lf ",r[i]);
	}
	printf("\n Momentum  vector for time t: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			p[i]+=m*Rdot[i][j]*r0[j];
		}
		printf("%lf ",p[i]);
	}
	printf("\n Angular momentum for time t: \n");
	v_prod(r,p);
	printf("\n Angular momentum for time t(check): %lf \n", m*w);
	return 0;

	}
