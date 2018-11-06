/*判断回文字符串*/ 
#include<stdio.h>
int level(char a[])
{
	int i,j,k = 0;
	for(i = 0;a[i] != '\0';i++);
	for(j = 0;a[j] != '\0';j++)
	    {
			if(a[j] != a[i-j-1])      k++;    
		}
    if(k == 0)       printf("这个字符串是回文字符\n");
    else             printf("这个字符串不是回文字符\n");
}

int main()
{
	char a[100];
	printf("请输入这个字符串\n");
	gets(a);
	
	level(a);
	
	return 0;
}
