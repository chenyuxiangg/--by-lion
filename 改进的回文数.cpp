/*������   ���磺121   12321*/
#include "stdio.h"
int main()
{
	unsigned long long int u, m;
	unsigned long long int sum = 0;
	printf("������Ҫ�жϵ���u=\n");
	scanf_s("%lld", &u);
	m = u;
	while (m)
	{
		sum = sum * 10 + m % 10;
		m = m / 10;
	}
	if (sum == u)
		printf("u�ǻ�����");
	else
		printf("u���ǻ�����");
	printf("\n");
	return 0;
}