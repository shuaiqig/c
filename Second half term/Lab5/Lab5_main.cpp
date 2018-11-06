#include<stdio.h>
#include<string.h>
#include"Lab5_main.h"
#include"Lab4.h"
#include"Lab5_loadfile.h"



void run()
{
	printf("郭帅旗的实验5程序：\n");
	printf("1. 调用实验4程序生成记录文件（文本方式）\n");
	printf("2. 调用实验4程序生成记录文件（二进制方式）\n");
	printf("3. 调用实验5程序读取指定数据记录文件并排序（二维数组存储方式）\n");
	printf("4. 调用实验5程序读取指定数据记录文件并排序（结构体数组存储方式）\n");
	printf("5. 调用实验5程序读取指定数据记录文件并排序（指针数组存储方式）\n");
	printf("6. 调用实验5程序读取指定数据记录文件并排序（链表存储方式）\n");
	printf("7. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（文本方式输出，二维数组方式存储）\n");
	printf("8. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（文本方式输出，结构体数组方式存储）\n");
	printf("9. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（文本方式输出，指针数组方式存储）\n");
	printf("10. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（文本方式输出，链表方式存储） \n");
	printf("11. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（二进制方式输出，二维数组方式存储）\n");
	printf("12. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（二进制方式输出，结构体数组方式存储）\n");
	printf("13. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（二进制方式输出，指针数组方式存储）\n");
	printf("14. 同时调用实验4、5程序生成数据记录文件、读取数据记录文件并排序（二进制方式输出，链表方式存储）\n");
	printf("15.调用实验4程序生成数据记录文件（文本方式），读取数据记录文件并同时以四种方式存储数据记录并排序（不显示排序结果）\n");
	printf("16.调用实验4程序生成数据记录文件（二进制方式），读取数据记录文件并同时以四种方式存储数据记录并排序（不显示排序结果）\n");
	printf("0. 退出\n");
	printf("请输入您要执行的程序序号：\n");
	
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




