/*
����˵����
1��ÿ����һ�����ʽ�����һ���ֺţ��ҷֺ�Ӧ����ʽ����һ�������ո�
2�����������⣬ÿ�������ż�Ӧ��һ���ո�
*/


//ͷ�ļ�����
#include <iostream>
#include <string>
#include <map>

//�����ռ�����
using namespace std;

//�Զ��庯������
typedef enum TOKEN {
	END, NUMBER, NAME,
	ADD = '+', MINUS = '-', MULTI = '*', DIV = '/',
	EQUAL = '=', PRINT = ';', LP = '(', RP = ')'
}token_value;

//ȫ�ֱ�������
int Error_Count = 0;
double Tmp_Value = 0.0;
string Tmp_Str;
token_value flag = PRINT;
map<string, double> table;//���Զ������ĳ�����

//ȫ�ֺ�������
double expr(bool get);
double term(bool get);
double prim(bool get);
token_value get_value();//Ϊʲô��Ҫ�������ֵ�أ���
token_value reterror(string s);

//�������
int main(int argc, char* argv[])
{
	//��ʼ��������
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

//��������

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
		return reterror("��Ч����");//�˴�����Ҫ����ֵ����Ϊreterror����Դ�����ֵ
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
			return reterror("��������Ϊ0��");
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
	case NUMBER://��������֣��ͷ��ظ�����
		e = Tmp_Value;
		get_value();
		return e;
		
	case NAME://���ʱ�������������Ӧֵ�����
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
		if (flag != RP)//��Ϊ��exprִ�к���Ѿ�ȡ����һ�����ţ����Դ˴�����Ҫ��ȡ��һ��
			reterror("ȱ��������");
		get_value();
		return e;
	default:
		return reterror("���ʽ����"); 

	}
}

token_value reterror(string s)
{
	Error_Count++;
	cerr << s << endl;
	return END;
}