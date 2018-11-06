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
	char last[3] , k[2];   //�洢��׺�� 
	strncpy(last , file+(strlen(file) - 3) , 3);
	
	if(strcmp(last , "txt") == 0)    //�Ժ�׺�������򿪷�ʽ 
	    strcpy(k , "r");
	else if(strcmp(last , "dat") == 0)
	    strcpy(k , "rb");
	else{
		printf("�ļ����Ϸ����˳�run������\n");
		return ;
	}
	
	
	int x , i = 0 ;
	FILE *fp;
	
	if((fp = fopen(file , k)) == NULL)
	{
		printf("\n�ļ���ȡ�����˳�run������\n");
		return ;
	}
	
	else{
		while(fscanf(fp,"%d,",&x)>0)
            {
            	a[i] = x;         //���ļ��е����ݴ���һ������   ע�⣬a��0�� Ϊ��¼������������ 
            	i++;
			}
		m = i;               //  m  ���ݸ��� 
        fclose(fp);
       	}

}


void load1()                                            //��ά����   �洢
{                  
	int date[m/3][3];
	int i , j , k = 1;                                  
	for(i = 0;i < m/3;i++)
	    for(j = 0;j < 3 && k < m;j++)
	        {
	        	date[i][j] = a[k];
	        	k++;
			}

    qsort(date, m/3, sizeof(date[0]), CmpLink1);     //��ά����   ����
    
    Output1(date , m/3);
}

void load2()                                           //�ṹ������   �洢 
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
	qsort(t, m/3, sizeof(record), CmpLink2);         //�ṹ������   ���� 
	
	Output2(t , m/3);
}

void load3()                                           //ָ������    �洢 
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
	
	qsort(s, m/3, sizeof(record), CmpLink3);         //ָ������   ����
	
	Output3(s , m/3);
}

void load4()                                       //����     �洢 
{
    LINK PHead = (LINK)malloc(sizeof(NODE));    //    ��������һ��ͷ�ڵ��ڴ�ռ�
    LINK p1 = (LINK)malloc(sizeof(NODE));    //    ����һ���½ڵ�
    PHead->next = p1;    //ע�⸳ֵ����     
    int i;
    for(i = 1;i < m;i+=3)
        {
        	p1->s1 = a[i];
        	p1->s2 = a[i+1];
        	p1->s3 = a[i+2];
        	p1->next = (LINK)malloc(sizeof(NODE));    //    ����һ���½ڵ�
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
	    
	qsort((NODE *)(All), m/3, sizeof(NODE *), CmpLink4);    //����   ����
	
    int Tmp;
    printf("������ʽ���������Ϊ��\n");
	for(Tmp = 0; Tmp < m/3; Tmp++)  
	{
		printf("%d,%d,%d\n", All[Tmp]->s1, All[Tmp]->s2, All[Tmp]->s3);
	}  		
}


