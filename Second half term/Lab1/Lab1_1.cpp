#include<stdio.h>

void ArrayBoundaryTest() 
{  
   double a = 1.5; 
   int i = 1, arr[10] = {0};  
   double b = 2.5;  int j;  
   printf("%d\t %10.2f\n", i, a);                //1���������  
   for (j = 1; j <= 10; j++)   
        arr[j] = j;                              //���жϴ˴���ʱ�����Խ��  (j = 10ʱ�� 
   arr[12] = 12;                                 //�жϴ�����Ӱ��ı���     (arr[11] = 0,arr[12] = 12)
   printf("%d\t %10.2f\n", i, a);                //2���������
   printf("%d",j);
   //���ٹ۲�ǰ���� printf ��䣨1�ź�2���������������i��a��ֵ�������ı仯, ����ԭ�� 
 
   arr[-1] = 1;                                  //���ٹ۲����b��ֵ�������ı仯������ԭ��  
   arr[-3] = 3;                                  //���ٹ۲���� j��ֵ�������ı仯������ԭ��  
   arr[100] = 100;                               //�۲���������ĸ��پ��棬����ԭ��˵��Ϊʲôǰ����Խ����䲻���ִ˾��� 
}

int main()
{
	ArrayBoundaryTest();
	return 0;
}