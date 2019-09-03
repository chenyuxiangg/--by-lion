#include<stdio.h>
#define N 10
/*查找函数的实现*/
int serch(int a[],int n,int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
			break;
	}
	if (i < n)
	{
		return i + 1;
	}
	return -1;
}

/*主程序*/
int main(int argc, char * argv[])
{
	int a[N];
	int i, x, t, p;
	char ch;

	printf("请输入%d个数，按回车结束：", N);
	for(i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("你输入的数组为：");
	for (i = 0; i < N; i++)
		printf("%d", a[i]);
	printf("\n");

	for(p = 0;; p++)
	{
		printf("亲~输入您要查找的数字，我们将会输出其序号：");
		scanf_s("%d", &x);
		t = serch(a, N, x);
		if (t != -1)
			printf("查找成功，%d的序号为 %d\n", x, t);
		else
			printf("对不起，查无此数！\n");

		printf("您是否继续查找？（y/n）\n");
		scanf_s(" %c", &ch);//输入单个字符时，需要“ %c",%号前必须有空格
		if (ch == 'n')
			break;
	}

	return 0;
}