/*逆置*/
#include<stdio.h>
#define N 6
/*逆置函数*/
void invert(int a[],int n)
{
	int i,t;
	for (i = 0; i < n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - 1 -i];
		a[n - 1 - i] = t;

	}
	printf("\n");
}
/*输入函数*/
void input(int a[],int n)
{
	int i;
	printf("请输入元素：");
	for(i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
}
/*输出函数*/
void output(int a[], int n)
{
	int i;
	printf("元素为：");
	for (i = 0; i < N; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(void)
{
	int a[N];
	printf("输入元素个数：%d\n", N);
	input(a, N);
	output(a, N);
	invert(a, N);
	printf("逆置后的结果是：\n");
	output(a, N);
	return 0;
}