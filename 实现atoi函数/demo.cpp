#include <iostream>
using namespace std;
const int N = 20;

char* str_Input(char* charr);
void My_atoi(char* str);
void show_str(char* str);

int main(int argc, char* argv[])
{
	system("pause");
	return 0;
}

char* str_Input(char* charr)
{
	charr = new char[N];
	char ch;
	int i = 0;

	while (1)
	{
		cin.get(ch);
		if (ch != '\n')
		{
			charr[i] = ch;
			i++;
		}
		else
			break;
	}
	return charr;
}

void show_str(char* str)
{
	cout << "The string is:" << endl;
	puts(str);
}

void My_atoi(char* str)
{

}