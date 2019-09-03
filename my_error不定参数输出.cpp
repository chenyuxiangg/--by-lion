/*
写一个error函数，，它取一个printf风格的包含%s,%d,%c指示符的格式串，以及任意多个其他参数，请不要使用printf（）
。使用<cstdarg>
*/

#include <iostream>
#include <cstdarg>
using namespace std;

//error
void my_error(char* ch, ...);

//驱动程序
int main(int argc, char* argv[])
{
	char ch = 'h';
	char* arr = "chenyuxiang";
	int age = 20;
	my_error("I am %s,I have %d age,%c%n", arr, age, ch);

	system("pause");
	return 0;
}

void my_error(char* ch, ...)
{
	va_list vp;
	int Len = strlen(ch);
	va_start(vp, ch);

	for (int i = 0; i < Len; i++)
	{
		if (ch[i] != '%' || i == Len - 1)
		{
			cout << ch[i];
			continue;
		}
		switch (ch[++i])
		{
		case 'c':
		{
			char t = va_arg(vp, char);
			cout << t;
			break; 
		}
		case 's':
		{
			char* s = va_arg(vp, char*);
			int s_len = strlen(s);
			for (int k = 0; k < s_len; k++)
			{
				cout << s[k];
			}
			break;
		}
		case 'd':
		{
			int data = va_arg(vp, int);
			cout << data;
			break;
		}
		case 'n':
		{
			cout << endl;
			break;
		}
		default:
		{
			va_end(vp);
			cout << "非法参数！" << endl;
			return;
		}
		}
	}
	va_end(vp);
	return;
}