#ifndef CODEFORLAB2_H_  
#define CODEFORLAB2_H_


extern char file[100];

typedef struct configinfo{
	char  filesavepath[100] ;      //���ڴ�����ݼ�¼�ļ���Ĭ�ϴ洢Ŀ¼ 
	char  filename[100] ;                    //���ڴ洢���ɵ�Ĭ���ļ�����Ϣ 
	int  maxvalue1 ;     //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��Ԫ��ֵ������ 
	int  minvalue1;   //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��Ԫ��ֵ������ 
	int  maxvalue2 ;     //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��Ԫ��ֵ������ 
	int  minvalue2;   //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��Ԫ��ֵ������ 
	int  recordcount1; //���ڴ�����ݼ�¼�ļ�����Ҫ���ɵļ�¼�������� 
	int  recordcount2; //���ڴ�����ݼ�¼�ļ�����Ҫ���ɵļ�¼�������� 
	int  recordcount;  //���ڴ�����ݼ�¼�ļ�����Ҫ���ɵļ�¼����
	}CONF;
	
void Lab4(char c[3][100]);
CONF Configuration(CONF s);
void write(CONF r , char w[]);
int RandRanges(int a , int b);

#endif
