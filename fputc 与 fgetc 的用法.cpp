#include<stdio.h>
#include<stdlib.h>
FILE * inf,*outf;
char ch,sh;

int main(int argc, char argv[])
{
	if ((inf = fopen("file1", "w+")) == NULL)
	{
		printf("error!\n");
		exit(-1);
	}
	printf("请输入内容：\n");
	while ((ch = getchar()) != '#')
	{
		fputc(ch, inf);
	}
	fclose(inf);

	if((outf = fopen("file1","r")) == NULL)
	{
		printf("error!");
		exit(-1);
	}
	printf("输出内容：\n");
	sh = fgetc(outf);
	while(sh != EOF)
	{
		putchar(sh);
		sh = fgetc(outf);
	}
	fclose(outf);

	return 0;
}