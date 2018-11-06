// 20182.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

typedef struct node
{
	int x,y;
}anstype;

int matrix[1000][1000];

anstype ans[1000];


int lenx = 0,leny = -1;

void prepare();

void work();

void printans();

int main()
{
	prepare();
	work();
	printans();
	return 0;
}

void prepare()
{
	ans[0].x = 0;
	char tem;
	int Intem = -1;
	printf("输入一个矩阵\n");
	while(1){
		leny = 0;
		while(1){
			while(tem = getchar(),tem == ' ');
			if((tem == '\n')||(tem == EOF)) break;
			matrix[lenx][leny] = tem-'0';              //输入一行 
			leny = leny+1;
		}
		if(leny > Intem) Intem = leny;
		if(tem == EOF) break;
		lenx = lenx+1;                                 //下一行 
	}
	leny = Intem;
}

int check(int x,int y)
{
	int i;
	for(i = 0;i < lenx;i = i+1){
		if(matrix[i][y] < matrix[x][y]) return 0;      //检查是否符合所在列最小 
	}
	return 1;
}

void remember(int x,int y)
{
	ans[0].x = ans[0].x+1;
	ans[ans[0].x].x = x;
	ans[ans[0].x].y = y;
}


void work()
{
	int i,j;
	int tem;
	int ColIndex[100] = {0};

	for(i = 0;i < lenx;i = i+1){
		tem = 0;
		ColIndex[0] = 0;                          //修改处，重置	ColIndex[0] 的值 
		for(j = 1;j < leny;j = j+1) 
			if(matrix[i][j] > matrix[i][tem])
				tem = j;                          //找每行最大 
		for(j = 0;j < leny;j = j+1){ 
			if(matrix[i][j] == matrix[i][tem]){   //同为最大的处理 
				ColIndex[0] = ColIndex[0] + 1;
				ColIndex[ColIndex[0]] = j;        //逐个存储同为最大的列数 
			}
		}
		for(j = 1;j <= ColIndex[0];j = j+1){
			if(check(i,ColIndex[j]) == 1)
			    remember(i,ColIndex[j]);
		}
	}
}

void printans()
{
	if(ans[0].x == 0){
		printf("no result found\n");
		return;
	}
	int i;
	for(i = 1;i <= ans[0].x;i = i+1){
		printf("the %dth saddle position is (%d,%d)\n",i,ans[i].x+1,ans[i].y+1);
	}
}
