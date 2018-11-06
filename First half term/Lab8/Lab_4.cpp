/*ʵ��¼����������ֵ����Сֵ��ƽ����������*/ 
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
	printf("����������Ԫ�ظ���\n");
	scanf("%d",&n);
	double a[n];
	printf("����������\n");
	for(i = 0;i < n;i++)
	   scanf("%lf",&a[i]);
	printf("		1)ʵ�ʳɹ���������ݸ�����%d\n",ReadRealData(a,n));
	printf("		2)���ֵ������n��%d,",FindMaxElement(a,n));
	printf("��Сֵ������n��%d\n",FindMinElement(a,n));
	printf("		3)ƽ������%.4lf,",Average(a,n));
	printf("������%.4lf\n",Variance(a,n));
	printf("\n");
	
	return 0;
}

