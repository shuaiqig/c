#include<stdio.h>
#include"Lab5_output.h"


void Output1(int a[][3] , int n)
{
	int i;
	printf("二维数组形式，排序后结果为：\n");
	for(i = 0;i < n;i++)
        printf("%d,%d,%d\n",a[i][0],a[i][1],a[i][2]);
}

void Output2(RECORD *t , int n)
{
	int i;
	RECORD *p;
	printf("结构体数组形式，排序后结果为：\n");
	for(p = t;p < (t + n);p++)  
	    {
		    printf("%d,%d,%d\n", p->r1 , p->r2 , p->r3);
        }
}

void Output3(RECORD *s , int n)
{
	int i;
	RECORD *p;
	printf("指针数组形式，排序后结果为：\n");
	for(p = s;p < (s + n);p++)  
	    {
		    printf("%d,%d,%d\n", p->r1 , p->r2 , p->r3);
        }
}

void Output4(NODE *All , int n)
{
	int Tmp;
	printf("链表形式，排序后结果为：\n");
	for(Tmp = 1; Tmp < n; Tmp++)  
	{
		printf("%d,%d,%d\n", All[Tmp].s1, All[Tmp].s2, All[Tmp].s3);
	}  
}

