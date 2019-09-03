#include <iostream>
using namespace std;
int i = 0;

void fun ()
{
	static int a = 1; //a为静态变量，拥有静态生存期，第一次调用fun时被初始化，以后每次调用fun时均保留上一步结果；
	static int b = 2; //b同a
	int c = 3;

	a += 1;
	c -= 2;  //c为fun作用域中的局部变量，拥有动态生存期，每次调用fun时总会被初始化为 3；
	cout << "fun()中结果： " << " a = " << a << endl;
	cout << "             " << " b = " << b << endl;
	cout << "             " << " c = " << c << endl;
	b = a;
}

int main(int argc,char * argv[])
{
	int i = 5;

	cout << "main()中结果： " << " i = " << i << endl;  //结果为5，因为内层屏蔽了外层；
	fun();
	fun();
	fun();

	return 0;
}