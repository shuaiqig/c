/*Å£¶Ùµü´ú·¨*/ 
#include<stdio.h>

int a,b,c,d;
double f1(double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

double f2(double x)
{
	return 3*a*x*x + 2*b*x + c;
}

int main()
{
	double x;
	printf("please enter four numbers for 'a' 'b' 'c' 'd'\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	printf("please enter a number for 'x0'\n");
	scanf("%lf",&x);
	
	do
	{
		x = x - f1(x)/f2(x);
	}
	while(f1(x)-0 > 1e-6);
	
	printf("x = %lf",x);
	
	return 0;
}
