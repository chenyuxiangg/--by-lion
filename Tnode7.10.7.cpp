#include <iostream>
#include <string>
using namespace std;

typedef struct Tnode {
	string word;
	int count;
	Tnode* left;
	Tnode* right;
}*pTnode;

pTnode init_Tnode(const string& word)
{
	pTnode node = new Tnode;
	node->word = word;
	node->count = 1;
	node->left = node->right = NULL;
	return node;
}

bool Insertword(pTnode &root, const string& word)
{
	if (root)
	{
		pTnode tmp = root;
		while (tmp)
		{
			int flag = word.compare(tmp->word);
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
	Insertword(root, "chen");
	Output(root);
	Destroy(root);
	return 0;
}
