#include "Date.h"

int main(int argc, char* argv[])
{
	CDate one(31, CDate::Dec, 1999);
	cout << one;

	cout << "after add day:" << endl;
	one.add_day(1000);
	cout << one;

	system("pause");
	return 0;
}