#include <stdio.h>
int f(int **q)
{
	int i = 5;
	*q = &i;

}
int main(void)
{
	int * p;
	f(&p);
	printf("%d\n", *p);//error,��Ϊi �Ǿ�̬��������f����ִ�����ͱ��ͷţ��ʲ������
	return 0;
}