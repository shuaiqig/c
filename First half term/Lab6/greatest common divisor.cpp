/*��2�������Լ�����ݹ����*/ 
#include<stdio.h>

int gcd(int m,int n)
{
	if    (m == n)             return m;
	else if(m < n)             return gcd(n,m);
	else                       return gcd(m-n,n);
}

int main()
{
	int m,n;
	printf("please enter two number for 'm' 'n'\n");
	scanf("%d%d",&m,&n);
	
	printf("���Լ�� = %d",gcd(m,n));
	
	return 0;
}
