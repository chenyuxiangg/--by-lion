#ifndef BINARY_SORT_TREE_H
#define BINARY_SORT_TREE_H
#include <iostream>
using namespace std;

typedef struct Bitree 
{
	int data;
	int num;
	Bitree* Lchild;
	Bitree* Rchild;
}Bitree;

int BSerch(Bitree* tree);
void BInput(Bitree* tree);
bool BDelete(Bitree* tree);
bool BInoderTranverce(Bitree* tree);
void BCreatBiTree(Bitree* tree, int mfirst);
void BDlesinsgle(Bitree* &tree);
bool BSetnum(Bitree* &tree);

void BCreatBiTree(Bitree* tree,int mfirst)//demo中提示用户输入第一个结点数据
{
	tree->data = mfirst;
	tree->num = 1;
	tree->Lchild = NULL;
	tree->Rchild = NULL;
	Bitree* p = NULL;//用于构建并插入结点
	Bitree* t = NULL;//用于遍历结点
	//bool R = false;
	//bool L = false;

	cout << "接下来构建其他结点，请输入该树的其他结点数据：" << endl;
	int i_num = 1;
	char ch = 'y';
	while(ch == 'y')
	{
		++i_num;
		p = new Bitree;
		t = tree;
		cout << "请输入第" << i_num << "个结点的数据:";
		cin >> p->data;
		p->Lchild = NULL;
		p->Rchild = NULL;
		while (t->Lchild || t->Rchild)
		{
			if (p->data > t->data)
			{
				//R = true;
				if (t->Rchild)
					t = t->Rchild;
				else
					break;
			}
			else
			{
				//L = true;
				if (t->Lchild)
					t = t->Lchild;
				else
					break;
			}
		}
		if (p->data > t->data)
		{
			p->num = (t->num * 2 + 1);
			t->Rchild = p;
		}
		else
		{
			p->num = (t->num * 2);
			t->Lchild = p;
		}
		p = NULL;
		cout << "您是否想要继续为此数增加结点？";
		cin >> ch;
	}

	cout << "成功创建一课二叉排序树..." << endl;
}

bool BInoderTranverce(Bitree* tree)
{
	if (tree == NULL)
		return true;
	BInoderTranverce(tree->Lchild);
	cout << tree->data << " ";
	BInoderTranverce(tree->Rchild);
	return true;
}

bool BDelete(Bitree* tree)
{
	if (tree == NULL)
		return true;
	BDelete(tree->Lchild);
	BDelete(tree->Rchild);
	delete tree;
	return true;
}

void BInput(Bitree* tree)
{
	cout << "请输入您要插入的数据：" << endl;
	int da;
	cin >> da;

	Bitree* t = tree;
	Bitree* p = new Bitree;
	p->data = da;
	p->Lchild = NULL;
	p->Rchild = NULL;

	while (t->Lchild || t->Rchild)
	{
		if (p->data > t->data)
		{
			//R = true;
			if (t->Rchild)
				t = t->Rchild;
			else
				break;
		}
		else
		{
			//L = true;
			if (t->Lchild)
				t = t->Lchild;
			else
				break;
		}
	}
	if (p->data > t->data)
	{
		p->num = (t->num * 2 + 1);
		t->Rchild = p;
	}
	else
	{
		p->num = (t->num * 2 + 1);
		t->Lchild = p;
	}
	p = NULL;
}

int BSerch(Bitree* tree)
{
	if(tree == NULL)
	{
		cout << "该树为空..." << endl;
		return 0;
	}
	Bitree* t = tree;
	cout << "请输入您要查询的数据";
	int da;
	cin >> da;

	while (t)
	{
		if (t->data == da)
			return t->num;
		else if (t->data < da)
			t = t->Rchild;
		else
			t = t->Lchild;
	}
	if (t)
	{
		return t->num;
	}
	else
		return 0;
}
/*再删除了头节点后，余下内存不可访问，原因：我之前用的参数是Bitree* tree,在函数内修改了tree的指向却在函数返回的
时候断了联系，tree相当于一个临时变量。当需要修改指针的指向时，考虑到互换两个变量值的操作时，是将变量的地址做为
参数传递的，那么*/
void BDlesinsgle(Bitree* &tree)
{
	bool YD = false;
	Bitree* t = tree;
	Bitree* p = NULL;
	Bitree* f = NULL;
	cout << "请输入您要删除的数据结点：";
	int da;
	cin >> da;

	while(t)
	{
		if (t->data == da)
		{
			YD = true;
			if (t->num == 1)
			{
				if (t->Rchild)
				{
					t = t->Rchild;
					while (t->Lchild)
					{
						t = t->Lchild;
					}
					t->Lchild = tree->Lchild;
					p = tree->Rchild;
					delete tree;
					t = NULL;
					tree = p;
					p = NULL;
				}
				else
				{
					p = tree->Lchild;
					delete tree;
					t = NULL;
					tree = p;
					p = NULL;
				}

			}
			else
			{
				if (t->Rchild)
				{
					p = t;
					t = t->Rchild;
					while (t->Lchild)
					{
						t = t->Lchild;
					}
					t->Lchild = p->Lchild;
					if (p == f->Lchild)
						f->Lchild = p->Rchild;
					else
						f->Rchild = p->Rchild;
					delete p;
					p = NULL;
				}
				else
				{
					if (t == f->Lchild)
						f->Lchild = t->Lchild;
					else
						f->Rchild = t->Lchild;
					delete t;
					t = NULL;
				}

			}
		}
		else if(t->data < da)
		{
			f = t;
			t = t->Rchild;
		}
		else
		{
			f = t;
			t = t->Lchild;
		}

	}

	if (YD)
		cout << "结点" << da << "删除成功！" << endl;
	else
		cout << "删除的结点不存在" << endl;

	//递归设置新位置
	tree->num = 1;
	BSetnum(tree);
}

bool BSetnum(Bitree* &tree)
{
	if (tree->Lchild == NULL)
	{
		return true;
	}
	else
	{
		tree->Lchild->num = (tree->num * 2);
		BSetnum(tree->Lchild);
	}
	if(tree->Rchild == NULL)
	{
		return true;
	}
	else
	{
		tree->Rchild->num = (tree->num * 2 + 1);
		BSetnum(tree->Rchild);
	}
	return true;
}

#endif !BINARY_SORT_TREE_H

