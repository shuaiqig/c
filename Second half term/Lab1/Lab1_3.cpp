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
	printf("����һ������\n");
	while(1){
		leny = 0;
		while(1){
			while(tem = getchar(),tem == ' ');
			if((tem == '\n')||(tem == EOF)) break;
			matrix[lenx][leny] = tem-'0';              //����һ�� 
			leny = leny+1;
		}
		if(leny > Intem) Intem = leny;
		if(tem == EOF) break;
		lenx = lenx+1;                                 //��һ�� 
	}
	leny = Intem;
}

int check(int x,int y)
{
	int i;
	for(i = 0;i < lenx;i = i+1){
		if(matrix[i][y] < matrix[x][y]) return 0;      //����Ƿ������������С 
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
		ColIndex[0] = 0;                          //�޸Ĵ�������	ColIndex[0] ��ֵ 
		for(j = 1;j < leny;j = j+1) 
			if(matrix[i][j] > matrix[i][tem])
				tem = j;                          //��ÿ����� 
		for(j = 0;j < leny;j = j+1){ 
			if(matrix[i][j] == matrix[i][tem]){   //ͬΪ���Ĵ��� 
				ColIndex[0] = ColIndex[0] + 1;
				ColIndex[ColIndex[0]] = j;        //����洢ͬΪ�������� 
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
