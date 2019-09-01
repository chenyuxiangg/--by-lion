#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
int main(int argc,char* argv[])
{
	srand(time(0));
	FILE* fin = fopen("D:\\c++文件\\dev\\intfile.dat","w+");
	for(int i = 0;i < 1000;++i)
	{
		fprintf(fin,"%5d",rand()%1000);
	}
	fclose(fin);
	
	int x;
	FILE* fout = fopen("D:\\c++文件\\dev\\intfile.dat","r+");
	for(int i = 0;i < 1000;++i)
	{
		fscanf(fout,"%5d",&x);
		printf("%5d",x);
	}
	return 0;
 } 
