#include <stdio.h>
#include <malloc.h>
int main(void)
{
	int * p;
	int len;
	int i;

	//������̬һά����
	printf("��������Ҫ�ĳ��ȣ�\n");
	scanf_s("%d", &len);
	p = (int *)malloc(4 * len);

	//������̬һά����
	for (i = 0; i < len; i++)
	{		scanf_s("%d", &p[i]);
}
	//�����̬һά����
	printf("���������\n");
	for (i = 0; i < len; i++)
		printf("%d\n", p[i]);
	return 0;

}