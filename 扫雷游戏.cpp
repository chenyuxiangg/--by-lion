#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char * argv[])
{
	int arr[10][10] = { 0 };//数组是用来存储10*10 = 100个格子的,并且定义所有地图都没有雷
	int row, col;//循环变量
	int count = 0;//统计地雷的数量
	srand(time(NULL));//随机数种子

	do 
	{
		row = rand() % 10;
		col = rand() % 10;//这俩行代码随机生成地雷，具有不确定位置以及不确定个数性
		if(arr[row][col] == 0)
		{
			arr[row][col] = -1;//标记为有地雷
			count++;
		}
	} while (count < 10);//从0-9产生10个地雷，有可能产生的少于10个，因为随机数可能重合

	for(row = 0;row < 10; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			if (arr[row][col] != -1)
				printf("o\t");
			else
				printf("x\t");
		}
		printf("\n\n");
	}
	return 0;
}