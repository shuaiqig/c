/*����2����*/ 
#include<stdio.h>

int h(int *p1,int *p2)
{
	int t;
	t = *p1;
	*p1 = *p2;   /*ע����ʽ*/ 
	*p2 = t;
}

int main()
{
	int a = 1,b = 2,*p1,*p2;;
	p1 = &a;
	p2 = &b;
	printf("����ǰ��a = %d,  b = %d\n",a,b);
	
	h(p1,p2);
	printf("������a = %d,  b = %d\n",*p1,*p2);
	
	return 0;
}
