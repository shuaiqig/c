#include<stdio.h>
int main()
{
 	int a,b;
 	char c1 = 'A',c2 = 'a';
 	double x,y,z;
 	scanf("%d %d %c %c %lf %lf %lf",&a,&b,&c1,&c2,&x,&y,&z);
 	printf("a = %d,b = %d,c1 = %c,c2 = %c,x = %.1lf,y = %.2lf,z = %.2lf",a,b,c1,c2,x,y,z);
 	return 0;
 }
