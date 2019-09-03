/*
从输入读一系列单词，使用Quit作为输入的结束单词。按照读入的顺序打印出这些单词，但同一个单词不要打印
两次。修改这个程序，再打印之前对单词排序。
*/

#include <iostream>
#include <string>
using namespace std;
int i = 0;
char buf[20];

//读入单词
void Input(string* strarr);

//比较函数
bool str_Compare(const string str1, const string str2);

//去重
int de_weight(string* strarr);

//排序（升序）
void Sort(string* strarr);

//驱动程序
int main(int argc, char* argv[])
{
	string* str_arr = new string[50];
	Input(str_arr);
	int Count = de_weight(str_arr);
	Sort(str_arr);

	//输出
	for (int j = 0; j < Count; j++)
		cout << str_arr[j] << " ";
	cout << endl;

	delete[] str_arr;
	str_arr = NULL;
	system("pause");
	return 0;
}

void Input(string* strarr)
{
	cin >> strarr[i];
	while (strarr[i] != "Quit")
	{
		i++;
		cin >> strarr[i];
	}
}

bool str_Compare(const string str1, const string str2)
{
	int s_i = 0;
	while (s_i < str1.length() && s_i < str2.length())
	{
		if (str1[s_i] > str2[s_i])
			return true;
		else if (str1[s_i] < str2[s_i])
			return false;
		else
		{
			s_i++;
			continue;
		}
	}
	return false;
}

int de_weight(string* strarr)
{
	string str[50];
	int count = 0;
	bool flag = true;
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < count; k++)
			if (strarr[j] != str[k])
			{
				flag = true;
				continue;
			}
			else
			{
				flag = false;
				break;
			}
		if (flag)
			str[count++] = strarr[j];
	}
	for (int j = 0; j < count; j++)
		strarr[j] = str[j];
	i = count;
	return count;
}


void Sort(string* strarr)
{
	for (int j = 0; j < i - 1; j++)
	{
		for (int k = 0; k < i - j - 1; k++)
		{
			if (str_Compare(strarr[k],strarr[k+1]))
			{
				string t = strarr[k];
				strarr[k] = strarr[k + 1];
				strarr[k + 1] = t;
			}
		}
	}
}