#include<stdio.h>
/*类似于结构体的定义   结构体定义：struct student{  };   */
enum Weakend //定义了一个数据类型enum Weakend,并没有定义变量
{
	Monday, Tuthday, Wednsday, Thursday, Friday, Saturday, Sunday
};//从Monday 开始到Sunday,依次自动赋值为0-6

int main(void)
{
	enum Weakend i;

	i = Monday;

	printf("%d\n", i);

	return 0;


}