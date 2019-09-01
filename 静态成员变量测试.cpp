#include <iostream>

//同一个父类的静态成员变量不能提供不同的多个子类共同访问。 
using namespace std;

class A{
	public:
		static int x;
		A(int b)
		{
			x = b;
		}
}; 

class B:public A{
	public:
		B(int b):A(b){
		}
		void setx(int a)
		{
			x = a;
		}
};

class C:public A{
	public:
		C(int c):A(c){
		}
		int getx(){
			return x;
		}
};
int A::x;

int main(int argc,char* argv[])
{
	B mb(1);
	mb.setx(5);
	C mc(2);
	C c2(9);
	cout << mc.getx() << endl;
	return 0;
}
