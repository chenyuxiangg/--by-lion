/*ָ��������Ҳ���Բ���ŵ�ַ*/
#include <stdio.h>
int main(void)
{
	char *p[] = { "hello","world","good!" };//4��
	int i;
	
	for (i = 0; i < 5; i++)
		printf("%s\n",p[i]);//��4�����ŵĲ��ǵ�ַ�����Բ��ü�*
	return 0;
}
