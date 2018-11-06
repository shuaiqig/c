#include<stdio.h>
#include<string.h>
#include <malloc.h>
#include <stdlib.h>
#include"Lab5_loadfile.h"
#include"Lab5_sort.h"
#include"Lab5_output.h"

int a[10000];
int m;

void load(char file[])
{
	char last[3] , k[2];   //存储后缀名 
	strncpy(last , file+(strlen(file) - 3) , 3);
	
	if(strcmp(last , "txt") == 0)    //以后缀名决定打开方式 
	    strcpy(k , "r");
	else if(strcmp(last , "dat") == 0)
	    strcpy(k , "rb");
	else{
		printf("文件不合法，退出run函数！\n");
		return ;
	}
	
	
	int x , i = 0 ;
	FILE *fp;
	
	if((fp = fopen(file , k)) == NULL)
	{
		printf("\n文件读取错误，退出run函数！\n");
		return ;
	}
	
	else{
		while(fscanf(fp,"%d,",&x)>0)
            {
            	a[i] = x;         //将文件中的数据存入一个数组   注意，a【0】 为记录条数，不采用 
            	i++;
			}
		m = i;               //  m  数据个数 
        fclose(fp);
       	}

}


void load1()                                            //二维数组   存储
{                  
	int date[m/3][3];
	int i , j , k = 1;                                  
	for(i = 0;i < m/3;i++)
	    for(j = 0;j < 3 && k < m;j++)
	        {
	        	date[i][j] = a[k];
	        	k++;
			}

    qsort(date, m/3, sizeof(date[0]), CmpLink1);     //二维数组   排序
    
    Output1(date , m/3);
}

void load2()                                           //结构体数组   存储 
{
	RECORD t[m/3];
	int i = 1;
	RECORD *p;
	for(p = t;p < (t + m/3);p++)
	    {
		    p->r1 = a[i];
		    p->r2 = a[i+1];
		    p->r3 = a[i+2];
		    i+=3;
		}
	qsort(t, m/3, sizeof(record), CmpLink2);         //结构体数组   排序 
	
	Output2(t , m/3);
}

void load3()                                           //指针数组    存储 
{
    RECORD *s = (RECORD*)malloc( sizeof(RECORD)*(m/3));    
	RECORD *p;
	int i = 0;		
	for(p= s;p < (s + m/3);p++)
	    {
		 	p->r1 = a[i];
	        p->r2 = a[i+1];
	        p->r3 = a[i+2];
        	i+=3;   
		} 
	
	qsort(s, m/3, sizeof(record), CmpLink3);         //指针数组   排序
	
	Output3(s , m/3);
}

void load4()                                       //链表     存储 
{
    LINK PHead = (LINK)malloc(sizeof(NODE));    //    创建分配一个头节点内存空间
    LINK p1 = (LINK)malloc(sizeof(NODE));    //    分配一个新节点
    PHead->next = p1;    //注意赋值方向     
    int i;
    for(i = 1;i < m;i+=3)
        {
        	p1->s1 = a[i];
        	p1->s2 = a[i+1];
        	p1->s3 = a[i+2];
        	p1->next = (LINK)malloc(sizeof(NODE));    //    分配一个新节点
        	p1 = p1->next;
        }
    p1->next = NULL;
    
//	LINK p;
//	for(p = PHead->next;p != NULL;p = p->next)
//	    printf("%d,%d,%d\n", p->s1 , p->s2 , p->s3);
	
	NODE * All[m/3];
	All[0] = PHead->next;
	for(i=1; i <= m/3; i++)  
	    All[i] = All[i-1]->next;
	    
	qsort((NODE *)(All), m/3, sizeof(NODE *), CmpLink4);    //链表   排序
	
    int Tmp;
    printf("链表形式，排序后结果为：\n");
	for(Tmp = 0; Tmp < m/3; Tmp++)  
	{
		printf("%d,%d,%d\n", All[Tmp]->s1, All[Tmp]->s2, All[Tmp]->s3);
	}  		
}


