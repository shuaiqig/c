/*y = a0  + a1 * x^1 + a2 * x^2 + ¡­ + an * x^n*/
#include<stdio.h>
#include<math.h>

double polyfunc(int n, double a[], double x)
{
	int i;
	double m,S = 0;
	for(i = 0;i <= n;i++)
	{
		m = a[i]*pow(x,i);
		S = S + m;
	}
	
	printf("y = %lf",S);
}

int main()
{
	int n,i;
	double a[n+1],x;
	
	printf("ÊäÈën\n");
	scanf("%d",&n);
	printf("ÊäÈëa[n+1]\n");
	for(i = 0;i <= n;i++)
	scanf("%lf",&a[i]);
	printf("ÊäÈëx\n");
	scanf("%lf",&x);
	
	polyfunc(n,a,x);
	return 0;
}
