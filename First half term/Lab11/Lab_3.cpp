/*判断n阶矩阵是否对称*/
#include<stdio.h>
#define N 100

int zhizhen(int (*p)[N],int n)
{
	int i,j,k = 0;
	for(i = 0;i < n;i++)
	   for(j = i;j < n;j++)
	      if((*p+i)+j != (*p+j)+i)       k++;
	if(k == 0)           return 1;
	else                 return 0;
}

int shuzu(int a[][N],int n)
{
	int i,j,k = 0;
	for(i = 0;i < n;i++)
	   for(j = i;j < n;j++)
	      if(a[i][j] != a[j][i])          k++;  
	if(k == 0)           return 1;
	else                 return 0;
}

int main()
{
	int i,j,n,a[N][N];
	printf("请输入阶数n:");
	scanf("%d",&n);
	printf("请输入这个矩阵：\n");
	for(i = 0;i < n;i++)
	   for(j = 0;j < n;j++)
	      scanf("%d",&a[i][j]);
	
	printf("数组方法判断结果为：%d\n",shuzu(a,n));
	printf("指针方法判断结果为：%d",zhizhen(a,n));	
	return 0;
}
