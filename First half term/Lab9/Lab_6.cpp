/*二维数组打印杨辉三角*/
#include<stdio.h>
#define n 10

int main()
{
	int i,j,a[n][n];
	for(i = 0;i < n;i++)
	   for(j = 0;j < n;j++)
	      a[i][j] = 0;
		          
	a[0][1] = 1;
	for(i = 1;i < n;i++)
	   for(j = 1;j <= i+1;j++)
	      a[i][j] = a[i-1][j-1] + a[i-1][j];
   
	for(i = 0;i < n;i++)
	   {
	    for(j = 1;j <= i+1;j++)
	    printf("%4d",a[i][j]);
       
	    printf("\n");
	   }
	return 0;
} 
