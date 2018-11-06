/*统计字符出现次数*/ 
#include<stdio.h>
#include<string.h>

int count(char str[], char c)
{
	strlwr(str);
	int i,F = 0;
	for(i = 0;i < 100;i++)
		if(str[i] == c)        F++;
	return F;
}

int main()
{
	char a[100],c;
	printf("请输入要查找的字符串：\n");
    gets(a);                              /*注意顺序*/ 
	printf("请输入要查找的字符'c'\n");
	scanf("%c",&c);
	
    printf("字符%c出现次数为%d次\n",c,count(a,c));
    
    return 0;
}
