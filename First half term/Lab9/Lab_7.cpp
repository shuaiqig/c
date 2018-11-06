/*打印数组鞍点*/
#include<stdio.h>
#define n 4

int main()
{
	int i,j,k,m,a[n][n],l = 0;
	printf("请输入这个二维数组：\n");
	for(i = 0;i < n;i++)
	   for(j = 0;j < n;j++)
	      scanf("%4d",&a[i][j]);
	
	for(i = 0;i < n;i++)
	   for(j = 0;j < n;j++)
	      {
	      	m = 0;
	      	for(k = 0;k < n;k++)
	      	   {
	      	   	if(a[i][j] < a[i][k])    m++;
	      	   	if(a[i][j] > a[k][j])    m++;	  
			   }
			if(m == 0)
			  {
			   printf("a[%d][%d]为鞍点,值为%d\n",i,j,a[i][j]);
		       l++;
		      }
		  }
		  
	if(l == 0)       printf("无鞍点\n");
	
	return 0;
} 
