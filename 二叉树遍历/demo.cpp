#include <iostream>
#include "Tree.h"
#include <conio.h>
using namespace std;

void creattree()
{
	cout << "请为树创建第一个结点（root）" << endl;
	cout << "请输入此结点的数据：";
}

int main(int argc,int argv[])
{
	Coordinate* coor1 = NULL;
	int Date;
	//建立root
	creattree();
	cin >> Date;
	coor1 = new Coordinate(Date);
	Tree tree(coor1);
	if (coor1 == NULL)
	{
		cout << "不好意思，出了点小问题，树创建失败..." << endl;
		exit(-1);
	}
	coor1 = NULL;
	cout << "您成功创建一棵树~请继续您的操作..." << endl;
	Coordinate* pc = NULL;
	char ch;
	while (1)
	{
		cout << "--------------------------------------------" << endl;
		cout << "                  操作菜单" << endl;
		cout << "     1.插入左结点            2.插入右结点  " << endl;
		cout << "     3.前序遍历树            4.中序遍历树  " << endl;
		cout << "     5.后序遍历树            6.寻找结点    " << endl;
		cout << "     7.清空树                8.生成新树    " << endl;
		cout << "     9.退出                              " << endl;
		cout << "--------------------------------------------" << endl;
		cout << "您想要什么操作：（请输入序号）";
		cin >> ch;

		switch (ch)
		{
		case '1':
			system("Cls");
			cout << "请输入结点的数据：";
			int date1;
			cin >> date1;
			pc = new Coordinate(date1);
			cout << endl;

			cout << "您想将它插在哪个结点上（输入序号）：";
			int i_Num;
			cin >> i_Num;
			tree.TsetleftC(i_Num, pc);
			pc = NULL;
			system("Cls");
			break;
		case '2':
			system("Cls");
			cout << "请输入结点的数据：";
			int date2;
			cin >> date2;
			pc = new Coordinate(date2);
			cout << endl;

			cout << "您想将它插在哪个结点上（输入序号）：";
			int i_Num1;
			cin >> i_Num1;
			tree.TsetrightC(i_Num1,pc);
			pc = NULL;
			system("Cls");
			break;
		case '3':
			system("Cls");
			cout << "前序遍历结果为：" << endl;
			tree.Tpretransform();
			cout << endl;
			_getch();
			system("Cls");
			break;
		case '4':
			system("Cls");
			cout << "中序遍历结果为：" << endl;
			tree.Tintransform();
			cout << endl;
			_getch();
			system("Cls");
			break;
		case '5':
			system("Cls");
			cout << "后序遍历结果为：" << endl;
			tree.Tposttransform();
			cout << endl;
			_getch();
			system("Cls");
			break;
		case '6':
			system("Cls");
			cout << "请输入您要查找的结点序号：";
			int x;
			cin >> x;
			cout << endl;
			cout << "查找结果为：" << endl;
			if(tree.Tserch(x))
			{
				cout << tree.Tserch(x)->Getdate();
			}
			_getch();
			system("Cls");
			break;
		case '7':
			system("Cls");
			tree.~Tree();
			cout << "树已清空。" << endl;
			_getch();
			system("Cls");
			break;
		case '8':
			system("Cls");
			if(tree.GetCoor())
			{
				tree.~Tree();
				creattree();
				cin >> Date;
				coor1 = new Coordinate(Date);
				tree.SetCoor(coor1);
				if (coor1 == NULL)
				{
					cout << "不好意思，出了点小问题，树创建失败..." << endl;
					exit(-1);
				}
				coor1 = NULL;
				cout << "您成功创建一棵树~请继续您的操作..." << endl;
			}

			else
			{
				creattree();
				cin >> Date;
				coor1 = new Coordinate(Date);
				tree.SetCoor(coor1);
				if (coor1 == NULL)
				{
					cout << "不好意思，出了点小问题，树创建失败..." << endl;
					exit(-1);
				}
				coor1 = NULL;
				cout << "您成功创建一棵树~请继续您的操作..." << endl;
			}
			break;
		case '9':
			exit(-1);
		default:
			system("Cls");
			cout << "您的输入有误，请重新输入（0~8）" << endl;
			break;

		}
	}



	system("pause");
	return 0;
}