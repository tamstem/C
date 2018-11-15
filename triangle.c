/*
 For three entered triangle points and one addiotional point P, check if point P is inside the triangle.
 */

#include <stdio.h>
 
/*Function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
float area(float x1, float  y1, float  x2, float  y2, float  x3, float  y3){
	float A=(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
	if (A>=0) return A;
	else return -A;
}

/* Program to test above function */
int main()
{
   float x1,y1,x2,y2,x3,y3,x,y;
   scanf("%f %f %f %f %f %f %f %f",&x1, &y1, &x2, &y2, &x3, &y3, &x, &y);
       /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);
   printf("%f\n", A);
 
   /* Calculate area of triangle PBC */  
   float A1 = area (x, y, x2, y2, x3, y3);
   printf("%f\n", A1);
 
   /* Calculate area of triangle PAC */  
   float A2 = area (x1, y1, x, y, x3, y3);
   printf("%f\n", A2);
 
   /* Calculate area of triangle PAB */   
   float A3 = area (x1, y1, x2, y2, x, y);
   printf("%f\n", A3);
   if (A == A1 + A2 + A3)
     printf ("Inside");
   else
     printf ("Not Inside");
 
   return 0;
}
