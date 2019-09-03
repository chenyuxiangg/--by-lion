#include <iostream>
#include "mystack.h"
#include <string.h>
using namespace std;

int main(int argc,char * argv[])
{
	Mystack<char> *stack = new Mystack<char>(30);//�洢��ƥ����ַ�
	Mystack<char> *needstack = new Mystack<char>(30);//�洢��Ҫ���ַ�

	char Currentneed = 0;
	char str[] = "[][()]]";

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != Currentneed)
		{
			stack->input(str[i]);

			switch(str[i])
			{
			case '(':
				if(Currentneed != 0)
			{
				needstack->input(Currentneed);
			}
				Currentneed = ')';
				break;

			case '[':
				if (Currentneed != 0)
				{
					needstack->input(Currentneed);
				}
				Currentneed = ']';
				break;
			default:
				cout << "���Ų�ƥ��" << endl;
				system("pause");
				return 0;
			}
		}
		else
		{
			char elem;
			stack->outstack(elem);
			if(needstack->stackempty())
			{
				Currentneed = 0;
			}
			else
				needstack->outstack(Currentneed);
		}
	}

	if(stack->stackempty())
	{
		cout << "����ƥ��" << endl;
	}
	else
	{
		cout << "���Ų�ƥ��" << endl;
	}

	delete needstack;
	needstack = NULL;

	delete stack;
	stack = NULL;

	system("pause");
	return 0;
}