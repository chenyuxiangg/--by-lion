#include"iostream"
using namespace std;
class A
{public:
	void output();
};

void A :: output()
{
	cout << "this ָ��ĵ�ַΪ��" << this << endl;
}

int main(int argc,char* argv[])
{
	A a;
	a.output();
	cout << "a�ĵ�ַΪ�� " << &a << endl;

	return 0;
}

//�ܽ᣺ÿ����Ա��������һ��������thisָ�룬thisָ��ָ����øó�Ա�����Ķ���