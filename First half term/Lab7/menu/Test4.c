/*求球的体积和表面积*/ 
#include<stdio.h>
#define PI 3.14
double volume(double radius)
{
	return PI*4*radius*radius*radius/3;
}

double SurfaceArea(double radius)
{
	return PI*4*radius*radius;
}

double Test4()
{
	double radius;
	printf("please enter a number for 'radius'\n");
	scanf("%lf",&radius);
	
	printf("volume = %lf\n",volume(radius));
	
	printf("Surface Area = %lf\n",SurfaceArea(radius));
	
}
