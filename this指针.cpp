#include"iostream"
using namespace std;
class A
{public:
	void output();
};

void A :: output()
{
	cout << "this 指向的地址为：" << this << endl;
}

int main(int argc,char* argv[])
{
	A a;
	a.output();
	cout << "a的地址为： " << &a << endl;

	return 0;
}

//总结：每个成员函数都有一个隐含的this指针，this指针指向调用该成员函数的对象。