#include <iostream>
using namespace std;

class Point {
public:
	char ch;
	int next[26];
	int qoutCount;
	Point();
	~Point(){}
};

Point :: Point()
{
	ch = ' ';
	qoutCount = 0;
	memset(next, -1, sizeof(int) * 26);
}

class Tree {
private:
	Point* tree;
	int Count;

public:
	Tree();
	~Tree();
	void Insert(char* str);
	int Query(char* str);
};

Tree :: Tree()
{
	tree = new Point[10000];
	Count = 0;
}

Tree :: ~Tree()
{
	delete[] tree;
	tree = NULL;
}

void Tree :: Insert(char* str)
{
	int lcount = 0;
	for (unsigned int i = 0;i < strlen(str);i++)
	{
		int x = str[i] - 'a';
		if (tree[lcount].next[x] == -1)
		{
			tree[lcount].next[x] = ++Count;//���д�� Count++��ᵼ���ȸ�ֵȻ��Count�ż�1
			tree[Count].ch = str[i];
			tree[Count].qoutCount++;//��ǰ������ô�����1
			lcount = tree[lcount].next[x];
		}
		else
		{//�����ǰλ����Ԫ�أ���ĸ�����򽫵�ǰλ�õ�qoutCount��1
			int y = tree[lcount].next[x];
			tree[y].qoutCount++;
			lcount = y;
		}
	}
}

int Tree :: Query(char* str)
{
	int Cmpnum = 0;
	int lenth = 0;
	for (unsigned int i = 0;i < strlen(str); i++)
	{
		int x = str[i] - 'a';
		if (tree[Cmpnum].next[x] == -1)
			return 0;
		else
		{
			int y = tree[Cmpnum].next[x];
			lenth = tree[y].qoutCount;
			Cmpnum = y;
		}

	}
	return lenth;
}

int main(int argc, char* argv[])
{
	Tree t;
	//�����ֵ���
	int n;
	char* s = NULL;
	s = new char[10];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		t.Insert(s);
	}

	//������Ҫ��ѯ�ĵ���
	//ע�⣺��ָ����ַ���ʱ��������Ϊ������ڴ棬��ᵼ���ڴ����
	int m;
	cin >> m;
	char* arr1[100];
	for (int i = 0; i < m; i++)
	{
		arr1[i] = new char[10];
		cin >> arr1[i];
	}

	//��ѯ
	for (int i = 0; i < m; i++)
		cout << t.Query(arr1[i]) << endl;


	for(int i = 0;i < m; i++)
	{
		delete[] arr1[i];
		arr1[i] = NULL;
	}
	delete[] s;
	s = NULL;
	system("pause");
	return 0;
}