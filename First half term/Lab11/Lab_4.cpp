/*把所有行依次输出，并在那些包含字符串s的行前面标一个星号*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	char str[100][20];
	char s[100];
	int n;
	printf("请输入这些字符串：\n");
	strcpy(s, argv[1]);
	int i;
	for (i = 0; scanf("%s", str[i]) != EOF; i++);
	n = i;
    printf("输出结果为：\n");
	for (i = 0; i < n; i++)
	 {
		char *p = strstr(str[i],argv[1]);
		if (p != NULL)
		 printf("*");
		printf("%s\n", str[i]);
	}
	return 0;
}
