#include<stdio.h>
int main(void)
{
	char * p[] = { "hello","world","good" };//����pΪһ��һά���飬��������3��һά���飬p����һά��������һ����һ��ָ��Ԫ���׵�ַ��ָ�룬��p[i]�ͱ�ʾ��i��Ԫ��
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%s\n", p[i]);
	}
	return 0;
}