/*求任意四边形面积*/
#include<stdio.h>
#include<math.h>
#define s (a+b+c+d)/2
#define PI 3.1415926 
double S(double a,double b,double c,double d,double x)
{
	return sqrt((s-a)*(s-b)*(s-c)*(s-d) - a*b*c*d*cos(x/360*PI)*cos(x/360*PI));
}

double Test3()
{
	double a,b,c,d,x;
	printf("please enter five number'a b c d x'\n");
	scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&x);
	
	printf("S = %lf\n",S(a,b,c,d,x));
	
}
