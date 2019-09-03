#include <stdio.h>
#define N 15
int main()
{
	int i, j, t;//t是交换的场所
	int a[N] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	printf("待排数据:\n");
	for (i = 0; i < N; i++)//输出a[i]
		printf("%4d", a[i]);
		printf("\n");
	for (j = 1 ; j < N  ; j++)//控制外循环次数
		for (i = 0; i <= N - 1 - j; i++)//内循环，从第i个数开始与它相邻数依次比较
			if (a[i] > a[i + 1])//若第i个数之后相邻的数比它小，则交换
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;

			}
	printf("排序后：\n");
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
	printf("\n");
	return 0;

}