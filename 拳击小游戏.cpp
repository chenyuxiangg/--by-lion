#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char argv[])
{//拳击游戏规则：四合制（我方先出拳，电脑后出拳）
 //出拳力量：1~10
 //生命值：30

	int mylife = 30;//我方生命值
	int enemy = 30;//电脑方生命值
	int power;//力量

	srand((unsigned)time(NULL));//初始化随机数种子

	while(1)
	{
		system("pause");//我方出拳
		power = rand() % 10 + 1;//得到的随机值从1到10之间的数

		//打击电脑，无闪避情况
		enemy -= power;
		//判断电脑方已经没有生命
		if(enemy <= 0)
		{//电脑放已经没有生命
			printf("\n厉害，你成功KO了电脑\n");
			break;
		}
		printf("\n我方打了电脑一拳，力量为%d,电脑方掉生命为%d，电脑方还剩余生命%d\n",power,power,enemy);

		//电脑方出拳
		power = rand() % 10 + 1;
		mylife -= power;

		if(mylife <= 0)
		{
			printf("\n很遗憾，你被电脑over了\n");
			break;
		}
		printf("\n电脑打了你一拳，力量为%d，你掉了%d的生命，你的生命还剩余%d\n", power, power, mylife);


	}
	return 0;
}