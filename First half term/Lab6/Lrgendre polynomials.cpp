/*�õݹ�ķ�����N�����õ¶���ʽ��ֵ*/
#include<stdio.h>

double P(int n,double x)
{
	if     (n == 0)                  return 1;
	else if(n == 1)                  return x;
	else                             return ((2*n-1)*x*P(n-1,x) - (n-1)*P(n-2,x))/n;           
}

int main()
{
	int n;
	double x;
	printf("please enter two number for 'n' 'x'\n");
	scanf("%d%lf",&n,&x);
	
	printf("P(n,x) = %lf",P(n,x));
	
	return 0;
}
