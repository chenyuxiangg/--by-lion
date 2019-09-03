/*
写一个函数atoi(const char*),他以一个包含数字的C风格字符串为参数
，返回与之对应的int值，例如：atoi("123")应是123.修改atoi(),以处
理简单的十进制数之外，还能处理c++的八进制和十六进制记法形
式。修改atoi(),以处理c++的常量字符记法。
*/
#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

//进制的枚举定义
enum Scale {
	DEC = 10, HEX = 16, OCT = 8
};

//错误处理
void iserror(const char* pch);
void iserror(const char ch);
void iserror();


//获取字符串
void str_Create(char* pch);


//处理字符串
int my_atoi(const char* pch);

//显示加工后的字符串
void show_ret(int num);

int main(int argc, char* argv[])
{
	char* charr = new char[50];
	str_Create(charr);
	int Num;
	if ((Num = my_atoi(charr)) != -1)
	{
		show_ret(Num);
	}

	delete[] charr;
	system("pause");
	return 0;
}

void iserror(const char* pch)
{
	for (pch; *pch != '\0'; pch++)
		cerr << *pch;
	cerr << " is error input!" << endl;
}

void iserror(const char ch)
{
	cerr << ch << "is error input!" << endl;
}

void iserror()
{
	cerr << "please input rightly!  "
		<< "for example: \"DEC or Dec or dec\"" << endl;
}

void str_Create(char* pch)
{
	bool flag = true;
	int ch_count = 0;
	char ch;

	cout << "please input:";
	cin >> ch;
	while (true)
	{
		if (isalnum(ch) || ch == '\n'|| ch == 32)
		{
			if (ch == '\n')
				break;
			pch[ch_count++] = ch;
			if(ch == 32)
			{
				cin.sync();
				ch = '\n';
				break;
			}
		}
		else
		{
			iserror(ch);
			flag = false;
			break;
		}
		cin.get(ch);
	}
	if (flag)
		pch[ch_count] = '\0';

}

int my_atoi(const char* pch)
{
	int sum = 0;
	int i = 0;
	int str_len = strlen(pch);
	Scale str_scale = DEC;

	if (pch && pch[0] <= 'a' && pch[0] >= 'z')
	{
		iserror(pch);
		return -1;
	}
	if (pch && pch[0] == '0' && pch[1] == 'x')//判断十六进制
	{
		i = 2;
		str_scale = HEX;
	}

	else if (pch && pch[0] == '0')//判断八进制
	{
		i = 1;
		for(int j = i;pch[j] != '\0';j++)
			if(pch[j]-'0' >= 8)
			{
				iserror(pch);
				return -1;
			}
		str_scale = OCT;
	}

	for (i; i < str_len; i++)
	{
		switch (pch[i])
		{
		case '0':case '1':case '2':case '3':
		case '4':case '5':case '6':case '7':
		case '8':case '9':case 'A':case 'B':
		case 'C':case 'D':case 'E':case 'F':
		{
			if(isupper(pch[i]))
				sum += (pch[i] - 'A' + 10) * pow((int)str_scale, str_len - i - 1);
			else
				sum += (pch[i] - '0') * pow((int)str_scale, str_len - i - 1);
			break;
		}

		default:
		{
			iserror(pch);
			return -1;
		}
		}
	}
	return sum;

}

void show_ret(int num)
{
	string str;
	cout << "please select a style of outputing number:";
	cin >> str;

	if (str == "Hex" || str == "HEX" || str == "hex")
		cout << hex << num;
	else if (str == "Dec" || str == "DEC" || str == "dec")
		cout << dec << num;
	else if (str == "Oct" || str == "OCT" || str == "oct")
		cout << oct << num;
	else
	{
		iserror();
		return;
	}
	cout << endl;
}