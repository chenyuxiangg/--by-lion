#include <stdio.h>
int main(void)
{
	int n, f1, f2, f3, i;
	f1 = 1;
	f2 = 2;
	printf("��������Ҫ������г��ȣ�\n");
	scanf_s("%d", &n);
	while (n <= 0)
	{
		printf("�������ֵ��Ч�����������0������\n");
		scanf_s("%d", &n);
		if (n > 0) break;
	}
	 if (n == 1)
		f3 = f1;
	else if (n == 2)
		f3 = f2;
	else {
		for (i = 0; i < (n - 2); i++)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
	}
	printf("fn = %d", f3);
	return 0;
}