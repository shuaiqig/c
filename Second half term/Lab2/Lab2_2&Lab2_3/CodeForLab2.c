/****************************************************\
������Ϣ��
     ��ҵ����ˣ���˧��		ѧ�ţ�17281178
��Ȩ������
     ��Ȩ�ɱ�����ͨ��ѧ���������Ϣ����ѧԺ������ƻ���ѵ���γ�������
ģ������: 
    CodeForLab2.CPP
ժҪ:
    ��ѧ�������룬���ʵ��2
����˵��:

ģ����ʷ:
�������ѷ���2011��10��26�մ�����ģ�飬email: yflin@bjtu.edu.cn
�������ѷ���2012��10��19���޸ı�ģ�飬email: yflin@bjtu.edu.cn
�������ѷ���2013��10��11���޸ı�ģ�飬email: yflin@bjtu.edu.cn
    ������2017��2��16���޸ı�ģ�飬email��shhan@bjtu.edu.cn
	�ֲ�����2018��2��22���޸ı�ģ�飬email: cyjia@bjtu.edu.cn

**********************************************************/
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

//�ı��ļ�ͳ����Ϣ�ṹ��
//��ʾ��ͨ��typedefʹTEXTFILEINFO�ȼ���struct TextFileInfo
typedef struct TextFileInfo
{
	char szFileName[120]; //the file name, should be less than 120 characters
	int nWords; //the number of words separated by spaces
	int nSize; //the size of file in bytes
	int nDigits; //the number of digital charactors
	int nSpaces; //the number of spaces including space , ��\t��, ��\r��, ��\n��
	int nAlphabets; //the number of charactors 'A'--'Z', 'a'--'z'
	int nOthers; //the number of other characters
}TEXTFILEINFO;


//�����ļ�ͳ����Ϣ�ṹ�壬�ýṹ�д�Ÿ����ı��ļ���ͳ����Ϣ
//�����ļ���Ϣ�Ľṹ˳����
typedef struct FilesInfo
{
	TEXTFILEINFO *pFileInfos; 
	//�׸��ļ���ͳ����Ϣ�ṹ���׵�ַ������nFileNumber-1���ļ�����Ϣ˳���������
	//��ʾ����ʹ��pFileInfosʱ�ɽ��俴��һ��������ʹ��,��pFileInfos[i]
	 
	int nFileNumber; //�ļ���Ŀ
	int nNewwords;  //�����ļ��´�����
}FILESINFO;

typedef struct node NODE, *LINK;

struct node//�������ӽṹ
{
	char word[50];	//������
	int count;			//������Ƶ
	LINK next;
};

int AllocateSpaceForTextFilesInfo(FILESINFO *pMyFiles);

int PrepareBasicInfoOfFiles(FILESINFO *pFilesInfo);

int CountFilesInfo(FILESINFO *pFilesInfo);

int CountDifferentCharactersInFile(TEXTFILEINFO *pTextFileInfo);

int ExportFilesInfoToWebPage(FILESINFO *pMyFiles, char *szHtmlFile);

void TestCountFilesInfo();

int CountWordsOfEuropeanTxtFile(char *szFileName);

int CountWordsInOneLine2(const char *szLine);

int CountWordsInOneLine(const char *szLine);

void newWord(FILESINFO *pFilesInfo);

LINK Rank(LINK p);

/*  AllocateSpaceForTextFilesInfo
 *	���ܣ�����FILESINFO������Ĵ洢�ռ�
 *  �������ļ�ͳ����Ϣ�ṹ�����
 *  ע�⣺
 *		1.�ڵ��øú���ǰ�����ȸ���pMyfiles���ļ���ĿnFileNumber
 *		2.����������Ҫ�޸ģ���ֱ��ʹ��
 *  ����ֵ: 0�� �ɹ���-1���������Ϸ���-2���洢�ռ䲻��
 *	ģ����ʷ��
 *	 
 */
 
int AllocateSpaceForTextFilesInfo(FILESINFO *pMyFiles)
{
	//�����Ϸ����ж�
	if (NULL == pMyFiles || pMyFiles->nFileNumber <= 0)
		return -1;

	//������pMyFiles->nFileNumber��TEXTFILEINFO���ͽṹ������Ĵ洢�ռ�
	//���������뵽��pMyFiles->nFileNumber * sizeof(TEXTFILEINFO)���ֽڵ�
	//�洢�ռ��׵�ַ��ŵ�pMyFiles->pFileInfos��
	pMyFiles->pFileInfos = (TEXTFILEINFO *)malloc(pMyFiles->nFileNumber * sizeof(TEXTFILEINFO));

	if (NULL == pMyFiles->pFileInfos)
		return -2;
	
	return 0;

}

/*
 *	��������PrepareBasicInfoOfFiles
 *	���ܣ�׼�������ļ��Ļ�����Ϣ
 *      1. ����ʵ�����ı��ļ��ĸ���
 *      2. ��������ļ�������FILESINFO������Ĵ洢�ռ�
 *		3. �������������ļ���
 *  ������FILESINFO *pFilesInfo���ļ�ͳ����Ϣ�ṹ��ָ��
 *	����ֵ��int
 *	ģ����ʷ��
 */	

int PrepareBasicInfoOfFiles(FILESINFO *pFilesInfo)
{
    pFilesInfo->nFileNumber = 5;
    
    AllocateSpaceForTextFilesInfo(pFilesInfo);
    
	strcpy(pFilesInfo->pFileInfos[0].szFileName , "DataMining.txt" );        //  .txt ����© 
    strcpy(pFilesInfo->pFileInfos[1].szFileName , "Example.txt" );
    strcpy(pFilesInfo->pFileInfos[2].szFileName , "Programming.txt" );
    strcpy(pFilesInfo->pFileInfos[3].szFileName , "Readability.txt" );
    strcpy(pFilesInfo->pFileInfos[4].szFileName , "reality.txt" );       //���ṹ�����ַ�����ֵҪ��strcpy���� 
    
    int i;
	for (i=0;i<pFilesInfo->nFileNumber;i++)
	{
		pFilesInfo->pFileInfos[i].nAlphabets = 0;
		pFilesInfo->pFileInfos[i].nDigits = 0;
		pFilesInfo->pFileInfos[i].nOthers = 0;
		pFilesInfo->pFileInfos[i].nSize = 0;
		pFilesInfo->pFileInfos[i].nSpaces = 0;
		pFilesInfo->pFileInfos[i].nWords = 0;
	}                                                     //  �����ļ��������ṹ���������ֵΪ 0 

	return 0;
}

/*
 *	��������CountFilesInfo
 *	���ܣ�ͳ�Ƹ�����Ϣ
 *		1. ͳ�Ƹ����ļ��е�Ӣ�Ĵʸ���
 *		2. ͳ�Ƹ����ļ��и��������ַ�����
 *	������FILESINFO *pFilesInfo���ļ�ͳ����Ϣ�ṹ��ָ��
 *	����ֵ��int  
 *		     0--����
 *           ������������
 *	 
 */
int CountFilesInfo(FILESINFO *pFilesInfo)
{
	int i;
	for(i = 0;i < pFilesInfo->nFileNumber;i++)
        {
		
		 pFilesInfo->pFileInfos[i].nWords = CountWordsOfEuropeanTxtFile(pFilesInfo->pFileInfos[i].szFileName);                                          
                                                                  //ͳ�Ƹ����ļ��е�Ӣ�Ĵʸ���(nWords), ���ú������� 
         
         CountDifferentCharactersInFile(&pFilesInfo->pFileInfos[i]);      //ע�������ʽ 
		}
	return 0;
}

/***********************************************\
��������:
	CountWordsOfEuropeanTxtFile
��������:
	ͳ��ŷ�������ı��ļ��дʵĸ���
��������:
	char *szFileName �ļ���
����ֵ:
	int �ʵĸ���
ģ����ʷ:
  	
\**********************************************/

int CountWordsOfEuropeanTxtFile(char *szFileName)
{
	int nWords = 0;//�ʼ�����������ʼֵΪ0
	FILE *fp; //�ļ�ָ��
	char carrBuffer[1024];//ÿ���ַ����壬ÿ�����1024���ַ�

	//���ļ�
	if ((fp = fopen(szFileName,  "r")) == NULL)
	{
		return -1;	//�ļ��򿪲��ɹ��Ƿ���-1
	}

	while (!feof(fp))//���û�ж����ļ�ĩβ 
	{
		//���ļ��ж�һ��
		if (fgets(carrBuffer, sizeof(carrBuffer),fp) != NULL)
			//ͳ��ÿ�д���
			nWords += CountWordsInOneLine(carrBuffer);		
	}

	//�ر��ļ�
	fclose(fp);

	return nWords;
}

/*
 *  ��������:
 *		CountWordsInOneLine
 *	���ܣ�ͳ��һ��ŷ�����������дʵĸ���
 *	������const char *szLine һ��ŷ����������
 *	����ֵ��
 *	int ������
 */
 
int CountWordsInOneLine(const char *szLine)
{
	int nWords = 0;
	
    nWords = Lab2_2(szLine);       //������һ������ 

	return nWords;
}

/*
 *	��������CountDifferentCharactersInFile
 *	���ܣ�ͳ�Ƹ����ļ��и����ַ��ĸ���
 *		1. �����ļ���Ϣ�ṹ��ָ��pTextFileInfo���������ļ��������ļ�
 *		2. ˳������ļ��е��ַ���ͳ���и����ַ���
 *		3. �ر��ļ�
 *  ������TEXTFILEINFO *pTextFileInfo
 *	����ֵ��0 �ɹ�  -1 �޷����ļ�
 */

int CountDifferentCharactersInFile(TEXTFILEINFO *pTextFileInfo)
{
	FILE *fp; //�ļ�ָ��
	
	char c;                                                    // �������c 

	//���ļ�
	if ((fp = fopen(pTextFileInfo->szFileName,  "r")) == NULL)
	{
		return -1;	//�ļ��򿪲��ɹ�ʱ����-1
	}
    
	while( (c = fgetc(fp)) != EOF)
	     {
		   if( (c >= 65 && c >= 90 ) || (c >= 97 && c <= 122))  //65��90Ϊ26����дӢ����ĸ��97��122��Ϊ26��СдӢ����ĸ��nAlphabets�� 
		       pTextFileInfo->nAlphabets++;
		    
		    else if(c >= 48 && c <= 57)            //48��57Ϊ0��9ʮ������������ ��nDigits�� 
		       pTextFileInfo->nDigits++;		  
			   
			else if( c == 8 || c == 9 || c == 10 || c == 13)
		       pTextFileInfo->nSpaces++;			         //8��9��10 ��13 �ֱ�ת��Ϊ�˸��Ʊ����кͻس��ַ� ��nSpaces�� 
		       
		    else
		       pTextFileInfo->nOthers++;			         //�����ַ�  ��nOthers�� 
		 }                                                    
	//��ʾ�����Ե��ú���fgetc���ļ��ж�һ���ַ�

    fseek(fp, 0L, SEEK_END );
    pTextFileInfo->nSize = ftell(fp);         //  �鿴�ļ���С 

	//�ر��ļ�
	fclose(fp);

	return 0;
}

/*  ��������ExportFilesInfoToWebPage
 *	���ܣ����ļ�ͳ����Ϣ�����һ��HTML�ļ���
 *  ������
 *		FILESINFO *pMyFiles �����ļ���ͳ����Ϣ�ṹ��ָ��
 *		char *szHtmlFile ��ҳ�ļ���
 *  ����ֵ��0�ɹ���-1���޷������ļ�
 *	
 */ 

int ExportFilesInfoToWebPage(FILESINFO *pMyFiles, char *szHtmlFile)
{
	FILE *fp;  //����һ���ļ�ָ��
	int i; //ѭ������

	fp = fopen(szHtmlFile, "w+"); //���ļ�
	if (NULL == fp) //�жϴ��Ƿ�ɹ�
	{
		printf("�޷������ļ���\n");  //���ɹ�
		return -1;
	}
	//��ʼ���ļ���д����
	//����һЩ��Ҫ��html��ʽ����
	fprintf(fp,"<HTML>\n<HEAD>\n<TITLE>�ļ�ͳ�ƽ��</TITLE>\n" );
	fprintf(fp, "<BODY>\n");

	
	fprintf(fp, "<H4>ʵ��2�ļ���Ϣͳ�ƽ�����£�</H6>\n");	

	//����һ�����
	fprintf(fp, "<table border=""2"">\n");
	//��ͷ
	fprintf(fp, "<td>���</td><td>�ļ���</td><td>���ʸ���</td><td>�ļ���С</td>"
		"<td>���ָ���</td><td>�հ��ַ���</td><td>Ӣ���ַ���</td><td>�����ַ���</td>\n");

	//ѭ������ÿһ��
	for (i = 0; i < pMyFiles->nFileNumber; ++i)
	{
		fprintf(fp, "<tr>"); //����һ��
		
		//��ÿһ���ļ���ͳ����Ϣ����Ŀ���ַ�����д���ļ���
		fprintf(fp, "<td>%4d</td>"
			"<td>%s</td>"
			"<td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td>\n",
			i + 1,
			pMyFiles->pFileInfos[i].szFileName,
			pMyFiles->pFileInfos[i].nWords,
			pMyFiles->pFileInfos[i].nSize,
			pMyFiles->pFileInfos[i].nDigits,
			pMyFiles->pFileInfos[i].nSpaces,
			pMyFiles->pFileInfos[i].nAlphabets,
			pMyFiles->pFileInfos[i].nOthers
			);
		fprintf(fp, "</tr>\n");//����һ��
	}
	//����������
	fprintf(fp, "</table>\n");

	fprintf(fp, "<H4>�����ʵ��˶�ͳ�ƽ���Ƿ���ȷ��</H6><BR>\n");	
	//�����Ҫ��html������־
	fprintf(fp, "</BODY>\n</HEAD>\n</HTML>\n");

	fclose(fp); //�ر��ļ�

	return 0;//���سɹ���־
}
/*
 *	��������TestCountFilesInfo
 *	���ܣ����Ժ���ʵ��1�ļ���Ϣͳ�Ƶ������Ժ���
 *	��������
 *	����ֵ����
 *	ģ����ʷ��
 */

void newWord(FILESINFO *pFilesInfo)         //ͳ���µ��ʺ��� 
{
	FILE *fp; 
	int i,j,k = 0,n,check,count; 
	char buf[1024*100];  
    char temp[1024];
    char c[1000][50];
    
	for(i = 0;i < pFilesInfo->nFileNumber;i++)
	   {
	   	    if ((fp = fopen(pFilesInfo->pFileInfos[i].szFileName,  "r")) == NULL)
	            return -1;
	        else
			{
	        	 while(fgets(temp,1024,fp) != NULL)  
                       strcat(buf,temp);          //�õ�һ�����ַ��� 
	        }
	        fclose(fp);
	   }

	   
	while(i < (strlen(buf)-1))                    //��ȡ�������� 
     {  
       while(!((buf[i] >= 'A' && buf[i] <= 'Z') || (buf[i] >= 'a' && buf[i] <= 'z')))  
           {  
             i++;  
           }  
       j = i;  
       while((buf[j] >= 'A' && buf[j] <= 'Z') || (buf[j] >= 'a' && buf[j] <= 'z'))  
           {  
             j++;  
           }  
 
       char str[50];  
 
       while(i < j)  
           {  
             str[n] = buf[i];  
             i++;  
             n++;  
           }  
       str[n] = '\0';
       strcpy(c[k] , str);                 //���Զ�ά������ʽ�洢���Ե��� 
	   k++;
	   n = 0;
	 }
	
		   
	LINK PHead = (LINK)malloc(sizeof(NODE));    //    ��������һ��ͷ�ڵ��ڴ�ռ�
    LINK p = (LINK)malloc(sizeof(NODE));    //    ����һ���½ڵ�
    PHead->next = p;    //ע�⸳ֵ����                      
    
	for(i = 0;i < k;i++)
	{	
	 	check = 0;
	 	count = 1;
	 	for(j = 0;j < i;j++)
		 {
	 	    if(strcmp(c[i],c[j]) == 0)
			   check++;	 	
		 }                         //check = 0����Ϊ�µ��� 
	 
		if(check == 0)             //�����µ��ʵĲ��� 
		{
		    for(j = 0;j < k;j++)
		    {
		        if(strcmp(c[i],c[j]) == 0)
			      count++;
			}
			
            strcpy(p->word,c[i]);
            p->count = count;
            LINK s = (LINK)malloc(sizeof(NODE));    //    ����һ���½ڵ�						
			p->next = s;			
			p = s;
		}
	}
	p->next = NULL;
	
	PHead = Rank(PHead);      //  �������  
	
	if((fp = fopen("wordsfrequency.txt","w")) == NULL)     //�����ĵ�
	   return -1;
	LINK q = PHead->next;

	while(q)                                          //�����е�����д���ĵ� 
	{				 
		fprintf(fp,"%s                %d\n",q->word,q->count);        
		q = q->next;
	}
	fclose(fp);
}

LINK Rank(LINK p)         //������ 
{
	LINK PHead = p;
	LINK p1,p2;
	int t;
	char c1[50];
     
    for(p1 = p;p1 != NULL;p1 = p1->next)
    {
        for(p2 = p1->next;p2 != NULL;p2 = p2->next)
        {
            if(p1->count < p2->count)//����
            {
            	t = p1->count;
            	p1->count = p2->count;
            	p2->count = t;
            	
            	strcpy(c1,p1->word);
            	strcpy(p1->word,p2->word);
            	strcpy(p2->word,c1);
            }
        }
    }			
	return PHead;
}
	 
void TestCountFilesInfo()
{
	
	//׼���������ļ���ͳ����Ϣ�Ľṹ�����
	FILESINFO MyFilesInfo;
	char szHtmlFile[120] = "FileInfoResult.html";


	//�ļ�������Ϣ׼��
	PrepareBasicInfoOfFiles(&MyFilesInfo);
	
	//����ͳ�ƺ���
	CountFilesInfo(&MyFilesInfo);
	
	
	//��ͳ�ƽ���������Web Page��
	ExportFilesInfoToWebPage(&MyFilesInfo, szHtmlFile);

	//�벹����룬ʵ�ִ򿪴洢ͳ�ƽ������ҳ�ļ�           
	//��ʾ�����ղο������е����ݵ����ⲿ�������ҳ�ļ�
	ShellExecute(NULL, "open", "FileInfoResult.html", NULL, NULL, SW_SHOWNORMAL);
	
	newWord(&MyFilesInfo);       //ͳ���µ��ʲ����� 

	return;
}
