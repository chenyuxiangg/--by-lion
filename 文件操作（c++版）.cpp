#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin("D:\\c++�ļ�\\dev\\URL.cpp");
	if (!fin.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
