#include<iostream>
#include<string>
using namespace std;
void Next(string substr, int *next);
int KMP(string str, string substr, int *next, int pos);
int Get_one(const int* arr, int substr_len);
int main()
{
	string str;
	string substr;
	cin >> str >> substr;
	int str_len = str.length();
	int substr_len = substr.length();

	int *next = new int[substr_len];
	Next(substr, next);

	int jump = Get_one(next, substr_len);
	int count = 0;
	int pos = 0;
	int t = 0;

	for (int i = 0; i < str_len && pos + substr_len <= str_len; i++)
	{
		t = KMP(str, substr, next, pos);//t是当前匹配到的位置（模式串中）与此次匹配的pos之差。也就是模式串中相邻两个匹配串之间的间隔
		if (t != -1)
		{
			count++;
			if (t - pos + 1 > jump)
				pos = t + 1;
			else
				pos += jump;
		}
	}
	cout << count << endl;

	system("pause");
	return 0;
}
void Next(string substr, int *next)
{
	int i = 0, j = -1;
	int substr_len = substr.length();
	next[i] = j;
	while (i < substr_len - 1)
	{
		if (j == -1 || substr[i] == substr[j])
		{
			i++;
			j++;
			if (substr[i] == substr[j])
			{
				next[i] = next[j];
			}
			else
				next[i] = j;
		}
		else
			j = next[j];
	}
}
int KMP(string str, string substr, int* next, int pos)
{
	int i = pos, j = 0;
	int str_len = str.length(), substr_len = substr.length();
	Next(substr, next);
	while (i < str_len && j < substr_len)
	{
		if (j == -1 || substr[j] == str[i])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if (j == substr_len)
		return i - j;
	return -1;
}

int Get_one(const int* arr, int substr_len)
{
	int i = 0;
	while (arr[i] != 1 && i < substr_len)
		i++;
	return i - 1;
}