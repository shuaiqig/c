/*ֱ��ͼ*/ 
#include<stdio.h>

void DrawHistogram(int a[], int n, char c)
{
	int i,j;
	for(i = 0;i < n;i++)
	   {
	   	printf("%4d",a[i]);
		printf("  ");
	   	while(a[i] > 0)
	   	   {
	   	   	   printf("%c",c);
	   	   	   a[i]--;
		   }
        printf("\n");
		}
}

int main()
{
	int i,n;
	char c;
	printf("�������ַ�\n");
    scanf("%c",&c);
	printf("����������Ԫ�ظ���'n'\n");
	scanf("%d",&n);
	int a[n];
	

	printf("����������\n");		
	for(i = 0;i < n;i++)
	   scanf("%d",&a[i]);
	
	
	DrawHistogram(a,n,c);
	
	
	
	return 0;
}
