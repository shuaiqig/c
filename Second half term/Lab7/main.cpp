#include<iostream>
#include<stdio.h>
#include <windows.h>
#include<string.h>
#include<time.h>
#include"run.h"
#include"start.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	printf("��˧���ʵ��7����\n"); 
	printf("  1. ����ʵ��4��������1�����ݼ�¼�ļ�����ɶԸ��ļ��ķ��棨����̨��������������ļ���\n");
	printf("  2. ����ʵ��4��������1�����ݼ�¼�ļ�����ɶԸ��ļ��ķ��棨�������ļ�����ϸ���������ʽ��\n");
	printf("  3. ����ʵ��4��������1�����ݼ�¼�ļ�����ɶԸ��ļ��ķ��棨�������ļ�����Ҫ�����ʽ��\n");
	printf("  4. ����ʵ��4��������n�����ݼ�¼�ļ�����ɶ���n���ļ��ķ��棨�������ļ�����Ҫ�����ʽ��\n");
	printf("  5. ����ʵ��4��������n�����ݼ�¼�ļ�����ɶ���n���ļ��ķ��棨�������ļ�����Ҫ�����ʽ���������ʱ��\n");
	printf("  6. �޸�ʵ��4����������ļ�\n");
	printf("  0. �˳�\n");
	printf("��������Ҫִ�еĳ�����ţ�\n");
	
	
	int a;
	while(scanf("%d", &a))
		switch(a){
		
			case 1:{
			
				system("E:\\����\\��һ��\\���ߴ�ʵ��\\Lab4.exe 5 Lab4.txt");
				char file[100] = "Lab4.txt";
				int n = 5;
				int date[n][3];
				load(file, date);    //��ȡ���洢 ������ 
	
				start_1(date, n);
				break;
			}
		
			case 2:{
			
				system("E:\\����\\��һ��\\���ߴ�ʵ��\\Lab4.exe 40 Lab4.txt");
				char file[100] = "Lab4.txt";
				int n = 40;
				int date[n][3];
				load(file, date);    //��ȡ���洢 ������ 
	
				start_2(date, n);
				break;
			}
		
			case 3:{
			
				system("E:\\����\\��һ��\\���ߴ�ʵ��\\Lab4.exe 5 Lab4.txt");
				char file[100] = "Lab4.txt";
				int n = 5;
				int date[n][3];
				load(file, date);    //��ȡ���洢 ������ 
				
				start_3(date, n);
				break;
			}
		
			case 4:{
				
				printf("����������ļ�������\n");
				int m;
				scanf("%d", &m);	
				
				FILE *fp;
   				if((fp = fopen("E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�4.txt", "w")) == NULL)
   					{
   						printf("�ļ�����ʧ�ܣ�\n");
   						break ;
					}
				else
					{
						fprintf(fp, "*****************************���������Ϣ*****************************\n");
						fprintf(fp, "�������¥������20\n");
						fprintf(fp, "���η����û������ļ�������%d\n", m);
						fprintf(fp, "����������ͣ���Ҫ���\n");
					}
	
				int mi;
				for(mi = 1; mi <= m; mi++)
					{        					
						system("E:\\����\\��һ��\\���ߴ�ʵ��\\Lab4.exe 5 Lab4.txt");
						Sleep(1000);
						char file[100] = "Lab4.txt";
						int n = 5;
						int date[n][3];
						load(file, date);    //��ȡ���洢 ������
		
						start_4(date, n, m, mi, fp);
					}

				fclose(fp);		
				printf("�ļ��������,�����E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�4.txt\n");	

				break;
			}
		
			case 5:{
				
				printf("����������ļ�������\n");
				int m;
				scanf("%d", &m);	
				
				FILE *fp;
   				if((fp = fopen("E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�5.txt", "w")) == NULL)
   					{
   						printf("�ļ�����ʧ�ܣ�\n");
   						break ;
					}
				else
					{
						fprintf(fp, "*****************************���������Ϣ*****************************\n");
						fprintf(fp, "�������¥������20\n");
						fprintf(fp, "���η����û������ļ�������%d\n", m);
						fprintf(fp, "����������ͣ���Ҫ���\n");
					}
				
				clock_t t_start1, t_start2, t_start3, t_end1, t_end2, t_end3;
				double TheTimes1, TheTimes2, TheTimes3;
				int mi;
				for(mi = 1; mi <= m; mi++)
					{        					
						t_start1 = clock();
						system("E:\\����\\��һ��\\���ߴ�ʵ��\\Lab4.exe 50 Lab4.txt");
						t_end1 = clock();
						TheTimes1 = (double)(t_end1-t_start1)/CLOCKS_PER_SEC;
						
						Sleep(1000);
						char file[100] = "Lab4.txt";
						int n = 50;
						int date[n][3];
						
						t_start2 = clock();
						load(file, date);    //��ȡ���洢 ������
						t_end2 = clock();
						TheTimes2 = (double)(t_end2-t_start2)/CLOCKS_PER_SEC;
		
						t_start3 = clock();
						start_4(date, n, m, mi, fp);
						t_end3 = clock();
						TheTimes3 = (double)(t_end3-t_start3)/CLOCKS_PER_SEC;
					
						
						fprintf(fp, "���ݼ�¼�ļ�����ʱ�䣺%lf s  ���ݼ�¼�ļ�����ʱ�䣺%lf s  ����������ʱ�䣺%lf s\n", TheTimes1, TheTimes2, TheTimes3);
					}	
						fclose(fp);	
						printf("�ļ��������,�����E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�5.txt\n");
								
				break;
			}
		
			case 6:{
			
			
				break;
			}
		
			case 0:{
				return 0;
				break;
			}
		
	}//500�û� 32¥ 300ʱ�� 
}
