/****************************************************\
作者信息：
     作业完成人：郭帅旗		学号：17281178
版权声明：
     版权由北京交通大学计算机与信息技术学院程序设计基础训练课程组所有
模块名称: 
    CodeForLab2.CPP
摘要:
    教学辅助代码，配合实验2
其它说明:

模块历史:
　　林友芳于2011年10月26日创建本模块，email: yflin@bjtu.edu.cn
　　林友芳于2012年10月19日修改本模块，email: yflin@bjtu.edu.cn
　　林友芳于2013年10月11日修改本模块，email: yflin@bjtu.edu.cn
    韩升于2017年2月16日修改本模块，email：shhan@bjtu.edu.cn
	贾彩燕于2018年2月22日修改本模块，email: cyjia@bjtu.edu.cn

**********************************************************/
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

//文本文件统计信息结构体
//提示：通过typedef使TEXTFILEINFO等价于struct TextFileInfo
typedef struct TextFileInfo
{
	char szFileName[120]; //the file name, should be less than 120 characters
	int nWords; //the number of words separated by spaces
	int nSize; //the size of file in bytes
	int nDigits; //the number of digital charactors
	int nSpaces; //the number of spaces including space , ‘\t’, ‘\r’, ‘\n’
	int nAlphabets; //the number of charactors 'A'--'Z', 'a'--'z'
	int nOthers; //the number of other characters
}TEXTFILEINFO;


//所有文件统计信息结构体，该结构中存放各个文本文件的统计信息
//各个文件信息的结构顺序存放
typedef struct FilesInfo
{
	TEXTFILEINFO *pFileInfos; 
	//首个文件的统计信息结构体首地址，其他nFileNumber-1个文件的信息顺序连续存放
	//提示，在使用pFileInfos时可将其看成一个数组来使用,如pFileInfos[i]
	 
	int nFileNumber; //文件数目
	int nNewwords;  //所有文件新词总数
}FILESINFO;

typedef struct node NODE, *LINK;

struct node//定义链接结构
{
	char word[50];	//存贮词
	int count;			//存贮词频
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
 *	功能：申请FILESINFO的所需的存储空间
 *  参数：文件统计信息结构体变量
 *  注意：
 *		1.在调用该函数前，请先给定pMyfiles的文件数目nFileNumber
 *		2.本函数不需要修改，请直接使用
 *  返回值: 0， 成功，-1，参数不合法，-2，存储空间不足
 *	模块历史：
 *	 
 */
 
int AllocateSpaceForTextFilesInfo(FILESINFO *pMyFiles)
{
	//参数合法性判断
	if (NULL == pMyFiles || pMyFiles->nFileNumber <= 0)
		return -1;

	//申请存放pMyFiles->nFileNumber个TEXTFILEINFO类型结构体所需的存储空间
	//并将新申请到的pMyFiles->nFileNumber * sizeof(TEXTFILEINFO)个字节的
	//存储空间首地址存放到pMyFiles->pFileInfos中
	pMyFiles->pFileInfos = (TEXTFILEINFO *)malloc(pMyFiles->nFileNumber * sizeof(TEXTFILEINFO));

	if (NULL == pMyFiles->pFileInfos)
		return -2;
	
	return 0;

}

/*
 *	函数名：PrepareBasicInfoOfFiles
 *	功能：准备各个文件的基本信息
 *      1. 给定实验用文本文件的个数
 *      2. 申请给定文件个数的FILESINFO的所需的存储空间
 *		3. 给定或读入各个文件名
 *  参数：FILESINFO *pFilesInfo，文件统计信息结构体指针
 *	返回值：int
 *	模块历史：
 */	

int PrepareBasicInfoOfFiles(FILESINFO *pFilesInfo)
{
    pFilesInfo->nFileNumber = 5;
    
    AllocateSpaceForTextFilesInfo(pFilesInfo);
    
	strcpy(pFilesInfo->pFileInfos[0].szFileName , "DataMining.txt" );        //  .txt 不能漏 
    strcpy(pFilesInfo->pFileInfos[1].szFileName , "Example.txt" );
    strcpy(pFilesInfo->pFileInfos[2].szFileName , "Programming.txt" );
    strcpy(pFilesInfo->pFileInfos[3].szFileName , "Readability.txt" );
    strcpy(pFilesInfo->pFileInfos[4].szFileName , "reality.txt" );       //给结构体中字符串赋值要用strcpy函数 
    
    int i;
	for (i=0;i<pFilesInfo->nFileNumber;i++)
	{
		pFilesInfo->pFileInfos[i].nAlphabets = 0;
		pFilesInfo->pFileInfos[i].nDigits = 0;
		pFilesInfo->pFileInfos[i].nOthers = 0;
		pFilesInfo->pFileInfos[i].nSize = 0;
		pFilesInfo->pFileInfos[i].nSpaces = 0;
		pFilesInfo->pFileInfos[i].nWords = 0;
	}                                                     //  存入文件名，给结构体各参数赋值为 0 

	return 0;
}

/*
 *	函数名：CountFilesInfo
 *	功能：统计各项信息
 *		1. 统计各个文件中的英文词个数
 *		2. 统计各个文件中各个类别的字符个数
 *	参数：FILESINFO *pFilesInfo，文件统计信息结构体指针
 *	返回值：int  
 *		     0--正常
 *           其他，不正常
 *	 
 */
int CountFilesInfo(FILESINFO *pFilesInfo)
{
	int i;
	for(i = 0;i < pFilesInfo->nFileNumber;i++)
        {
		
		 pFilesInfo->pFileInfos[i].nWords = CountWordsOfEuropeanTxtFile(pFilesInfo->pFileInfos[i].szFileName);                                          
                                                                  //统计各个文件中的英文词个数(nWords), 调用函数即可 
         
         CountDifferentCharactersInFile(&pFilesInfo->pFileInfos[i]);      //注意参数形式 
		}
	return 0;
}

/***********************************************\
函数名称:
	CountWordsOfEuropeanTxtFile
功能描述:
	统计欧洲语言文本文件中词的个数
函数参数:
	char *szFileName 文件名
返回值:
	int 词的个数
模块历史:
  	
\**********************************************/

int CountWordsOfEuropeanTxtFile(char *szFileName)
{
	int nWords = 0;//词计数变量，初始值为0
	FILE *fp; //文件指针
	char carrBuffer[1024];//每行字符缓冲，每行最多1024个字符

	//打开文件
	if ((fp = fopen(szFileName,  "r")) == NULL)
	{
		return -1;	//文件打开不成功是返回-1
	}

	while (!feof(fp))//如果没有读到文件末尾 
	{
		//从文件中读一行
		if (fgets(carrBuffer, sizeof(carrBuffer),fp) != NULL)
			//统计每行词数
			nWords += CountWordsInOneLine(carrBuffer);		
	}

	//关闭文件
	fclose(fp);

	return nWords;
}

/*
 *  函数名称:
 *		CountWordsInOneLine
 *	功能：统计一行欧洲语言正文中词的个数
 *	参数：const char *szLine 一行欧洲语言正文
 *	返回值：
 *	int 单词数
 */
 
int CountWordsInOneLine(const char *szLine)
{
	int nWords = 0;
	
    nWords = Lab2_2(szLine);       //调用上一个函数 

	return nWords;
}

/*
 *	函数名：CountDifferentCharactersInFile
 *	功能：统计给定文件中各类字符的个数
 *		1. 根据文件信息结构体指针pTextFileInfo中所给的文件名，打开文件
 *		2. 顺序读出文件中的字符，统计中各类字符数
 *		3. 关闭文件
 *  参数：TEXTFILEINFO *pTextFileInfo
 *	返回值：0 成功  -1 无法打开文件
 */

int CountDifferentCharactersInFile(TEXTFILEINFO *pTextFileInfo)
{
	FILE *fp; //文件指针
	
	char c;                                                    // 补充变量c 

	//打开文件
	if ((fp = fopen(pTextFileInfo->szFileName,  "r")) == NULL)
	{
		return -1;	//文件打开不成功时返回-1
	}
    
	while( (c = fgetc(fp)) != EOF)
	     {
		   if( (c >= 65 && c >= 90 ) || (c >= 97 && c <= 122))  //65～90为26个大写英文字母，97～122号为26个小写英文字母（nAlphabets） 
		       pTextFileInfo->nAlphabets++;
		    
		    else if(c >= 48 && c <= 57)            //48～57为0到9十个阿拉伯数字 （nDigits） 
		       pTextFileInfo->nDigits++;		  
			   
			else if( c == 8 || c == 9 || c == 10 || c == 13)
		       pTextFileInfo->nSpaces++;			         //8、9、10 和13 分别转换为退格、制表、换行和回车字符 （nSpaces） 
		       
		    else
		       pTextFileInfo->nOthers++;			         //其他字符  （nOthers） 
		 }                                                    
	//提示：可以调用函数fgetc从文件中读一个字符

    fseek(fp, 0L, SEEK_END );
    pTextFileInfo->nSize = ftell(fp);         //  查看文件大小 

	//关闭文件
	fclose(fp);

	return 0;
}

/*  函数名：ExportFilesInfoToWebPage
 *	功能：将文件统计信息输出到一个HTML文件中
 *  参数：
 *		FILESINFO *pMyFiles 所有文件的统计信息结构体指针
 *		char *szHtmlFile 网页文件名
 *  返回值：0成功，-1，无法建立文件
 *	
 */ 

int ExportFilesInfoToWebPage(FILESINFO *pMyFiles, char *szHtmlFile)
{
	FILE *fp;  //声明一个文件指针
	int i; //循环变量

	fp = fopen(szHtmlFile, "w+"); //打开文件
	if (NULL == fp) //判断打开是否成功
	{
		printf("无法创建文件！\n");  //不成功
		return -1;
	}
	//开始往文件中写内容
	//生成一些必要的html格式代码
	fprintf(fp,"<HTML>\n<HEAD>\n<TITLE>文件统计结果</TITLE>\n" );
	fprintf(fp, "<BODY>\n");

	
	fprintf(fp, "<H4>实验2文件信息统计结果如下：</H6>\n");	

	//生成一个表格
	fprintf(fp, "<table border=""2"">\n");
	//表头
	fprintf(fp, "<td>序号</td><td>文件名</td><td>单词个数</td><td>文件大小</td>"
		"<td>数字个数</td><td>空白字符数</td><td>英文字符数</td><td>其他字符数</td>\n");

	//循环生成每一行
	for (i = 0; i < pMyFiles->nFileNumber; ++i)
	{
		fprintf(fp, "<tr>"); //新起一行
		
		//将每一条文件的统计信息生成目标字符串，写入文件中
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
		fprintf(fp, "</tr>\n");//结束一行
	}
	//表格生成完毕
	fprintf(fp, "</table>\n");

	fprintf(fp, "<H4>请根据实验核对统计结果是否正确！</H6><BR>\n");	
	//输出必要的html结束标志
	fprintf(fp, "</BODY>\n</HEAD>\n</HTML>\n");

	fclose(fp); //关闭文件

	return 0;//返回成功标志
}
/*
 *	函数名：TestCountFilesInfo
 *	功能：测试函数实验1文件信息统计的主测试函数
 *	参数：无
 *	返回值：无
 *	模块历史：
 */

void newWord(FILESINFO *pFilesInfo)         //统计新单词函数 
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
                       strcat(buf,temp);          //得到一个长字符串 
	        }
	        fclose(fp);
	   }

	   
	while(i < (strlen(buf)-1))                    //获取单个单词 
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
       strcpy(c[k] , str);                 //先以二维数组形式存储所以单词 
	   k++;
	   n = 0;
	 }
	
		   
	LINK PHead = (LINK)malloc(sizeof(NODE));    //    创建分配一个头节点内存空间
    LINK p = (LINK)malloc(sizeof(NODE));    //    分配一个新节点
    PHead->next = p;    //注意赋值方向                      
    
	for(i = 0;i < k;i++)
	{	
	 	check = 0;
	 	count = 1;
	 	for(j = 0;j < i;j++)
		 {
	 	    if(strcmp(c[i],c[j]) == 0)
			   check++;	 	
		 }                         //check = 0，则为新单词 
	 
		if(check == 0)             //发现新单词的操作 
		{
		    for(j = 0;j < k;j++)
		    {
		        if(strcmp(c[i],c[j]) == 0)
			      count++;
			}
			
            strcpy(p->word,c[i]);
            p->count = count;
            LINK s = (LINK)malloc(sizeof(NODE));    //    分配一个新节点						
			p->next = s;			
			p = s;
		}
	}
	p->next = NULL;
	
	PHead = Rank(PHead);      //  排序操作  
	
	if((fp = fopen("wordsfrequency.txt","w")) == NULL)     //建立文档
	   return -1;
	LINK q = PHead->next;

	while(q)                                          //链表中的数据写入文档 
	{				 
		fprintf(fp,"%s                %d\n",q->word,q->count);        
		q = q->next;
	}
	fclose(fp);
}

LINK Rank(LINK p)         //排序函数 
{
	LINK PHead = p;
	LINK p1,p2;
	int t;
	char c1[50];
     
    for(p1 = p;p1 != NULL;p1 = p1->next)
    {
        for(p2 = p1->next;p2 != NULL;p2 = p2->next)
        {
            if(p1->count < p2->count)//降序
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
	
	//准备好所有文件的统计信息的结构体变量
	FILESINFO MyFilesInfo;
	char szHtmlFile[120] = "FileInfoResult.html";


	//文件基本信息准备
	PrepareBasicInfoOfFiles(&MyFilesInfo);
	
	//调用统计函数
	CountFilesInfo(&MyFilesInfo);
	
	
	//将统计结果输出到下Web Page中
	ExportFilesInfoToWebPage(&MyFilesInfo, szHtmlFile);

	//请补充代码，实现打开存储统计结果的网页文件           
	//提示：参照参考资料中的内容调用外部程序打开网页文件
	ShellExecute(NULL, "open", "FileInfoResult.html", NULL, NULL, SW_SHOWNORMAL);
	
	newWord(&MyFilesInfo);       //统计新单词并排序 

	return;
}
