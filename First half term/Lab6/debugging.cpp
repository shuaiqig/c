/*Á·Ï°µ÷ÊÔ*/
#include<stdio.h>
#include <math.h>

int main()
{
	int i, n;
	double Pi, Item;
	double F, S, T;                           
	F = 1, Pi = 0.5, i = 1, T = 0.5, Item=1;                	
	while(Item >= 1e-10)
	{
	    F = F * (1.0 - 1.0/(2*i));
		S = 1.0 / (2*i + 1);
		T = T*0.25;
		Item = F * S * T;
		Pi += Item;
		i = i+1;
		printf("%.16f\n", Pi*6);
	}
	
	return 0;
 }

