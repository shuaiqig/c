/*����ָ����˳��*/ 
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
	printf("����������Ϊ��\n");
	for(i = 0;i < 10;i++)
	   printf("%4d",a[i]);
}

int main()
{
	int i,a[10],n;
	printf("��������10����\n");
	for(i = 0;i < 10;i++)
	   scanf("%d",&a[i]);
	printf("������Ҫ����ĸ���\n");
	scanf("%d",&n);
	   
	sort(a,n);
}
