#include <stdio.h>
#include <stdlib.h>
/*
*sprintf��д��ʱ�����������ԭ���Ķ��� 
*/

int main(int argc,char* argv[]){
	char a[10] = "abcdefghi";
	a[9] = '\0';
	printf("before:%s\n",a);
	sprintf(a,"cyx");
	printf("after:%s\n",a);
	return 0;
}
