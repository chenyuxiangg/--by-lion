#include<stdio.h>
void test()
{
	static int x = 10;//x 为静态局部变量，值初始化一次，也就是说第二次调用test函数时，x 的值在第一次的基础上继续处理,且只能在test中调用
	int y = 10;//y为非静态变量，其初始化为每次调用test函数时

	printf("x = %d,y = %d\n", x, y);

	x = x + 10;
	y = y + 10;
}

int main(void)
{
	test();
	test();
	test();
	return 0;
}

//---------------------------------------------------------
/*输出结果：
x = 10,y = 10
x = 20,y = 10
x = 30,y = 10
*/