#include "MyString.h"

int main(int argc, char* argv[])
{
	mystring s1("haha");
	mystring s2("cc");
	mystring s3;
	cout << s1.getn() << endl;
	s1 = s1;
	cout << s1.getn();

	cout << endl;
	system("pause");
	return 0;
}