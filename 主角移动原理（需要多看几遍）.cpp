#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int x = 5, y = 5;
int i = 1;//����iֵΪ1ʱ�����ƣ�Ϊ0ʱ������

void GamePosition(HANDLE hout,int x,int y)
{
	//1.��ȡ����
	COORD pos;//��Ľṹ�����
	pos.X = x;
	pos.Y = y;//X,Y�ǵ�Ľṹ�������ڲ���Ա

	//2.���õ���Ӧ��λ��
	SetConsoleCursorPosition(hout, pos);//���ÿ���ƽ̨���λ��

}
int main(int argc, char argv[])
{
	//3.��ȡһ�Ű�ֽ
	HANDLE
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//4.�������꺯��������ͼ��
	GamePosition(hout, x, y), printf("*");
	while (1)
	{
		if (_kbhit())//5.������¼���

			switch (_getch())//�����㰴�µ���ĸ���ж��Ƿ���w,s,a,d
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
		/*if (x >= 0 && i == 1)//�����ߵ�״̬
		{
			GamePosition(hout, x, y);
			printf(" ");
			GamePosition(hout, ++x, y);
			printf("*");
			Sleep(1000);
			if (x == 10)
				i = 0;//�����ߵ�״̬
		}
		else if(x <= 10&&i == 0)
		{
			GamePosition(hout, x, y);
			printf(" ");
			GamePosition(hout, --x, y);
			printf("*");
			Sleep(1000);
			if (x == 0)
				i = 1;//�����ߵ�״̬
		}*/
	}
	return 0;
}