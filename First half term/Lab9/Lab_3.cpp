/*���ַ���s1��ɾ�����г����ڴ�s2����ַ�*/
#include<stdio.h>
#include<string.h>
#define n 100
char s3[n];

char squeeze(char s1[], char s2[])
 {
 	int i,j,k = 0,f;
	 for(i = 0;s1[i] != '\0';i++)
	    {
		 f = 0;
		 for(j = 0;j < n;j++)
		     if(s1[i] == s2[j])          { f++;}
		      
         if(f == 0)          { s3[k] = s1[i];k++;}
		}

		s3[k] = '\0';
}
 
 int main()
 {
 	int i;
 	char s1[n], s2[n]; 
 	printf("�������ַ���1��\n");
 	gets(s1);
 	printf("�������ַ���2��\n");
 	gets(s2);
 	
 	squeeze(s1,s2);
 	printf("ת����Ľ��Ϊ��\n");
 	puts(s3);
 }
