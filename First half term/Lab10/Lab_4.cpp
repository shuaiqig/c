/*������a�д��ڵ���x����˳���Ƶ�����b��*/
#include<stdio.h>

select1(double a[], double b[], int n, double x)
{
	int i,j = 0,m;
	for(i = 0;i < n;i++)
	    if(a[i] >= x)       {b[j] = a[i];  j++;}      
	m = j;
	
	printf("\n���鷽����ѡ���b[]Ϊ��");
	for(j = 0;j < m;j++)
	   printf("%.2lf   ",b[j]);
}

select2(double *a, double *b, int n, double x)
{
	double *p,*q;
	q = b;
	int m;
	for(p = a;p < (a+n);p++)
	   if(*p >= x)        {*q = *p;    q++;}
	m = q-b;
	
	printf("\nָ�뷽����ѡ���b[]Ϊ��");
	for(q = b;q < (b+m);q++)
	   printf("%.2lf   ",*q);
}

int main()
{
	int i,n;
	printf("������n��ֵ��");
	scanf("%d",&n);
	 
	double x,a[n],b[n];
	printf("����������a[n]:");
	for(i = 0;i < n;i++)
	    scanf("%lf",&a[i]);
	
	printf("������x��ֵ��");
	scanf("%lf",&x);
	
	select1(a,b,n,x);
	select2(a,b,n,x);
	
	return 0;
}
