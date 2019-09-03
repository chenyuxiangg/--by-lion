#include <iostream>
#include <cstring>
using namespace std;

typedef struct Tnode {
	char* word;
	int count;
	Tnode* left;
	Tnode* right;
}*pTnode;

pTnode init_Tnode(const char* word)
{
	pTnode node = new Tnode;
	int length = strlen(word);
	node->word = new char[length+1];
	strcpy(node->word,word);
	node->count = 1;
	node->left = node->right = NULL;
	return node;
}

bool Insertword(pTnode &root, const char* word)
{
	if (root)
	{
		pTnode tmp = root;
		while (tmp)
		{
			int flag = strcmp(word,tmp->word);
			if (flag == 0)
			{
				++tmp->count;
				return false;
			}
			else
			{
				pTnode& next = flag > 0 ? tmp->right : tmp->left;
				if (!next)
				{
					next = init_Tnode(word);
					return true;
				}
				else
				{
					tmp = next;
				}
			}
		}
		return true;
	}
	else
	{
		root = init_Tnode(word);
	}
	return true;
}

void Output(const pTnode root)
{
	if (root->left)
	{
		Output(root->left);
	}
	cout << root->word << endl;
	if (root->right)
	{
		Output(root->right);
	}
	return;
}

void Destroy(pTnode& root)
{
	if (root->left)
	{
		Destroy(root->left);
	}
	if (root->right)
	{
		Destroy(root->right);
	}
	delete[] root->word;
	root->word = NULL;
	delete root;
	root = NULL;
	return;
}

int main(int argc, char* argv[])
{
	pTnode root = init_Tnode("book");
	Insertword(root, "app");
	Insertword(root, "copy");
	Insertword(root, "keep");
	Insertword(root, "hhhhh");
	Insertword(root, "peoplennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm");
	Output(root);
	Destroy(root);
	return 0;
}
