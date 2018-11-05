/*求π的近似值*/ 
#include<stdio.h>
int main()
{
	int n,a;
	double i,s,sum;
	
	while(1)
  {
	i = 1,sum = 0.5,s = 0.5;
  
	printf("please enter cycles 'n'\n");/*输入循环次数*/ 
	scanf("%d",&n);
	
	do
	{
		s = s*((2*i -1) / (2*i))*0.5*0.5*((2*i - 1) / (2*i + 1));
		
		sum = sum + s;
		i++;
	}
	while(i <= n);
	
	sum = 6*sum;
	printf("π = %.16lf\n",sum);
	
	printf("enter '1' continue,enter '0' end\n");
	scanf("%d",&a); 
	
	if(a == 1)           continue;
	break;
  }
	
	return 0;
 } 
