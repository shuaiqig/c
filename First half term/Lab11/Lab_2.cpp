/*��������ַ����Ƿ���ͬһ�ַ����.
  �ж�һ���ַ����Ƿ����ͨ����һ���ַ������ŵõ�*/

#include<stdio.h>
#include<stdlib.h>
#define n 100

int A(char *pa,char *pb)
{
	char *p,*l;
	int k,j = 0;
	for(p = pa;*p != '\0';p++)
	   {
	   	  k = 0;
	   	  for(l = pb;*l != '\0';l++)
	   	      {
	   	      	 if(*p == *l)        k++;   /*k != 0ʱ�󼪴��������ҵ�*/ 
			  }
		  if(k == 0)                 j++;   /*��ǰһ���ַ����е��ַ������ں�һ�����ҵ�������0�����򷵻�1*/  
	   }
	return j;
}

void zucheng(char *pa,char *pb)
{
	if(A(pa,pb) + A(pb,pa) == 0)     
	  printf("�������ַ����� <��ͬ> �ַ����\n");
	else
	  printf("�������ַ����� <��ͬ> �ַ����\n");
}

int B(char *pc,char c)
{
	int i = 0;
	char *p;
	for(p = pc;*p != '\0';p++)
	   if(*p == c)             i++;
	return i;              /*����һ���ַ�����ĳ�ַ�����*/ 
}

void chuongpai(char *pa,char *pb)
{
    int i = 1,j = 0,k;
	char *p,*l,c[n];
	
	if(A(pa,pb) + A(pb,pa) != 0)    
	  printf("һ���ַ��� <����> ͨ����һ���ַ������ŵõ�\n");
	  
	else
	{
	  c[0] = *pa;
	  for(p = pa+1;*p != '\0';p++)
	     {
	     	k = 0;
	     	for(l = pa;l < p;l++)       
	     	   if(*p == *l)           k++;
			if(k == 0)	            {c[i] = *p; i++;}
		 }
	  c[i] = '\0';              /*��ȡa[]/b[]�е��ַ�*/ 
	  printf("�����ַ�������ַ���Ϊ��");
	  puts(c);
	  
	  for(p = c;*p != '\0';p++)
	     if(B(pa,*p) != B(pb,*p))     j++;
	  
	  if(j == 0)        printf("һ���ַ��� <��> ͨ����һ���ַ������ŵõ�\n");
	  else              printf("һ���ַ��� <����> ͨ����һ���ַ������ŵõ�\n");
    }
}

int main()
{
	char a[n],b[n],c = 'a';
	printf("�������ַ���a[]: ");
	gets(a);
	printf("�������ַ���b[]: ");
    fflush(stdin);
    gets(b);
    
    zucheng(a,b);
    chuongpai(a,b);
    
	return 0;
}
