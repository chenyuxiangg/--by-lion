/*回文数   例如：121   12321*/
#include "stdio.h"
int main()
{
	int u, m;
	int sum = 0;
	printf("请输入要判断的数u=");
	scanf_s("%d", &u);
	m = u;
	while (m)
	{
		sum = sum * 10 + m % 10;
		m = m / 10;
	}
	if (sum == u)
		printf("u是回文数");
	else
		printf("u不是回文数");
	printf("\n");
	return 0;
}