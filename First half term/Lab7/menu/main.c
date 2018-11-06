#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    
	int a,b;
	printf("此菜单功能有：\n");
    printf("功能1：打印Hello World!                 (输入“1”实现)\n");
    printf("功能2：100以内正整数立方和              (输入“2”实现)\n");
    printf("功能3：计算任意四边形面积               (输入“3”实现)\n");
    printf("功能4：求球的体积和表面积               (输入“4”实现)\n");
    
	while(1)
  {
	printf("请输入你想要的，Sir/lady!\n");
	scanf("%d",&a); 
	
	switch(a)
	{
		case 1: Test1();break;
		case 2: Test2();break;
		case 3: Test3();break;
		case 4: Test4();break;
		default: printf("你输入有毛病，老铁！\n");
	}
	
	printf("输入1继续，输入0结束\n");
	scanf("%d",&b);
	if(b == 1)     continue;
	else               break;
  }
  
	return 0;
}
