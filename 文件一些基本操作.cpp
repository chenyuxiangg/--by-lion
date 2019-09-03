#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	ofstream outfile;
	cout << "请输入文件名：";
	char a[10];
	cin >> a;
	getchar();
	outfile.open(a, ios::out);//文件不存在，自动创建一个文件
	cout << "输入数据：";
	char b[50];
	cin.getline(b, 50);
	outfile << b;
	outfile << '\n';//存入一行后换行
	cout << "再次输入：";
	char r[5];
	cin.getline(r, 5);//按行输入一组数据，空格也将被提取，且占一个是数组位
	outfile << r;
	outfile.close();
	cout << "从文件中读出：" << endl;
	//cin.ignore();
	ifstream infile;
	cout << "请输入文件名：";
	char t[20];
	cin >> t;
	infile.open(t, ios::in);
	string c;

	//判断文件是否到达末尾，可用此语句来将文件中的所有内容提取到足够大的数组中
	/*while (!infile.eof())
	{
		infile >> c;
		cout << c;
	}*/

	infile >> c;
	cout << c;
	cout << endl;
	istringstream in(c);//将字符串转换成整型，若输入为55ddd55，则会转换成55，后边都会截断
	int h;
	in >> h;
	cout << h << endl;
	

	infile.close();
	system("pause");
	return 0;
}