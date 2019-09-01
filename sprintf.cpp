#include <stdio.h>
#include <stdlib.h>
/*
*sprintf在写入时会清空数组里原来的东西 
*/

int main(int argc,char* argv[]){
	char a[10] = "abcdefghi";
	a[9] = '\0';
	printf("before:%s\n",a);
	sprintf(a,"cyx");
	printf("after:%s\n",a);
	return 0;
}
