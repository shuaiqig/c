#ifndef CODEFORLOADFILE_H_  
#define CODEFORLOADFILE_H_

typedef struct node NODE, *LINK;     //以链表形式    存储 
struct node//定义链接结构
{
	int s1;
	int s2;
	int s3;
	LINK next;
};

typedef struct record{     
    int r1;
    int r2;
    int r3;
}RECORD;

void load(char file[]);
void load1();
void load2();
void load3();
void load4();

#endif
