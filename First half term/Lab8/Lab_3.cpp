/*交换指定项顺序*/ 
#include<stdio.h>

void sort(int a[], int n)
{
	int i,j,t;
	for(j = 0;j < n;j++)
	   for(i = 0;i < n-1;i++)
	      {
	      	if(a[i] < a[i+1])
	      	    {
				 t = a[i];
	      	     a[i] = a[i+1];
	      	     a[i+1] = t;
		        }
		  }
	printf("排序后的数组为：\n");
	for(i = 0;i < 10;i++)
	   printf("%4d",a[i]);
}

int main()
{
	int i,a[10],n;
	printf("请输入这10个数\n");
	for(i = 0;i < 10;i++)
	   scanf("%d",&a[i]);
	printf("请输入要排序的个数\n");
	scanf("%d",&n);
	   
	sort(a,n);
}
