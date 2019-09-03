/*
#功能：判断一个数是否是素数
#输入：一个自然数
#输出：素数输出1，否则输出0
*/
int ss(int x)
{
	int n;
	if (x <= 2)
		return 1;
	for (n = 2; n <= x / 2; n++)
	{
		if (x % n == 0)
			return 0;

	}
	return 1;
}


/*
#功能：主函数，判断从4到100的偶数满足两个素数相加
#输出：无
#输出：无
*/

#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
int main(void)
{
	int n, i, j, p = 0;
	for (n = 4; n <= 100; n += 2)
	{
		for (i = 1; i <= n / 2; i++)
		{
			j = n - i;
			if (ss(i) && ss(j))
				printf("%d = %d + %d\t", n, i, j);
		}
		p += 1;
		if (p % 3 == 0)
			printf("\n");
	}
	return 0;

}