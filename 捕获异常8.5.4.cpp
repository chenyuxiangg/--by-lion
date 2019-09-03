#include <iostream>
using namespace std;

void func()
{
	throw "error";
}

int main(int argc,char* argv[])
{
	try{
		func();
	}
	catch(const char* s)
	{
		cout << "the tip is:" << s << endl;
	}
	return 0;
}
