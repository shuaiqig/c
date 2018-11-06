#ifndef CODEFORLAB2_H_  
#define CODEFORLAB2_H_


extern char file[100];

typedef struct configinfo{
	char  filesavepath[100] ;      //用于存放数据记录文件的默认存储目录 
	char  filename[100] ;                    //用于存储生成的默认文件名信息 
	int  maxvalue1 ;     //用于存放实验1中生成的数据记录三元组中第1、2个元素元素值的上限 
	int  minvalue1;   //用于存放实验1中生成的数据记录三元组中第1、2个元素元素值的下限 
	int  maxvalue2 ;     //用于存放实验1中生成的数据记录三元组中第3个元素元素值的上限 
	int  minvalue2;   //用于存放实验1中生成的数据记录三元组中第3个元素元素值的下限 
	int  recordcount1; //用于存放数据记录文件中需要生成的记录条数上限 
	int  recordcount2; //用于存放数据记录文件中需要生成的记录条数下限 
	int  recordcount;  //用于存放数据记录文件中需要生成的记录条数
	}CONF;
	
void Lab4(char c[3][100]);
CONF Configuration(CONF s);
void write(CONF r , char w[]);
int RandRanges(int a , int b);

#endif
