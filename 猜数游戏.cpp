/*
*项目名称：猜数游戏
*作   者：Mr.c
*开发日期：2017/2/12
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//函数声明
int init();
int play(int);
void getscore(int);

//初始化
/*
功能：随机产生一个1~100的数
输入：无
输出：随机整数1~100
*/
int init()
{
	srand((unsigned)time(NULL));
	return (rand() % 100);
}

//玩家猜测
/*
功能：玩家多次猜测数字，直到猜对为止
输入：随机数1~100
输出：猜数总次数
*/
int play(int cnum)
{
	int gnum;
	int gnumt = 1;

	printf("请输入您猜的数：\n");
	scanf_s("%d", &gnum);

	do 
	{
		gnumt += 1;

		if(gnum < cnum)
		{
			printf("偏小了呦~请重新输入：\n");
		}
		else
		{
			printf("有点偏大啊！请重新输入：\n");
		}

		scanf_s("%d", &gnum);
		//printf("%d", cnum);
		
	} while (gnum != cnum);

	return gnumt;
}



int main(void)
{
	int cnum = init();
	//printf("%d", cnum);
	int gnumt = play(cnum);
	getscore(gnumt);

	return 0;
}

//测评
/*
功能：系统对用户猜数结果总结
输入：用户猜数总次数
输出：是否继续，Y/y继续，N/n退出
*/
void getscore(int gnumt)
{
	if (gnumt <= 2)
		printf("神啊！！你居然%d次就猜中了！！奖励一朵小红花~\n", gnumt);
	else if (gnumt <= 5)
		printf("不错呦，用了%d次就猜中~继续加油，相信你能更棒！\n", gnumt);
	else
		printf("小伙子，用了%d次才猜中，没用心呦\n", gnumt);
}


