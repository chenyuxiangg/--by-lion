#include"iostream"
using namespace std;
int min(int a, int b);
int min(int a, int b, int c);
int min(int a, int b, int c, int d);

int main(int argc,char* argv[])
{
	int i = 5;
	int j = 2;
	int k = 6;
	int h = 1;

	int g = min(i, j);
	int p = min(h, k, i);
	int f = min(k, j, i, h);

	cout << "������������Сֵ�� " << g << endl;
	cout << "������������Сֵ�� " << p << endl;
	cout << "�ĸ���������Сֵ�� " << f << endl;

	return 0;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int min(int a,int b,int c)
{
	if (a > b)
	{
		if (b > c)
			return c;
		else
			return b;
	}
	else
	{
		if (a > c)
			return c;
		else
			return a;
	}
}

int min(int a,int b,int c,int d)
{
	int l, m;
	if (a > b)
		l = b;
	else
		l = a;
	if (c > d)
		m = d;
	else
		m = c;
	if (l > m)
		return m;
	else
		return l;
}