#include<stdio.h>
int main(void)
{
	char * p[] = { "hello","world","good" };//定义p为一个一维数组，其中容纳3个一维数组，p就像一维整形数组一样是一个指向元素首地址的指针，则p[i]就表示第i个元素
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%s\n", p[i]);
	}
	return 0;
}