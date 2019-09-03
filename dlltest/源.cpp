#include <windows.h>
#include <iostream>

int main(int argc, char ** argv)
{
	using std::cout;
	using std::endl;

	// 随便设置一个不存在的dll名
	HMODULE hMod = LoadLibrary("123.dll");
	
	if (NULL != hMod)
		FreeLibrary(hMod);
	
	cout << "LoadLibrary Test" << endl;
	 return 0;
}