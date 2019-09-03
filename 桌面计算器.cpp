/*
操作说明：
1、每输入一个表达式后都需加一个分号，且分号应与表达式间有一个或多个空格。
2、除变量名外，每两个符号间应有一个空格。
*/


//头文件声明
#include <iostream>
#include <string>
#include <map>

//命名空间声明
using namespace std;

//自定义函数声明
typedef enum TOKEN {
	END, NUMBER, NAME,
	ADD = '+', MINUS = '-', MULTI = '*', DIV = '/',
	EQUAL = '=', PRINT = ';', LP = '(', RP = ')'
}token_value;

//全局变量声明
int Error_Count = 0;
double Tmp_Value = 0.0;
string Tmp_Str;
token_value flag = PRINT;
map<string, double> table;//可自动增长的常量表

//全局函数声明
double expr(bool get);
double term(bool get);
double prim(bool get);
token_value get_value();//为什么需要这个返回值呢？？
token_value reterror(string s);

//程序入口
int main(int argc, char* argv[])
{
	//初始化常量表
	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452345;

	while (cin)
	{
		get_value();
		if (flag == END) break;
		if (flag == PRINT) continue;
		cout << expr(false) << endl;
	}
	return 0;
}

//函数定义

token_value get_value()
{
	char ch = 0;
	cin >> ch;
	switch (ch)
	{
	case 0:
		return flag = END;

	case '+':
	case '-':
	case '*':
	case '/':
	case ';':
	case '(':
	case '=':
	case ')':
		return flag = token_value(ch);

	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':case '.':
		cin.putback(ch);
		cin >> Tmp_Value;
		return flag = NUMBER;

	default:
		if (isalpha(ch))
		{
			cin.putback(ch);
			cin >> Tmp_Str;
			return flag = NAME;
		}
		return reterror("无效输入");//此处不需要返回值，因为reterror里边自带返回值
	}
}

double expr(bool get)
{
	double left = term(get);
	while (true)
	{
		switch (flag)
		{
		case '+':
			left += term(true);
			break;
		case '-':
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}

double term(bool get)
{
	double left = prim(get);
	while (true)
	{
		switch(flag)
		{
		case '*':
			left *= prim(true);
			break;
		case '/':
			if (double t = prim(true))
			{
				left /= t;
				break;
			}
			return reterror("除数不能为0！");
		default:
			return left;
		}
	}
}

double prim(bool get)
{
	double e;
	if (get)
		get_value();
	switch (flag)
	{
	case NUMBER://如果是数字，就返回该数字
		e = Tmp_Value;
		get_value();
		return e;
		
	case NAME://如果时变量名，将其对应值计算出
	{
		double& v = table[Tmp_Str];
		if (get_value() == EQUAL)
			v = expr(true);
		return v; 
	}

	case MINUS:
		return -prim(true);

	case LP:
		e = expr(true);
		if (flag != RP)//因为在expr执行后就已经取了下一个符号，所以此处不需要再取下一个
			reterror("缺少右括号");
		get_value();
		return e;
	default:
		return reterror("表达式错误"); 

	}
}

token_value reterror(string s)
{
	Error_Count++;
	cerr << s << endl;
	return END;
}