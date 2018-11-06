#include<stdio.h>
	int m,n;
void  CountRangeItems(double a[], int n, int b[])
{
	int i;
	for(i = 0;i < m;i++)
	  {
	    if     (a[i] <  160&&a[i] > 0)          b[0]++;   
	    else if(a[i] >= 160&&a[i] < 165)        b[1]++;
	    else if(a[i] >= 165&&a[i] < 170)        b[2]++;
	    else if(a[i] >= 170&&a[i] < 175)        b[3]++;
	    else                                    b[4]++;    /*以身高为例*/ 
      }
    for(i = 0;i < n;i++)
       printf("%3d",b[i]);
}


int main()
{
    int i;
	printf("请输入数组a元素个数\n");
	scanf("%d",&m);
	printf("请输入数组b元素个数(5)\n");
	scanf("%d",&n);
	
	double a[m];
	int b[n] = {0,0,0,0,0};
	printf("请输入数组a\n");
	for(i = 0;i < m;i++)
	   scanf("%lf",&a[i]);
	
	CountRangeItems(a,n,b);
	
	return 0;
}
