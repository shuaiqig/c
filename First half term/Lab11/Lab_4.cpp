/*�����������������������Щ�����ַ���s����ǰ���һ���Ǻ�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	char str[100][20];
	char s[100];
	int n;
	printf("��������Щ�ַ�����\n");
	strcpy(s, argv[1]);
	int i;
	for (i = 0; scanf("%s", str[i]) != EOF; i++);
	n = i;
    printf("������Ϊ��\n");
	for (i = 0; i < n; i++)
	 {
		char *p = strstr(str[i],argv[1]);
		if (p != NULL)
		 printf("*");
		printf("%s\n", str[i]);
	}
	return 0;
}
