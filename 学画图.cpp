#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int i = 10, j = 10;//初始化坐标

void GamePosition(int x, int y)//定坐标
{
	COORD pos = { x,y };//点的结构体，直接初始化
	HANDLE
		hout = GetStdHandle(STD_OUTPUT_HANDLE);//设置一张白纸
	SetConsoleCursorPosition(hout, pos);//设置控制平台坐标位置  坐标 = 白纸 = 坐标设置在白纸上

}

int main(int argc,char * argv[])
{
	GamePosition(i, j);//调用坐标函数
	printf("*");
	while(1)
	{
		if(_kbhit())//是否按下键盘
			switch(_getch())//接受按下去的字母，实现上下左右移动
			{
			case 'w':
				if(i > 0)
				{
					GamePosition(i, j), printf(" ");//把坐标点的图形清空
					GamePosition(i, --j), printf("*");//轴减一，在画图形

				}
				break;
			case 's':
				if(j < 20)
				{
					GamePosition(i, j), printf(" ");
					GamePosition(i, ++j), printf("*");

				}
				break;
			case 'a':
				if(i > 0)
				{
					GamePosition(i, j), printf(" ");
					GamePosition(--i, j), printf("*");
				}
				break;
			case 'd':
				if(i < 20)
				{
					GamePosition(i, j), printf(" ");
					GamePosition(++i, j), printf("*");

				}
				break;
			}
	}
	return 0;
}