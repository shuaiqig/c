/*将一个字符串中从第m个字符开始的全部字符复制成为另一个字符*/
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
	printf("请输入n：            ");
	scanf("%d",&n);
	char a[n];	
	printf("请输入这个字符串a[]：");
	fflush(stdin);
	gets(a);
	printf("请输入字符 b ：      ");
	fflush(stdin);
	scanf("%c",&b);    
	printf("请输入m：            ");
	scanf("%d",&m);
	
	fun(a,b,m,n);
    puts(a);
    
    return 0;
}
