#include <typeinfo>
#include <iostream>
using namespace std;

class A{
	
};

class B: public A{
	
};

int main(int argc,char* argv[])
{
	A* ap = new B();
	cout << typeid(ap).name() << endl;
	
	delete ap;
	ap = NULL;
	return 0;
}
