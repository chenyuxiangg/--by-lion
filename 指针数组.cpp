/*指针数组里也可以不存放地址*/
#include <stdio.h>
int main(void)
{
	char *p[] = { "hello","world","good!" };//4行
	int i;
	
	for (i = 0; i < 5; i++)
		printf("%s\n",p[i]);//第4行里存放的不是地址，所以不用加*
	return 0;
}
