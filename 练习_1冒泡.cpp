#include <stdio.h>
int main(void)
{
	int i, j, t, k, a[5];
	printf("������5�����֣�\n");
	for (k = 0; k < 5; k++)
		scanf_s("%d", &a[k]);
	printf("����ǰ��\n");
	for (k = 0; k < 5; k++)
		printf("%4d", a[k]);
	printf("\n");
	for(i = 0; i < 4; i++)
		for (j = 0; j < 5 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}

		}
	printf("�����\n");
	for (i = 0; i < 5; i++)
		printf("%4d", a[i]);
	printf("\n");
	return 0;
}