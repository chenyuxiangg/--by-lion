#include<stdio.h>
#include<stdlib.h>

#define DEBUG

int main(void)
{
	int i;
	int sum = 0;

	#undef DEBUG
	for (i = 1; i <= 10; i++)
	{
        #ifdef DEBUG
		printf("i = %d,sum = %d", i, sum);
		system("pause");
        #endif
		sum = sum + i;
	}
	printf("sum is : %d\n", sum);

	return 0;
}
