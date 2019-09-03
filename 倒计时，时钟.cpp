#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*
int main(int argc,char argv[])
{
	int a = 10;//初始化倒计时数
	while(a >= 0)
	{
		system("cls");//作用是啥？？  清除屏幕先前显示的内容  将此语句放在这里最后会显示还剩0秒，以及 新年快乐
		printf("\r离新年还有%d秒\n", a--);
		Sleep(1000);//睡眠或延迟1000毫秒，也就是1秒
		//system("cls");//放在此处最后只显示 新年快乐
	}
	printf("新年快乐！\n");
	return 0;
}
*/

int main(int argc,char * argv[])
{
	int h = 0, m = 0, s = 0;
	while(1)
	{
		printf("\r现在是 2017 年 3 月 18 日 %02d:%02d:%02d", h, m, s++);
		Sleep(1000);
		if(s == 60)
		{
			m++;
			s = 0;
			if (m == 60)
			{
				h++;
				m = 0;
				if (h == 12)
					return 0;
			}
		}
		system("cls");
	}
	return 0;
}