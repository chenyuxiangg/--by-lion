#pragma once
#ifndef LOGIN_H
#define LOFIN_H
#include <iostream>
#include "StrCompare.h"
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

void login();
void Setpass();

void Setpass()
{
	bool bEnable = false;
	ofstream opassfile;
	ifstream ipassfile;
	char other[128];
	char temp[128];
	cout << "������ԭʼ���룺";
	cin >> other;
	ipassfile.open("passwd.txt",ios::in);
	ipassfile >> temp;
	ipassfile.close();
	if(StrCompare(other, temp))
	{
		bEnable = true;
		opassfile.open("passwd.txt", ios::out);
		cout << "�����������룺";
		cin >> other;
		opassfile << other;
		opassfile.close();
	}

	if (bEnable)
		cout << "�޸ĳɹ���" << endl;
	else
		cout << "ԭʼ���벻��ȷ��" << endl;
}

void login()
{
	ifstream iuserfile;
	ifstream ipasswdfile;
	const int reset = 3;
	int j;
	char usrname[128];
	char passwd[128];
	char ut[128];
	char pt[128];

	memset(usrname, 0, sizeof(usrname));
	memset(passwd, 0, sizeof(passwd));
	memset(ut, 0, sizeof(ut));
	memset(pt, 0, sizeof(pt));

	char ch;
	for (j = reset; j > 0; j--)
	{
		iuserfile.open("usrname.txt", ios::in);
		cout << "�û�����";
		for (int i = 0; i < sizeof(usrname) - 1; i++)
		{
			ch = getchar();
			if (ch == '\n')
				break;
			usrname[i] = ch;
		}
		iuserfile >> ut;
		iuserfile.close();

		ipasswdfile.open("passwd.txt", ios::in);
		cout << "���룺";
		for (int i = 0; i < sizeof(usrname) - 1;)
		{
			ch = _getch();
			if(ch == '\0')
				continue;
			if (ch == '\r')
				break;
			if (ch == '\b')
			{
				if (i > 0)
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					i--;
				}
			}
			else
			{
				passwd[i] = ch;
				putchar('*');
				i++;
			}
		}
		ipasswdfile >> pt;
		ipasswdfile.close();
		if (StrCompare(passwd,pt) && StrCompare(usrname,ut))
		{
			cout << endl;
			cout << "��½�ɹ�����������ϵͳ..." << endl;
			Sleep(1000);
			break;
		}
		else
		{
			cout << endl;
			cout << "������������" << endl;
			cout << "������" << j - 1 << "�ε�½����" << endl;
		}
	}
	if (j == 0)
	{
		cout << "�����������������࣬�����˳�ϵͳ..." << endl;
		Sleep(1000);
		exit(-1);
	}
	system("cls");
}

#endif