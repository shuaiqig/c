/*����10����������������С�������һ�����Ի����������������һ�����Ի�*/
#include<stdio.h>
#define n 10

int action1(int a[],int m)    /*��������Ϊ�궨���n*/ 
{                             /*���鷽��*/ 
	int i,min = a[0],j = 0,max = a[0],k = 0,t,b[n];
	for(i = 1;i < m;i++)
	   {
	   	  if(a[i] > max)       max = a[i],j = i;
	   	  if(a[i] < min)       min = a[i],k = i;
	   }
	t = a[j];
	a[j] = a[9];
	a[9] = t;
	
	t = a[k];
	a[k] = a[0];
	a[0] = t;
	
	for(i = 0;i < m;i++)
	   printf("%4d",a[i]);
}

void action2(int *a,int m)      /*ָ�뷽��*/ 
{
	int *p,max = *a,min = *a,i = 0,j = 0,k = 0,t;
	for(p = a+1;p < (a+10);p++)
	   {
	   	  i++;
	   	  if(*p > max)          {max = *p;	j = i;}
	   	  if(*p < min)          {min = *p;  k = i;}
	   }
	t = *(p+9);
	*(p+9) = *(p+j);
	*(p+j) = t;
	
	t = *p;
	*p = *(p+k);
	*(p+k) = t;  
	
	for(p = a;p < (a+10);p++)
	   printf("%4d",*p);
}

int main()
{
	int i,a[n];
	printf("������������飺\n");
	for(i = 0;i < n;i++)
    scanf("%d",&a[i]);
    
    printf("���鷽��ʵ�֣�\n");
    action1(a,n);
    
    printf("\n���鷽��ʵ�֣�\n");
    action2(a,n);
    
    return 0;
} 
