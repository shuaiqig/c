#include<iostream>
#include<stdio.h>
#include <windows.h>
#include<string.h>
#include<time.h>
#include"run.h"
#include"start.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	printf("郭帅旗的实验7程序：\n"); 
	printf("  1. 调用实验4程序生成1个数据记录文件并完成对该文件的仿真（控制台输出，不输出结果文件）\n");
	printf("  2. 调用实验4程序生成1个数据记录文件并完成对该文件的仿真（输出结果文件，详细过程输出方式）\n");
	printf("  3. 调用实验4程序生成1个数据记录文件并完成对该文件的仿真（输出结果文件，概要输出方式）\n");
	printf("  4. 调用实验4程序生成n个数据记录文件并完成对这n个文件的仿真（输出结果文件，概要输出方式）\n");
	printf("  5. 调用实验4程序生成n个数据记录文件并完成对这n个文件的仿真（输出结果文件，概要输出方式，带仿真计时）\n");
	printf("  6. 修改实验4程序的配置文件\n");
	printf("  0. 退出\n");
	printf("请输入您要执行的程序序号：\n");
	
	
	int a;
	while(scanf("%d", &a))
		switch(a){
		
			case 1:{
			
				system("E:\\代码\\大一下\\第七次实验\\Lab4.exe 5 Lab4.txt");
				char file[100] = "Lab4.txt";
				int n = 5;
				int date[n][3];
				load(file, date);    //读取，存储 ，排序 
	
				start_1(date, n);
				break;
			}
		
			case 2:{
			
				system("E:\\代码\\大一下\\第七次实验\\Lab4.exe 40 Lab4.txt");
				char file[100] = "Lab4.txt";
				int n = 40;
				int date[n][3];
				load(file, date);    //读取，存储 ，排序 
	
				start_2(date, n);
				break;
			}
		
			case 3:{
			
				system("E:\\代码\\大一下\\第七次实验\\Lab4.exe 5 Lab4.txt");
				char file[100] = "Lab4.txt";
				int n = 5;
				int date[n][3];
				load(file, date);    //读取，存储 ，排序 
				
				start_3(date, n);
				break;
			}
		
			case 4:{
				
				printf("请输入仿真文件个数：\n");
				int m;
				scanf("%d", &m);	
				
				FILE *fp;
   				if((fp = fopen("E:\\代码\\大一下\\第七次实验\\仿真文件4.txt", "w")) == NULL)
   					{
   						printf("文件创建失败！\n");
   						break ;
					}
				else
					{
						fprintf(fp, "*****************************仿真基本信息*****************************\n");
						fprintf(fp, "电梯最大楼层数：20\n");
						fprintf(fp, "本次仿真用户请求文件数量：%d\n", m);
						fprintf(fp, "仿真输出类型：概要输出\n");
					}
	
				int mi;
				for(mi = 1; mi <= m; mi++)
					{        					
						system("E:\\代码\\大一下\\第七次实验\\Lab4.exe 5 Lab4.txt");
						Sleep(1000);
						char file[100] = "Lab4.txt";
						int n = 5;
						int date[n][3];
						load(file, date);    //读取，存储 ，排序
		
						start_4(date, n, m, mi, fp);
					}

				fclose(fp);		
				printf("文件生成完毕,请查阅E:\\代码\\大一下\\第七次实验\\仿真文件4.txt\n");	

				break;
			}
		
			case 5:{
				
				printf("请输入仿真文件个数：\n");
				int m;
				scanf("%d", &m);	
				
				FILE *fp;
   				if((fp = fopen("E:\\代码\\大一下\\第七次实验\\仿真文件5.txt", "w")) == NULL)
   					{
   						printf("文件创建失败！\n");
   						break ;
					}
				else
					{
						fprintf(fp, "*****************************仿真基本信息*****************************\n");
						fprintf(fp, "电梯最大楼层数：20\n");
						fprintf(fp, "本次仿真用户请求文件数量：%d\n", m);
						fprintf(fp, "仿真输出类型：概要输出\n");
					}
				
				clock_t t_start1, t_start2, t_start3, t_end1, t_end2, t_end3;
				double TheTimes1, TheTimes2, TheTimes3;
				int mi;
				for(mi = 1; mi <= m; mi++)
					{        					
						t_start1 = clock();
						system("E:\\代码\\大一下\\第七次实验\\Lab4.exe 50 Lab4.txt");
						t_end1 = clock();
						TheTimes1 = (double)(t_end1-t_start1)/CLOCKS_PER_SEC;
						
						Sleep(1000);
						char file[100] = "Lab4.txt";
						int n = 50;
						int date[n][3];
						
						t_start2 = clock();
						load(file, date);    //读取，存储 ，排序
						t_end2 = clock();
						TheTimes2 = (double)(t_end2-t_start2)/CLOCKS_PER_SEC;
		
						t_start3 = clock();
						start_4(date, n, m, mi, fp);
						t_end3 = clock();
						TheTimes3 = (double)(t_end3-t_start3)/CLOCKS_PER_SEC;
					
						
						fprintf(fp, "数据记录文件生成时间：%lf s  数据记录文件加载时间：%lf s  仿真结果生成时间：%lf s\n", TheTimes1, TheTimes2, TheTimes3);
					}	
						fclose(fp);	
						printf("文件生成完毕,请查阅E:\\代码\\大一下\\第七次实验\\仿真文件5.txt\n");
								
				break;
			}
		
			case 6:{
			
			
				break;
			}
		
			case 0:{
				return 0;
				break;
			}
		
	}//500用户 32楼 300时间 
}
