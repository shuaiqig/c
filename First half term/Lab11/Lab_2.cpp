/*检查两个字符串是否由同一字符组成.
  判断一个字符串是否可以通过另一个字符串重排得到*/

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
	   	      	 if(*p == *l)        k++;   /*k != 0时大吉大利，能找到*/ 
			  }
		  if(k == 0)                 j++;   /*若前一个字符串中的字符都能在后一个中找到，返回0；否则返回1*/  
	   }
	return j;
}

void zucheng(char *pa,char *pb)
{
	if(A(pa,pb) + A(pb,pa) == 0)     
	  printf("这两串字符串由 <相同> 字符组成\n");
	else
	  printf("这两串字符串由 <不同> 字符组成\n");
}

int B(char *pc,char c)
{
	int i = 0;
	char *p;
	for(p = pc;*p != '\0';p++)
	   if(*p == c)             i++;
	return i;              /*返回一个字符串中某字符个数*/ 
}

void chuongpai(char *pa,char *pb)
{
    int i = 1,j = 0,k;
	char *p,*l,c[n];
	
	if(A(pa,pb) + A(pb,pa) != 0)    
	  printf("一个字符串 <不能> 通过另一个字符串重排得到\n");
	  
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
	  c[i] = '\0';              /*提取a[]/b[]中的字符*/ 
	  printf("两个字符串组成字符均为：");
	  puts(c);
	  
	  for(p = c;*p != '\0';p++)
	     if(B(pa,*p) != B(pb,*p))     j++;
	  
	  if(j == 0)        printf("一个字符串 <能> 通过另一个字符串重排得到\n");
	  else              printf("一个字符串 <不能> 通过另一个字符串重排得到\n");
    }
}

int main()
{
	char a[n],b[n],c = 'a';
	printf("请输入字符串a[]: ");
	gets(a);
	printf("请输入字符串b[]: ");
    fflush(stdin);
    gets(b);
    
    zucheng(a,b);
    chuongpai(a,b);
    
	return 0;
}
