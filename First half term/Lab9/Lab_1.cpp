/*�۰뷨����*/ 
#include<stdio.h>

int search(int a[], int n, int x)
{
	int i,H = n,L = 1,mid,find = 0;
while(L <= H)
	{
		mid = (H + L)/2;
		if(x == a[mid])        {find = 1;break;		}
		else if(x < a[mid])    H = mid-1;
		else                   L = mid+1;		   
	}
	return find;
}

int main()
{
	int i,a[100],x,n = 10;
	printf("������10���ź��������\n");
	for(i = 1;i <= 10;i++)
	scanf("%d",&a[i]);
	printf("������Ҫ���ҵ���x\n");
	scanf("%d",&x);
	
	printf("find = %d",search(a,n,x));

    return 0;
}
