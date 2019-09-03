#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	if (::WritePrivateProfileStringW(L"shi", L"rui", L"hahah", L"D:\\tmp\\test.ini"))
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	system("pause");
	return 0;
}