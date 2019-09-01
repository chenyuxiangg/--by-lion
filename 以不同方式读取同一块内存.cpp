#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <limits.h>

int main(int argc,char* argv[]){
	unsigned int x = INT_MAX;
	unsigned char* px = (unsigned char*)&x;
	char tmp[16];
	sprintf(tmp,"%d.%d.%d.%d",px[3],px[2],px[1],px[0]);
	printf("%s\n",tmp);
	printf("size:%d\n",strlen(tmp));
	return 0;
}
