/*指针变量基础，各个数据类型、大小、地址*/ 
#include<stdio.h>

int main()
{
	int a,e,*pe;
	float b,f,*pf;
	char c,g,*pg;
	double d,h,*ph;
    
    a = 1;
    b = 2;
    c = '*';
    d = 3;
	e = 4,pe = &e;
	f = 5,pf = &f;
	g = '@',pg = &g;
	h = 6,ph = &h;	
	printf("\nVarName    Type    Size    Address        Value\n");
    printf("   a        int     %d     %08xH    %d\n",sizeof(a),&a,a);
	printf("   b      float     %d     %08xH    %10.2f\n",sizeof(b),&b,b);
    printf("   c       char     %d     %08xH    %c\n",sizeof(c),&c,c);
	printf("   d     double     %d     %08xH    %10.2f\n",sizeof(d),&d,d);
    printf("  pe       int*     %d     %08xH    %08xH\n",sizeof(pe),&pe,pe);
	printf("  pf      float*    %d     %08xH    %08xH\n",sizeof(pf),&pf,pf);
    printf("  pg       char*    %d     %08xH    %08xH\n",sizeof(pg),&pg,pg);		
    printf("  ph     double*    %d     %08xH    %08xH\n",sizeof(ph),&ph,ph);
    
    return 0;
}
