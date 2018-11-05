/*引用函数求一元二次方程的根*/ 
#include<stdio.h>
#include<math.h>

double root(double a, double b, double c)
{
	double x1,x2;
    
	if(a == 0||b == 0||c == 0) 	                                printf("enter error\n");
	
	else if (b*b-4*a*c < 0)	                                    printf("no answer\n");
	
	else 
	    x1 = (-b-sqrt(b*b-4*a*c))/(2*a),x2 = (-b+sqrt(b*b-4*a*c))/(2*a);
        printf("x1 = %lf,x2 = %lf\n",x1,x2);
    
	return 0;
}

int main()
{
	double a,b,c;
	printf("please enter three number 'a','b','c' not 0\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	
	root(a,b,c);
	
	return 0;
}
