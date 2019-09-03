#include<stdio.h>
#define N 10
/*输入函数*/
void input(int a[],int n)
{
	int i;
	printf("请输入%d个元素：",N);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);

	}
	printf("\n");
}

/*输出函数*/
void output(int a[],int n)
{
	int i;
	printf("元素为：");
	for (i = 0; i < n; i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}

/*求最大值及其下标*/
void mani(int a[],int n)
{
	int i;
	int max = a[0];
	int maxid;

	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			maxid = i;
		}
	
	}
	printf("此数组的最大元素为%d,其下标为%d.\n", max, maxid + 1);
	printf("\n");
}

int main(void)
{
	int a[N];
	input(a, N);
	output(a, N);
	mani(a, N);

	return 0;
}