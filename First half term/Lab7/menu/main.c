#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    
	int a,b;
	printf("�˲˵������У�\n");
    printf("����1����ӡHello World!                 (���롰1��ʵ��)\n");
    printf("����2��100����������������              (���롰2��ʵ��)\n");
    printf("����3�����������ı������               (���롰3��ʵ��)\n");
    printf("����4�����������ͱ����               (���롰4��ʵ��)\n");
    
	while(1)
  {
	printf("����������Ҫ�ģ�Sir/lady!\n");
	scanf("%d",&a); 
	
	switch(a)
	{
		case 1: Test1();break;
		case 2: Test2();break;
		case 3: Test3();break;
		case 4: Test4();break;
		default: printf("��������ë����������\n");
	}
	
	printf("����1����������0����\n");
	scanf("%d",&b);
	if(b == 1)     continue;
	else               break;
  }
  
	return 0;
}
