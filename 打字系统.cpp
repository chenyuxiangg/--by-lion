#include<stdio.h>
#include<windows.h>
#include<time.h>
char *arr[] = { "Q W E R T Y U I O P [ ]",
"A S D F G H J K L ; '",
"Z X C V B N M , . /" };//��������ĸ��ʼ��

						//������
void GamePosition(int x, int y)
{
	COORD pos = { x,y };//ֱ�ӳ�ʼ����Ľṹ���ڲ���Ա��Ҳ���Ǵ��������
	HANDLE
		hout = GetStdHandle(STD_OUTPUT_HANDLE);//��Ҫ���õ�����൱���õ�һ�Ű�ֽ
	SetConsoleCursorPosition(hout, pos);//���ÿ���ƽ̨���λ��
}

//��ʼ���������ĸ������
void play()
{
	int x, y, i, j;//x , y����ĸ���µ����꣬i , j��������������
	char ch;//�������������������ĸ
	srand((unsigned)time(NULL));
	i = rand() % 3;//����ɶ�ã�
	j = rand() % (9 - i);//����ɶ��?
	ch = arr[i][j * 4];//��ȡ��ĸ
	x = 18 + i * 2 + j * 4;//�Զ����18��ʼ
	y = 7;//��ӡ��ĸ��6����������Ҫ��7��ʼ

	while (y <= 24)//YС�ڵ���24��һֱ���п�ʼ
	{
		if (y > 7)
		{
			GamePosition(x, y - 1);
			printf(" ");

		}
		GamePosition(x, y);
		printf("%c", ch);
		Sleep(300);
		y++;
	}
}



int main()
{
	system("cls");
	GamePosition(18, 2);//��ӡ�Լ��̶�Ӧ����ĸ
	printf("%s", arr[0]);
	GamePosition(20, 4);
	printf("%s", arr[1]);
	GamePosition(22, 6);
	printf("%s", arr[2]);
	GamePosition(15, 25);
	printf("===========================");
	while (1)
		play();
	return 0;
}
