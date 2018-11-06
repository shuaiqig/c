/*实际录入个数、最大值、最小值、平均数、方差*/ 
#include<stdio.h>
int ReadRealData(double a[], int n)
{
	int i,y = 0;
	for(i = 0;i < n;i++)
	   {
	   	if(a[i] != 0)       y++;
	   }
	return y;
}

int FindMaxElement (double a[], int n) 
{
	int i,t = 0;
	double max = a[0];
	for(i = 1;i < n;i++)
	   	if(a[i] > max)
	   	 {
     	    max = a[i];
	   	    t = i+1;
	     }
	   return t;
}

int FindMinElement (double a[], int n)
{
	int i,t = 0;
	double min = a[0];
	for(i = 1;i < n;i++)
	   {
	   	if(a[i] < min)
	   	 {
     	    min = a[i];
	   	    t = i+1;
	     }
	   }
	   return t;
}

double Average(double a[], int n)
{
	int i;
	double sum = 0;
	for(i = 0;i < n;i++)
	   {
	   	sum = sum + a[i];
	   }
	   return sum/n;
}
double Variance(double a[], int n)
{
	int i;
	double sum1 = 0,A,sum2 = 0;
	for(i = 0;i < n;i++)
	   	sum1 = sum1 + a[i];
	   A = sum1/n;
	   
	for(i = 0;i < n;i++)
	   sum2 = sum2 + (a[i] - A)*(a[i] - A);
	return sum2/n;
}

int main()
{
	int i,n;
	printf("请输入数组元素个数\n");
	scanf("%d",&n);
	double a[n];
	printf("请输入数组\n");
	for(i = 0;i < n;i++)
	   scanf("%lf",&a[i]);
	printf("		1)实际成功读入的数据个数是%d\n",ReadRealData(a,n));
	printf("		2)最大值的项数n是%d,",FindMaxElement(a,n));
	printf("最小值的项数n是%d\n",FindMinElement(a,n));
	printf("		3)平均数是%.4lf,",Average(a,n));
	printf("方差是%.4lf\n",Variance(a,n));
	printf("\n");
	
	return 0;
}

