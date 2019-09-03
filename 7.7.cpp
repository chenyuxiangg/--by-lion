 /*
考虑：
struct Tnode{
string word,
int count,
Tnode* left,
Tnode* right
};

写一个函数向Tnode的树中插入新的单词，写一个函数将Tnode的树打印出来。写一个函数将Tnode的树按照单词
的字典顺序打印出来。修改Tnode，使他只存储一个到任意长度的单词的指针，该单词存储在一个有new分配的
字符数组里。修改上述函数，使他们能使用新的Tnode。
*/
#include <iostream>
#include <string>
using namespace std;

//节点申明
struct Tnode{
	string word;//考虑此成员如何赋值
	int count;
	Tnode* left;
	Tnode* right;
};
//创建一个节点
Tnode* Create_Node(const string& str);

//创建一棵单词树
void Create_Tree(Tnode*& root, const string& str);

//向单词树中插入单词
void Insert_subword(Tnode* root, Tnode* Node);

//打印单词树
void Output_Tree(Tnode* toot);

//比较函数
int Word_Compare(const string& str1, const string& str2);

//清除树
void Delete_Tree(Tnode* root);

//驱动程序
int main(int argc, char* argv[])
{
	Tnode* Root = NULL;
	Create_Tree(Root, "root");
	string s;
	cin >> s;
	while (s != "Quit")
	{
		Tnode* Node = Create_Node(s);
		Insert_subword(Root, Node);
		cin >> s;
	}
	Output_Tree(Root);
	cout << endl;

	Delete_Tree(Root);
	system("pause");
	return 0;
}

Tnode* Create_Node(const string& str)
{
	Tnode* node = new Tnode;
	node->word = str;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void Create_Tree(Tnode*& root, const string& str)
{
	root = new Tnode;
	root->word = str;
	root->left = NULL;
	root->right = NULL;
}

void Insert_subword(Tnode* root, Tnode* Node)
{
	if (root == NULL)
		return;
	else
	{
		if (Word_Compare(Node->word, root->word) > 0)
		{
			if (root->right == NULL)
				root->right = Node;
			else
				Insert_subword(root->right, Node);
		}
		else if (Word_Compare(Node->word, root->word) < 0)
		{
			if (root->left == NULL)
				root->left = Node;
			else
				Insert_subword(root->left, Node);
		}
		else
			return;
	}
	return;
}

void Output_Tree(Tnode* root)
{
	if (root == NULL)
		return;
	else
	{
		if (root->left)
			Output_Tree(root->left);
		cout << root->word << " ";
		if (root->right)
			Output_Tree(root->right);
		return;
	}
}

int Word_Compare(const string& str1, const string& str2)
{
	for (int i = 0; i < str1.length() && i < str2.length(); i++)
	{
		if (str1[i] > str2[i])
			return 1;
		if (str1[i] < str2[i])
			return -1;
	}
	return 0;
}

void Delete_Tree(Tnode* root)
{
	if (root == NULL)
		return;
	else
	{
		if (root->left != NULL)
			Delete_Tree(root->left);
		if (root->right != NULL)
			Delete_Tree(root->right);
		delete root;
		root = NULL;
		return;
	}
}
