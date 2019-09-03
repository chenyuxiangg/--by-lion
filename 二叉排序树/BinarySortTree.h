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

void BCreatBiTree(Bitree* tree,int mfirst)//demo����ʾ�û������һ���������
{
	tree->data = mfirst;
	tree->num = 1;
	tree->Lchild = NULL;
	tree->Rchild = NULL;
	Bitree* p = NULL;//���ڹ�����������
	Bitree* t = NULL;//���ڱ������
	//bool R = false;
	//bool L = false;

	cout << "����������������㣬���������������������ݣ�" << endl;
	int i_num = 1;
	char ch = 'y';
	while(ch == 'y')
	{
		++i_num;
		p = new Bitree;
		t = tree;
		cout << "�������" << i_num << "����������:";
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
		cout << "���Ƿ���Ҫ����Ϊ�������ӽ�㣿";
		cin >> ch;
	}

	cout << "�ɹ�����һ�ζ���������..." << endl;
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
	cout << "��������Ҫ��������ݣ�" << endl;
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
		cout << "����Ϊ��..." << endl;
		return 0;
	}
	Bitree* t = tree;
	cout << "��������Ҫ��ѯ������";
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
/*��ɾ����ͷ�ڵ�������ڴ治�ɷ��ʣ�ԭ����֮ǰ�õĲ�����Bitree* tree,�ں������޸���tree��ָ��ȴ�ں������ص�
ʱ�������ϵ��tree�൱��һ����ʱ����������Ҫ�޸�ָ���ָ��ʱ�����ǵ�������������ֵ�Ĳ���ʱ���ǽ������ĵ�ַ��Ϊ
�������ݵģ���ô*/
void BDlesinsgle(Bitree* &tree)
{
	bool YD = false;
	Bitree* t = tree;
	Bitree* p = NULL;
	Bitree* f = NULL;
	cout << "��������Ҫɾ�������ݽ�㣺";
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
		cout << "���" << da << "ɾ���ɹ���" << endl;
	else
		cout << "ɾ���Ľ�㲻����" << endl;

	//�ݹ�������λ��
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

