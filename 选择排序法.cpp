#include <stdio.h>
#define N 10
int main()
{
	int array[N], i, j, k, t;
	printf("Input %d number ��\n", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &array[i]);
	}
	printf("\n");
	for (i = 0; i <= N - 1; i++)//��ѭ������N-1��
	{
		k = i;//��ÿһ����ѭ�������󶼽�k��i��ֵ���Ա㽫��С������������
		for (j = i + 1; j < N; j++)//��ѭ��
			if (array[j] < array[k])  k = j;//���±���ȣ�ʵ������array[k] = array[j],����array[j]ֵ����
		if (i != k)//����С���û���iλ��
		{
			t = array[k];
			array[k] = array[i];
			array[i] = t;
		}
	}
	printf("The sorted numbers��\n");
	for (i = 0; i < N; i++)//�����д�һ��������ֻ�����һ��ֵ
		printf("%5d", array[i]);

	
	return 0;
}