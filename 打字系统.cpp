#include<stdio.h>
#include<windows.h>
#include<time.h>
char *arr[] = { "Q W E R T Y U I O P [ ]",
"A S D F G H J K L ; '",
"Z X C V B N M , . /" };//键盘上字母初始化

						//定坐标
void GamePosition(int x, int y)
{
	COORD pos = { x,y };//直接初始化点的结构体内部成员，也就是传点的坐标
	HANDLE
		hout = GetStdHandle(STD_OUTPUT_HANDLE);//点要设置到哪里，相当于拿到一张白纸
	SetConsoleCursorPosition(hout, pos);//设置控制平台光标位置
}

//开始随机生成字母并掉落
void play()
{
	int x, y, i, j;//x , y是字母掉下的坐标，i , j是随机数组的行列
	char ch;//用来接受随机产生的字母
	srand((unsigned)time(NULL));
	i = rand() % 3;//这有啥用？
	j = rand() % (9 - i);//这有啥用?
	ch = arr[i][j * 4];//获取字母
	x = 18 + i * 2 + j * 4;//自定义从18开始
	y = 7;//打印字母到6，所以这里要从7开始

	while (y <= 24)//Y小于等于24是一直运行开始
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
	GamePosition(18, 2);//打印吃键盘对应的字母
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
