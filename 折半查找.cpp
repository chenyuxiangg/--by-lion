#include<stdio.h>
#define N 5
/*折半查找函数实现*/
int zserch(int a[], int n, int x)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == x)
			return 1;
		else if (a[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

/*主函数*/
int main (int argc,char* argv[])
{
	int a[N];
	int i, x, t;

	printf("请输入大小为%d的单调数组：", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("您输入的数组为：");
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
	printf("\n");

	printf("输入您想要查找的数：");
	scanf_s("%d", &x);
	t = zserch(a, N, x);
	
	if (t == 1)
		printf("查找成功！");
	else
		printf("对不起，查无此数！");

	return 0;
}