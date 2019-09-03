#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int x = 5, y = 5;
int i = 1;//定义i值为1时向右移，为0时向左移

void GamePosition(HANDLE hout,int x,int y)
{
	//1.获取坐标
	COORD pos;//点的结构体变量
	pos.X = x;
	pos.Y = y;//X,Y是点的结构体坐标内部成员

	//2.设置到对应的位置
	SetConsoleCursorPosition(hout, pos);//设置控制平台光标位置

}
int main(int argc, char argv[])
{
	//3.获取一张白纸
	HANDLE
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//4.调用坐标函数，画出图形
	GamePosition(hout, x, y), printf("*");
	while (1)
	{
		if (_kbhit())//5.如果按下键盘

			switch (_getch())//接收你按下的字母，判断是否是w,s,a,d
			{
			case 'w':

			case 'W':

				if (y > 3)
				{
					GamePosition(hout, x, y);
					printf(" ");
					GamePosition(hout, x, --y);
					printf("*");
				}
				break;
			case 's':
			case 'S':
				if (y < 20)
				{
					GamePosition(hout, x, y);
					printf(" ");
					GamePosition(hout, x, ++y);
					printf("*");
				}
				break;

				case 'a':
				case'A':
					if(x > 3)
					{
						GamePosition(hout, x, y);
						printf(" ");
						GamePosition(hout, --x, y);
						printf("*");
					}
					break;
				case 'd':
				case 'D':
					if(x < 50)
					{
						GamePosition(hout, x, y);
						printf(" ");
						GamePosition(hout, ++x, y);
						printf("*");
					}
					break;
			}
		/*if (x >= 0 && i == 1)//向右走的状态
		{
			GamePosition(hout, x, y);
			printf(" ");
			GamePosition(hout, ++x, y);
			printf("*");
			Sleep(1000);
			if (x == 10)
				i = 0;//向左走的状态
		}
		else if(x <= 10&&i == 0)
		{
			GamePosition(hout, x, y);
			printf(" ");
			GamePosition(hout, --x, y);
			printf("*");
			Sleep(1000);
			if (x == 0)
				i = 1;//向右走的状态
		}*/
	}
	return 0;
}