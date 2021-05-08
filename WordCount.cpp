#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) { //读取参数 

	if( argc == 3 ) {
		char data;
		FILE *fp = fopen(argv[2],"r"); //以写的方式读取文件 

		if(!fp) {
			printf("错误：文件读取失败\n");
			return -1;
		}

		if(!strcmp(argv[1],"-c") ) //统计字符数 
		{ 
			char temp;
			int num = 0;
			temp = fgetc(fp);
			while( temp != EOF ) //检查是否到文件的结束位置 
			{
				temp = fgetc(fp);
				if(temp!=' ' && temp!='\n' && temp!='\t')
					num++;
			}
			printf("该文本文件的字符数为：%d\n",num);

		} 
		else if( !strcmp(argv[1],"-w") ) //统计单词数 
		{ 
			int count = 0;
			char a = fgetc(fp);
			while( a != EOF) {
				if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') ) 
				{
					while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
						a =fgetc(fp);
					count++;
					a =fgetc(fp);

				} 
				else
					a =fgetc(fp);
			}
			printf("该文本文件的单词数为：%d\n",count);

		}
		else {
			printf("错误：参数超出范围！\n");
			printf("允许参数：-c，-w\n");
		}
		
		int n=fclose(fp); //关闭文件 
	} 
	else 
	{
		printf("错误：运行参数必须要3个\n");
		printf("用法应该是：wc.exe [parameter] [file_name]\n");
	}
	system("pause");
	
	return 0;
}
