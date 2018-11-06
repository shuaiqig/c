/*输出最长字符串*/ 
#include<stdio.h>
#include<string.h>
#define n 100

int s(char a[])     /*数字符串长度*/ 
{
	int i,k = 0;
	for(i = 0;a[i] != '\0';i++)     k++;
        
    return k;
}

int main()
{
	char a[n],b[n];
	printf("请输入第一个字符串：\n");
	gets(a);
	printf("请输入其他字符串：\n");
    gets(b);
    
	do   
	{
      if(s(a) < s(b))
        strcpy(a,b);
	  printf("请输入其他字符串：\n");
	}
	while(gets(b)!=NULL);   /*作为判断语句，同时也完成了一次输入*/ 
	
	printf("最长字符串为："); 
	puts(a);
	
	return 0;
}

