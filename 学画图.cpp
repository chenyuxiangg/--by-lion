#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int i = 10, j = 10;//��ʼ������

void GamePosition(int x, int y)//������
{
	COORD pos = { x,y };//��Ľṹ�壬ֱ�ӳ�ʼ��
	HANDLE
		hout = GetStdHandle(STD_OUTPUT_HANDLE);//����һ�Ű�ֽ
	SetConsoleCursorPosition(hout, pos);//���ÿ���ƽ̨����λ��  ���� = ��ֽ = ���������ڰ�ֽ��

}

int main(int argc,char * argv[])
{
	GamePosition(i, j);//�������꺯��
	printf("*");
	while(1)
	{
		if(_kbhit())//�Ƿ��¼���
			switch(_getch())//���ܰ���ȥ����ĸ��ʵ�����������ƶ�
			{
			case 'w':
				if(i > 0)
				{
					GamePosition(i, j), printf(" ");//��������ͼ�����
					GamePosition(i, --j), printf("*");//���һ���ڻ�ͼ��

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