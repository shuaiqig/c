/*解一元二次方程*/ 
#include<stdio.h>
#include<math.h>
int main ()
{
	double a,b,c,x1,x2,x;
	printf ("please enter three number\n");
	scanf ("%lf %lf %lf",&a,&b,&c);
	
	if (a == 0)
	  
	{
	  if (b == 0)
	    
	   {  
		if (c == 0)
		printf("any answer\n");
	    
		else  
		printf("no answer\n");
       }
	  else  
	    x = -c/b;
		printf("x = %lf\n",x);
    }   
	else 
	{
	
	  if (b*b-4*a*c < 0)
	    printf("no answer\n");
	  else if (b*b-4*a*c == 0)
	   {
	    x1 = x2 = -b/(2*a);
		printf("x1 = x2 =%lf\n",x1);
       }
	  else 
	    x1 = (-b-sqrt(b*b-4*a*c))/(2*a),x2 = (-b+sqrt(b*b-4*a*c))/(2*a);
		printf("x1 = %lf,x2 = %lf\n",x1,x2);
    }
	return 0;
}
