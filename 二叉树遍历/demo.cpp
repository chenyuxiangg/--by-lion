#include <iostream>
#include "Tree.h"
#include <conio.h>
using namespace std;

void creattree()
{
	cout << "��Ϊ��������һ����㣨root��" << endl;
	cout << "������˽������ݣ�";
}

int main(int argc,int argv[])
{
	Coordinate* coor1 = NULL;
	int Date;
	//����root
	creattree();
	cin >> Date;
	coor1 = new Coordinate(Date);
	Tree tree(coor1);
	if (coor1 == NULL)
	{
		cout << "������˼�����˵�С���⣬������ʧ��..." << endl;
		exit(-1);
	}
	coor1 = NULL;
	cout << "���ɹ�����һ����~��������Ĳ���..." << endl;
	Coordinate* pc = NULL;
	char ch;
	while (1)
	{
		cout << "--------------------------------------------" << endl;
		cout << "                  �����˵�" << endl;
		cout << "     1.��������            2.�����ҽ��  " << endl;
		cout << "     3.ǰ�������            4.���������  " << endl;
		cout << "     5.���������            6.Ѱ�ҽ��    " << endl;
		cout << "     7.�����                8.��������    " << endl;
		cout << "     9.�˳�                              " << endl;
		cout << "--------------------------------------------" << endl;
		cout << "����Ҫʲô����������������ţ�";
		cin >> ch;

		switch (ch)
		{
		case '1':
			system("Cls");
			cout << "������������ݣ�";
			int date1;
			cin >> date1;
			pc = new Coordinate(date1);
			cout << endl;

			cout << "���뽫�������ĸ�����ϣ�������ţ���";
			int i_Num;
			cin >> i_Num;
			tree.TsetleftC(i_Num, pc);
			pc = NULL;
			system("Cls");
			break;
		case '2':
			system("Cls");
			cout << "������������ݣ�";
			int date2;
			cin >> date2;
			pc = new Coordinate(date2);
			cout << endl;

			cout << "���뽫�������ĸ�����ϣ�������ţ���";
			int i_Num1;
			cin >> i_Num1;
			tree.TsetrightC(i_Num1,pc);
			pc = NULL;
			system("Cls");
			break;
		case '3':
			system("Cls");
			cout << "ǰ��������Ϊ��" << endl;
			tree.Tpretransform();
			cout << endl;
			_getch();
			system("Cls");
			break;
		case '4':
			system("Cls");
			cout << "����������Ϊ��" << endl;
			tree.Tintransform();
			cout << endl;
			_getch();
			system("Cls");
			break;
		case '5':
			system("Cls");
			cout << "����������Ϊ��" << endl;
			tree.Tposttransform();
			cout << endl;
			_getch();
			system("Cls");
			break;
		case '6':
			system("Cls");
			cout << "��������Ҫ���ҵĽ����ţ�";
			int x;
			cin >> x;
			cout << endl;
			cout << "���ҽ��Ϊ��" << endl;
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
			cout << "������ա�" << endl;
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
					cout << "������˼�����˵�С���⣬������ʧ��..." << endl;
					exit(-1);
				}
				coor1 = NULL;
				cout << "���ɹ�����һ����~��������Ĳ���..." << endl;
			}

			else
			{
				creattree();
				cin >> Date;
				coor1 = new Coordinate(Date);
				tree.SetCoor(coor1);
				if (coor1 == NULL)
				{
					cout << "������˼�����˵�С���⣬������ʧ��..." << endl;
					exit(-1);
				}
				coor1 = NULL;
				cout << "���ɹ�����һ����~��������Ĳ���..." << endl;
			}
			break;
		case '9':
			exit(-1);
		default:
			system("Cls");
			cout << "���������������������루0~8��" << endl;
			break;

		}
	}



	system("pause");
	return 0;
}