/*100以内正整数立方和*/
#include<stdio.h>
#include<math.h>

int SumCube(int  limit)
{
	int i,sum;
	sum = 0;
	if (limit <= 0)
	   return 0;
	
	else 
	   for(i = 1;i <= limit;i++)
	     sum = sum + i*i*i;
    return sum;
}

double Test2()
{
	int limit,result;
	printf("please enter a limit\n");
	scanf("%d",&limit);
	
	result = SumCube(limit);
	printf("result = %d\n",result);
	
	return 0;
}
