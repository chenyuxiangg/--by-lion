#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int Get_next(string str,char Next[],int n,int L)
{
	Next[0] = -1;
	int h = 0;
	int k = -1;
	int l = L;
	while (h < l - 1)
	{
		if (k == -1 || str[h] == str[k])
		{
			k++;
			h++;
			if (str[h] != str[k])
				Next[h] = k;
			else
				Next[h] = Next[k];
		}

		else
		{
			k = Next[k];
		}
	}
	return Next[h];
}

int KMP_serch(string s,string p,char Next[],int n)//s���ı�����p��ģʽ��
{
	int i = 0;//�ı�����ǰλ��
	int j = 0;//ģʽ����ǰλ��

	while(i < (int)s.length() && j < (int)p.length())
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Get_next(p,Next,n,j);
		}
	}

	if (j == p.length())
		return i - j;
	else
		return -1;
}

int main(int argc, char* argv[])
{
	int const n = 100;
	char next[n];
	char str[100];
	string p;
	ifstream infile;

	cout << "��������Ҫ���ʵ��ļ���������س�������:" << " ";
	cin.getline(str,'\n');
	cout << endl;
	infile.open(str, ios :: in);
	if(!infile)
	{
		cerr << "�ļ���ʧ�ܣ�";
		abort();
	}

	cout << "��������Ҫ���ҵ��ַ�������س�������:" << " ";
	getline(cin, p);
	cout << endl;

	string s;
	int i_row = 0;//�������
	while(!infile.eof())
	{
		int i_num = 0;
		char* i_p = NULL;
		++i_row;
		getline(infile, s);
		cout << "��" << i_row << "�У�" << s << endl;

		int B = KMP_serch(s, p, next, n);
		while(B != -1 && s.length() >= p.length())
		{
			i_num++;
			if (B + p.length() >= s.length())
				break;
			i_p = &s[B + p.length()];
			s = i_p;
			i_p = NULL;
			B = KMP_serch(s, p, next, n);
		}
		cout << "��" << i_row << "����" << i_num << "��\"" << p << "\"" << endl;
		cout << endl;
}

	infile.close();

	system("pause");
	return 0;
}