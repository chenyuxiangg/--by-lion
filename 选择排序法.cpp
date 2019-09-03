#include <stdio.h>
#define N 10
int main()
{
	int array[N], i, j, k, t;
	printf("Input %d number ：\n", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &array[i]);
	}
	printf("\n");
	for (i = 0; i <= N - 1; i++)//外循环，找N-1遍
	{
		k = i;//在每一趟内循环结束后都将k付i的值，以便将较小的数传送上来
		for (j = i + 1; j < N; j++)//内循环
			if (array[j] < array[k])  k = j;//令下标相等，实际上是array[k] = array[j],但是array[j]值不变
		if (i != k)//将较小数置换到i位置
		{
			t = array[k];
			array[k] = array[i];
			array[i] = t;
		}
	}
	printf("The sorted numbers：\n");
	for (i = 0; i < N; i++)//必须有此一步，否则只能输出一个值
		printf("%5d", array[i]);

	
	return 0;
}