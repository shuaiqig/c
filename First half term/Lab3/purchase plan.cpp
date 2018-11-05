/*买水果方案*/ 
#include<stdio.h>
int main()
{
	int a,b,c;
	
	for(a = 1;a <= 100;a++)
	
	
	  for(b = 1;b <= 10;b++)
    {
	      
	   c = 100 - a -b;
	   
	   if(0.4*a + 4*b + 0.2*c == 40)
	     printf("a = %d,b = %d,c = %d\n",a,b,c);     
     
	}

}
