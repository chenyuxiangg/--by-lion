#include <stdio.h>
#define N 15
int main()
{
	int i, j, t;//t�ǽ����ĳ���
	int a[N] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	printf("��������:\n");
	for (i = 0; i < N; i++)//���a[i]
		printf("%4d", a[i]);
		printf("\n");
	for (j = 1 ; j < N  ; j++)//������ѭ������
		for (i = 0; i <= N - 1 - j; i++)//��ѭ�����ӵ�i������ʼ�������������αȽ�
			if (a[i] > a[i + 1])//����i����֮�����ڵ�������С���򽻻�
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;

			}
	printf("�����\n");
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
	printf("\n");
	return 0;

}