/*������*/ 
#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,result;
	char yunsuanfu;
	scanf("%c %lf %lf",&yunsuanfu,&a,&b);
	
	switch(yunsuanfu)
	{
		case'+': result = (a + b),printf("result = %.2lf",result);break;
		
		case'*': result = a * b,printf("result = %.2lf",result);break;
		
		case'-': result = a * b,printf("result = %.2lf",result);break;
		
		case'/':
		        if(b == 0)
		          printf("����Ϊ��������\n");
		        else
		        result = a / b,printf("result = %.2lf",result);break; 
		        
		default:printf("δ֪�����\n");
		
    }
}
