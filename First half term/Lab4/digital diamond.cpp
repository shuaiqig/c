/*引用函数打印数字菱形*/ 
#include<stdio.h>
int PrintNumbers(int line)
{
	int i,j;
	
	if(line < 1)                                printf("enter error\n");
	  
	  else
	  
		 for(i = 1;i <= line;i++)
	     {
	     	for(j = 1;j <= line+1-i;j++)        printf(" ");
	     	
	     	for(j = 1;j <= i;j++)               printf("%d",j);
	     	
	     	for(j = i-1;j >= 1;j--)             printf("%d",j);
	     	
	     	printf("\n");
		 }  
		 
		 for(i = line-1;i >= 1;i--)
		 {
		    for(j = 1;j <= line+1-i;j++)        printf(" ");
	     	
	     	for(j = 1;j <= i;j++)               printf("%d",j);
	     	
	     	for(j = i-1;j >= 1;j--)             printf("%d",j);
	     	
	     	printf("\n");
		 }   
      
}

int main()
{
	int line;
	printf("please enter a number 'line'\n");
	scanf("%d",&line);
	PrintNumbers(line);
	 
	return 0;
}
