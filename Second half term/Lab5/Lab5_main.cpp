#include<stdio.h>
#include<string.h>
#include"Lab5_main.h"
#include"Lab4.h"
#include"Lab5_loadfile.h"



void run()
{
	printf("��˧���ʵ��5����\n");
	printf("1. ����ʵ��4�������ɼ�¼�ļ����ı���ʽ��\n");
	printf("2. ����ʵ��4�������ɼ�¼�ļ��������Ʒ�ʽ��\n");
	printf("3. ����ʵ��5�����ȡָ�����ݼ�¼�ļ������򣨶�ά����洢��ʽ��\n");
	printf("4. ����ʵ��5�����ȡָ�����ݼ�¼�ļ������򣨽ṹ������洢��ʽ��\n");
	printf("5. ����ʵ��5�����ȡָ�����ݼ�¼�ļ�������ָ������洢��ʽ��\n");
	printf("6. ����ʵ��5�����ȡָ�����ݼ�¼�ļ�����������洢��ʽ��\n");
	printf("7. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ�������ά���鷽ʽ�洢��\n");
	printf("8. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ������ṹ�����鷽ʽ�洢��\n");
	printf("9. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ�����ָ�����鷽ʽ�洢��\n");
	printf("10. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ���������ʽ�洢�� \n");
	printf("11. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�������ά���鷽ʽ�洢��\n");
	printf("12. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ������ṹ�����鷽ʽ�洢��\n");
	printf("13. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�����ָ�����鷽ʽ�洢��\n");
	printf("14. ͬʱ����ʵ��4��5�����������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ���������ʽ�洢��\n");
	printf("15.����ʵ��4�����������ݼ�¼�ļ����ı���ʽ������ȡ���ݼ�¼�ļ���ͬʱ�����ַ�ʽ�洢���ݼ�¼�����򣨲���ʾ��������\n");
	printf("16.����ʵ��4�����������ݼ�¼�ļ��������Ʒ�ʽ������ȡ���ݼ�¼�ļ���ͬʱ�����ַ�ʽ�洢���ݼ�¼�����򣨲���ʾ��������\n");
	printf("0. �˳�\n");
	printf("��������Ҫִ�еĳ�����ţ�\n");
	
	int g;
	while(scanf("%d" , &g))
	    {
	    	switch(g){
			
			case 0:{
				return ;
				break;
			}
			
			case 1:{
				char c[3][100] = {"5" , "Lab4.txt" , "w"};
				Lab4(c);
				break;
			}
			
			case 2:{
				char c[3][100] = {"5" , "Lab4.dat" , "wb"};
				Lab4(c);
				break;
			}
			
			case 3:{
	            load(file);
	            load1();
				break;
			}
			
			case 4:{
	            load(file);
	            load2();
				break;
			}
			
			case 5:{
	            load(file);
	            load3();
				break;
			}
			
			case 6:{
	            load(file);
	            load4();
				break;
			}
			
			case 7:{
				char c[3][100] = {"5" , "Lab4.txt" , "w"};
				Lab4(c);
	            load(file);
	            load1();
	            
				break;
			}
			
			case 8:{
				char c[3][100] = {"5" , "Lab4.txt" , "w"};
				Lab4(c);
	            load(file);
	            load2();
				break;
			}
			
			case 9:{
				char c[3][100] = {"5" , "Lab4.txt" , "w"};
	            Lab4(c);
				load(file);
	            load3();
				break;
			}
			
			case 10:{
				char c[3][100] = {"5" , "Lab4.txt" , "w"};
				Lab4(c);
	            load(file);
	            load4();
				break;
			}
			
			case 11:{
				char c[3][100] = {"5" , "Lab4.dat" , "wb"};
				Lab4(c);
	            load(file);
	            load1();
	            
				break;
			}
			
			case 12:{
				char c[3][100] = {"5" , "Lab4.dat" , "wb"};
				Lab4(c);
	            load(file);
	            load2();
				break;
			}
			
			case 13:{
				char c[3][100] = {"5" , "Lab4.dat" , "wb"};
	            Lab4(c);
				load(file);
	            load3();
				break;
			}
			
			case 14:{
				char c[3][100] = {"5" , "Lab4.dat" , "wb"};
				Lab4(c);
	            load(file);
	            load4();
				break;
			}
			
			case 15:{
				char c[3][100] = {"5" , "Lab4.txt" , "w"};
				Lab4(c);
	            load(file);
	            load1();
	            load2();
	            load3();
	            load4();
				break;
			}
			
			case 16:{
				char c[3][100] = {"5" , "Lab4.dat" , "wb"};
				Lab4(c);
	            load(file);
	            load1();
	            load2();
	            load3();
	            load4();
				break;
			}
			
		} 
    } 
} 




