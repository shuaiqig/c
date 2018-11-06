/*直方图*/ 
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
	printf("请输入字符\n");
    scanf("%c",&c);
	printf("请输入数组元素个数'n'\n");
	scanf("%d",&n);
	int a[n];
	

	printf("请输入数组\n");		
	for(i = 0;i < n;i++)
	   scanf("%d",&a[i]);
	
	
	DrawHistogram(a,n,c);
	
	
	
	return 0;
}
