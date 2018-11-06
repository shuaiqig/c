/*交换数组*/ 
#include<stdio.h>

void BlockExchange(int a[], int n, int m)
{
	int i;
	if (m > n/2)             printf("m不符合要求!\n");
	else
	{
	int temp,i;
	for	(i = 0;i < m;i++)
		{
			temp=a[i];
			a[i]=a[n-m+i];
			a[n-m+i]=temp;
		}
	printf("交换后的数组为:");
	for (i = 0;i < n;i++)
		printf("%4d ",a[i]);
	printf("\n");
    }
}

int main()
{
	int i,m,n;
	
	printf("请输入n\n");
	scanf("%d",&n);
	
	int a[n];                  /*定义数组时，n不能为变量*/ 
	printf("请输入数组\n");
	for(i = 0;i < n;i++)
	   scanf("%d",&a[i]);
	printf("输入数组为：\n");
	for(i = 0;i < n;i++)  
	   printf("%4d",a[i]);
	   
	printf("请输入m\n");
	scanf("%d",&m);
	
	BlockExchange(a, n, m);
	
}
