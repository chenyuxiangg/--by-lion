#include <iostream>
using namespace std;

int main()
{
	int a[3]{};

	/*for(int i = 0;i < 3;i++)
	{
		cout << a[i] << " ";
	}*/
	cout << "a�ĵ�ַΪ��" << a << endl;
	cout << "&a�ĵ�ַΪ��" << &a << endl;

	a[0] = 1;
	cout << "*a:" << *a << endl;           //1
	cout << "*&a:" << *&a << endl;         //a,&a
	cout << "**&a:" << *(*(&a)) << endl;   //1
	cout << "&a + 1:" << &a + 1 << endl;   //�������������
	cout << "a + 1:" << a + 1 << endl;     //�����int����
	cout << "*&a + 1 :" << *&a + 1 << endl;//�����int����

	system("pause");
	return 0;
}