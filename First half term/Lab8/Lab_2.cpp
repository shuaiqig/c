/*��������*/ 
#include<stdio.h>

void BlockExchange(int a[], int n, int m)
{
	int i;
	if (m > n/2)             printf("m������Ҫ��!\n");
	else
	{
	int temp,i;
	for	(i = 0;i < m;i++)
		{
			temp=a[i];
			a[i]=a[n-m+i];
			a[n-m+i]=temp;
		}
	printf("�����������Ϊ:");
	for (i = 0;i < n;i++)
		printf("%4d ",a[i]);
	printf("\n");
    }
}

int main()
{
	int i,m,n;
	
	printf("������n\n");
	scanf("%d",&n);
	
	int a[n];                  /*��������ʱ��n����Ϊ����*/ 
	printf("����������\n");
	for(i = 0;i < n;i++)
	   scanf("%d",&a[i]);
	printf("��������Ϊ��\n");
	for(i = 0;i < n;i++)  
	   printf("%4d",a[i]);
	   
	printf("������m\n");
	scanf("%d",&m);
	
	BlockExchange(a, n, m);
	
}
