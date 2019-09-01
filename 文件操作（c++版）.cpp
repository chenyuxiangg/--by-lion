#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin("D:\\c++文件\\dev\\URL.cpp");
	if (!fin.is_open())
	{
		cout << "文件打开失败！" << endl;
		return 0;
	}
	//fin.seekg(ios::end);
	string x;
	while(fin >> x)
	{
		cout << x << " ";
	}
	cout << endl;
	fin.close();
	return 0;
}
