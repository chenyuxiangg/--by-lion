#include <stdio.h>
#include <windows.h>
int main()
{
	int pass, i = 0, p = 5;
	printf("请注意周边环境安全！！\n");
		while (1)
		{
			scanf_s("%d", &pass);
			if (pass != 123456)
				printf("输入密码错误第%d次\n",++i);
			if (i >= 3)
			{
				printf("对不起，您的卡被锁，请联系当地银行~\n");
				while (i == 3 && p >= 0)
				{
					printf("\r%d秒后退出系统。。。。\n",p--);
					Sleep(1000);
				}
			
				return -1;
			}
			if (pass == 123456)
			{
				printf("密码正确，正在进入系统。。\n");
				while (p >= 0)
				{
					printf("\r%d秒后进入系统。。\n", p--);
					Sleep(1000);
				}
				return 0;
			}
		

		}
}
