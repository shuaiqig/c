/*��һ���ַ����дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ�Ϊ��һ���ַ�*/
#include<stdio.h>
#include<stdlib.h>

void fun(char *s,char c,int m,int n)
{
	char *p;
	for(p = (s+m-1);p < (s+n);p++)
	   {
	   	   *p = c;
	   }
}

int main()
{
	char b;
	int m,n;
	printf("������n��            ");
	scanf("%d",&n);
	char a[n];	
	printf("����������ַ���a[]��");
	fflush(stdin);
	gets(a);
	printf("�������ַ� b ��      ");
	fflush(stdin);
	scanf("%c",&b);    
	printf("������m��            ");
	scanf("%d",&m);
	
	fun(a,b,m,n);
    puts(a);
    
    return 0;
}
