#include<stdio.h>

void ArrayBoundaryTest() 
{  
   double a = 1.5; 
   int i = 1, arr[10] = {0};  
   double b = 2.5;  int j;  
   printf("%d\t %10.2f\n", i, a);                //1号输出命令  
   for (j = 1; j <= 10; j++)   
        arr[j] = j;                              //请判断此处何时会产生越界  (j = 10时） 
   arr[12] = 12;                                 //判断此语句会影响的变量     (arr[11] = 0,arr[12] = 12)
   printf("%d\t %10.2f\n", i, a);                //2号输出命令
   printf("%d",j);
   //跟踪观察前两条 printf 语句（1号和2号输出命令）所输出的i和a的值所发生的变化, 解释原因 
 
   arr[-1] = 1;                                  //跟踪观察变量b的值所发生的变化，解释原因  
   arr[-3] = 3;                                  //跟踪观察变量 j的值所发生的变化，解释原因  
   arr[100] = 100;                               //观察此语句产生的跟踪警告，解释原因，说明为什么前几条越界语句不出现此警告 
}

int main()
{
	ArrayBoundaryTest();
	return 0;
}
