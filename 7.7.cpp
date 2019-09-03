 /*
���ǣ�
struct Tnode{
string word,
int count,
Tnode* left,
Tnode* right
};

дһ��������Tnode�����в����µĵ��ʣ�дһ��������Tnode������ӡ������дһ��������Tnode�������յ���
���ֵ�˳���ӡ�������޸�Tnode��ʹ��ֻ�洢һ�������ⳤ�ȵĵ��ʵ�ָ�룬�õ��ʴ洢��һ����new�����
�ַ�������޸�����������ʹ������ʹ���µ�Tnode��
*/
#include <iostream>
#include <string>
using namespace std;

//�ڵ�����
struct Tnode{
	string word;//���Ǵ˳�Ա��θ�ֵ
	int count;
	Tnode* left;
	Tnode* right;
};
//����һ���ڵ�
Tnode* Create_Node(const string& str);

//����һ�õ�����
void Create_Tree(Tnode*& root, const string& str);

//�򵥴����в��뵥��
void Insert_subword(Tnode* root, Tnode* Node);

//��ӡ������
void Output_Tree(Tnode* toot);

//�ȽϺ���
int Word_Compare(const string& str1, const string& str2);

//�����
void Delete_Tree(Tnode* root);

//��������
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
