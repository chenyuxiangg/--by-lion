#include <iostream>
using namespace std;

int main()
{
	int a[3]{};

	/*for(int i = 0;i < 3;i++)
	{
		cout << a[i] << " ";
	}*/
	cout << "a的地址为：" << a << endl;
	cout << "&a的地址为：" << &a << endl;

	a[0] = 1;
	cout << "*a:" << *a << endl;           //1
	cout << "*&a:" << *&a << endl;         //a,&a
	cout << "**&a:" << *(*(&a)) << endl;   //1
	cout << "&a + 1:" << &a + 1 << endl;   //向后移整个数组
	cout << "a + 1:" << a + 1 << endl;     //向后移int步长
	cout << "*&a + 1 :" << *&a + 1 << endl;//向后移int步长

	system("pause");
	return 0;
}