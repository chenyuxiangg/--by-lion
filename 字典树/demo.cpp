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
			tree[lcount].next[x] = ++Count;//如果写成 Count++则会导致先赋值然后Count才加1
			tree[Count].ch = str[i];
			tree[Count].qoutCount++;//当前点的引用次数加1
			lcount = tree[lcount].next[x];
		}
		else
		{//如果当前位置有元素（字母），则将当前位置的qoutCount加1
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
	//创建字典树
	int n;
	char* s = NULL;
	s = new char[10];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		t.Insert(s);
	}

	//输入需要查询的单词
	//注意：用指针存字符串时，若不先为其分配内存，则会导致内存溢出
	int m;
	cin >> m;
	char* arr1[100];
	for (int i = 0; i < m; i++)
	{
		arr1[i] = new char[10];
		cin >> arr1[i];
	}

	//查询
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