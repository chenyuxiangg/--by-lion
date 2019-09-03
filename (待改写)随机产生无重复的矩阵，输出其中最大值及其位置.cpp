#include "stdio.h"
#include "stdlib.h"
#define N 5

int main(int argc, char* argv[])
{
		int a[N][N];
		int b[N * N];
		int k = -1;
		int f, t, i, j, pmax, max;

		printf("正在创生 %d 个在【10 ~ 99】范围内互不相同的随机数组……\n\n", N*N);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
				k++;
				f = 1;

				do
				{
					b[k] = rand() % 100;
				} while (b[k] < 10);

				for (t = 0; t < k; t++)
				{
					if (b[t] == b[k])
					{
						k--;
						j--;
						f = 0;
						break;
					}
				}

				if (f == 1)
				{
					a[i][j] = b[k];
				}
			}

		printf("输出数组a[%d][%d]:\n", N, N);
		for(i = 0;i < N;i++)
		{
			for (j = 0;j < N;j++)
			{
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}

		for(i = 0;i < N;i++)
		{
			max = a[i][0];
			pmax = 0;

			for (j = 0;j < N;j++)
			{
				if (max < a[i][j])
				{
					max = a[i][j];
					pmax = j;
				}
			}
			printf("\n数组中第 %d 行的最大数是： %d,在第 %d 行的 第 %d 个。\n", i + 1, max, i + 1,pmax + 1);
		}

		return 0;
	}

//想办法把他改写成函数模块形式