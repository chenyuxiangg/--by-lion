#include <iostream>
#include "Stack.h"
#include <stdlib.h>
#include <ctime>
#define N 4
using namespace std;

int x = 0;//坐标x
int y = 0;//坐标y

void moveR(Coordinate coor)
{
	x = coor.getX() + 1;
	y = coor.getY();

}

void moveL(Coordinate coor)
{
	x = coor.getX() - 1;
	y = coor.getY();
}

void moveD(Coordinate coor)
{
	x = coor.getX();
	y = coor.getY() + 1;
}

void moveU(Coordinate coor)
{
	x = coor.getX();
	y = coor.getY() - 1;
}

int main(int argc,char*argv[])
{
	Stack stack;
	//Coordinate coor1(1, 2,NO);
	//stack.Push(coor1);
	//Coordinate coor1(1, 3,NO);//产生多重定义错误

	int maze[N][N];
	int row;//行
	int col;//列
	for (row = 0; row < N ; row++)
		for (col = 0; col < N; col++)
			maze[row][col] = 1;//迷宫全部初始化为障碍

	maze[0][0] = 0;//入口
	maze[N-1][N-1] = 0;//出口

	//随机生成迷宫
	srand(int(time(NULL)));
	int count = (N*N) / 2 + (N*N) / 10;
	for (int k = 0; k < count; k++)//
	{
		int rowr = rand() % N;//行
		int colr = rand() % N;//列
		if(maze[rowr][colr] != 0)
		{
			maze[rowr][colr] = 0;
		}
		else
		{
			k--;
		}

	}
	cout << "迷宫" << endl;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		for (int j = 0; j < N; j++)
		{
			if (num % N == 0)
				cout << endl;
			cout << maze[i][j] << " ";
			num++;
		}
	}
	cout << endl;
	cout << endl;

	//实现迷宫走法
	stack.Push(Coordinate(x, y));//第一个元素
	while(((stack.getTop().getY() != N-1) || (stack.getTop().getX() != N-1)) && !stack.Isempty())
	{
		direction t = (direction)stack.getTop().getdirec();
		switch(t)
		{
		case DOWN:
			maze[stack.getTop().getY()][stack.getTop().getX()] = 1;
			moveD(stack.getTop());
			if (x < 0 || x > N - 1 || y < 0 || y > N - 1 || maze[y][x] == 1)
			{
				stack.getTop().setdir(LEFT);//getTop()应该为返回引用，否则不能设置
			}
			else
			{
				stack.Push(Coordinate(x,y));
			}
			break;
		case LEFT:
			maze[stack.getTop().getY()][stack.getTop().getX()] = 1;
			moveL(stack.getTop());
			if (x < 0 || x > N - 1 || y < 0 || y > N - 1 || maze[y][x] == 1)
			{
				stack.getTop().setdir(RIGHT);
			}
			else
			{
				stack.Push(Coordinate(x,y));
			}
			break;
		case RIGHT:
			maze[stack.getTop().getY()][stack.getTop().getX()] = 1;
			moveR(stack.getTop());
			if (x < 0 || x > N - 1 || y < 0 || y > N - 1 || maze[y][x] == 1)
			{
				stack.getTop().setdir(NO);
			}
			else
			{
				stack.Push(Coordinate(x,y));
			}
			break;
		default:
			Coordinate elem;
			stack.Pop(elem);
			break;
		}
	}

	cout << "解为：" << endl;
	if (stack.Isempty())
	{
		cout << "迷宫无解,本少无能为力呀~" << endl;
		system("pause");
		return 0;
	}
	stack.traverse();
	system("pause");
	return 0;
}