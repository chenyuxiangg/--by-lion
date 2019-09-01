/*
*单例模式需要私有的构造函数，私有的复制构造函数以及私有的等号赋值函数。
*单例模式说白了就是申请了一块内存，可以用多个指针去指向它。
*静态成员变量可以在非函数或非类内定义。就算是指针也行。 
*/

#include <iostream>
using namespace std;

class A{
	private:
		A(){
			i = 0;
			cout << "单例模式" << endl;
		}
		
		A(const A&){
		}
		
		A& operator=(const A&)
		{
		}
		
		
	public:
		static A* GetA()
		{
			return a;
		}
		
		int Geti()
		{
			return i;
		}
		
		void Seti(int k)
		{
			i = k;
		}
		~A()
		{
			delete a;
			a = NULL;
		}
		
	private:
		static A* a;
		int i;
}; 

A* A::a = new A();

//接下来尝试单例模式是否可以被继承
//单例模式不可继承，因为构造函数私有 

/*
class B : public A{
	public:
		B(){
			cout << "单例模式可以继承" << endl;
		}
};
*/

int main(int argc,char* argv[])
{
	A* b = A::GetA();
	b->Seti(5);
	A* c = A::GetA();
	cout << c->Geti() << endl;
	return 0;
}
