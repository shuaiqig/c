#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"Lab5_sort.h"

typedef struct record{     
    int r1;
    int r2;
    int r3;
}RECORD;

typedef struct node NODE, *LINK;     //以链表形式存储 
struct node//定义链接结构
{
	int s1;
	int s2;
	int s3;
	LINK next;
};

int CmpLink1(const void *a,const void *b)
{
	int *c = (int *)a;
    int *d = (int *)b;
    
    if(c[2] > d[2])
		return 1; 
	else  
		return c[2] == d[2]?0:-1;
}

int CmpLink2(const void *a,const void *b)
{
	RECORD *p = (RECORD *)a;  
    RECORD *q = (RECORD *)b;  
 
	if(p->r3 > q->r3)
		return 1; 
	else  
		return p->r3 == q->r3?0:-1;
}

int CmpLink3(const void *a,const void *b)
{
	RECORD *p = (RECORD *)a;
    RECORD *q = (RECORD *)b;  
 
	if(p->r3 > q->r3)
		return 1; 
	else  
		return p->r3 == q->r3?0:-1;
}

int CmpLink4(const void *a,const void *b)
{
	NODE *p = *(NODE **)a;
    NODE *q = *(NODE **)b;  
 
	if(p->s3 > q->s3)
		return 1; 
	else  
		return p->s3 == q->s3?0:-1;
}


