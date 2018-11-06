/*交换2个数*/ 
#include<stdio.h>

int h(int *p1,int *p2)
{
	int t;
	t = *p1;
	*p1 = *p2;   /*注意形式*/ 
	*p2 = t;
}

int main()
{
	int a = 1,b = 2,*p1,*p2;;
	p1 = &a;
	p2 = &b;
	printf("交换前，a = %d,  b = %d\n",a,b);
	
	h(p1,p2);
	printf("交换后，a = %d,  b = %d\n",*p1,*p2);
	
	return 0;
}
