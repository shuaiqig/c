/*引用函数求1到100之间被6或7整除的所有数*/
#include<stdio.h>
int times1(int)
{
	int i;
	for(i = 1;i <= 100;i++)
	  {
	   if     (i % 6 == 0)	         printf("%d\t",i);
	   else if(i % 7 == 0)	     printf("%d\t",i);
      }
}
int times2(int)
{
	int i;
	for(i = 1;i <= 100;i++)
	  {
	   if     (i % 6 == 0 && i % 7 != 0)	         printf("%d\t",i);
	   else if(i % 7 == 0 && i % 6 != 0)	         printf("%d\t",i);
      }
}
int main()
{
	int n;
	times1(n);
	printf("\n");
	times2(n);
	
	return 0;
}
