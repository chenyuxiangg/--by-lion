#include <iostream>
#include "Complex.h"
#include <iomanip>
using namespace std;

int main(int argc,char* argv[])
{
	Complex c1(1.1,5.2);
	Complex c2(2.5,1.0);
	Complex c3(0,0);

	c3 = c1 / c2;
	cout.setf(ios::fixed);//控制小数点后的打印个数
	cout << setprecision(2) << c3 << endl;//控制输出流显示的浮点数的个数

	system("pause");
	return 0;
}