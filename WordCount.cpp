#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) { //��ȡ���� 

	if( argc == 3 ) {
		char data;
		FILE *fp = fopen(argv[2],"r"); //��д�ķ�ʽ��ȡ�ļ� 

		if(!fp) {
			printf("�����ļ���ȡʧ��\n");
			return -1;
		}

		if(!strcmp(argv[1],"-c") ) //ͳ���ַ��� 
		{ 
			char temp;
			int num = 0;
			temp = fgetc(fp);
			while( temp != EOF ) //����Ƿ��ļ��Ľ���λ�� 
			{
				temp = fgetc(fp);
				if(temp!=' ' && temp!='\n' && temp!='\t')
					num++;
			}
			printf("���ı��ļ����ַ���Ϊ��%d\n",num);

		} 
		else if( !strcmp(argv[1],"-w") ) //ͳ�Ƶ����� 
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
			printf("���ı��ļ��ĵ�����Ϊ��%d\n",count);

		}
		else {
			printf("���󣺲���������Χ��\n");
			printf("���������-c��-w\n");
		}
		
		int n=fclose(fp); //�ر��ļ� 
	} 
	else 
	{
		printf("�������в�������Ҫ3��\n");
		printf("�÷�Ӧ���ǣ�wc.exe [parameter] [file_name]\n");
	}
	system("pause");
	
	return 0;
}
