/*
#项目名称：模拟银行ATM自动存取款机
#作   者：Mr.c
#日   期：2017/02/16
*/

int menu();//菜单列表及功能选择
double cmoney();//输出当前余额
void getmoney(int);//存钱
void withdraw(int);//取钱

#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

double money = 0.0;

int main(void)
{
	char ch = menu();
	printf("====================================\n");
	int temp;

	while (ch != 0)
	{
		switch (ch)
		{
		case 1:
			printf("您当前的余额为 %.2lf\n", cmoney());
			break;
		case 2:
			printf("请输入您的存款额:\n");
			scanf_s("%ld", &temp);
			getmoney(temp);
			printf("您当前的余额为 %.2lf\n", cmoney());
			break;
		case 3:
			printf("请输入您的取款金额:\n");
			scanf_s("%ld", &temp);
			withdraw(temp);
			printf("您当前的余额为 %.2lf\n", cmoney());
		}
		printf("\n\n");
		_getch();//暂停，让用户看清，按任意键继续
		ch = menu();
	}
	printf("===============================================\n");
	printf("谢谢使用中国银行，我们将竭诚为您服务！\n");
	return 0;
}

/*
#功能：显示菜单列表及功能选择
#输入：无
#输出：代表选择的整数
*/
int menu()
{
	int i;
	printf("还迎使用中国银行，我们将竭诚为您服务！\n");
	printf("=========================================\n");
	printf("请选择您所需的服务：\n");
	printf("\n");
	printf("1.查询余额\t 2.存款\n");
	printf("3.取款\t     0.退出\n");
	scanf_s("%d",&i);
	return i;
}

/*
#功能：存入金额
#输入：金额
#输出：无
*/
void getmoney(int x)
{
	money = money + x;
}

/*
#功能：取出金额
#输入：金额
#输出：无
*/
void withdraw(int x)
{
	if (x > money)
	{
		printf("您的余额不足。\n");
	}
	else
		money = money - x;
}

/*
#功能：当前余额
#输入：无
#输出：当前余额
*/
double cmoney()
{
	return money;
}
