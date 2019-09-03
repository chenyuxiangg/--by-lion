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
	cout << "请输入原始密码：";
	cin >> other;
	ipassfile.open("passwd.txt",ios::in);
	ipassfile >> temp;
	ipassfile.close();
	if(StrCompare(other, temp))
	{
		bEnable = true;
		opassfile.open("passwd.txt", ios::out);
		cout << "请输入新密码：";
		cin >> other;
		opassfile << other;
		opassfile.close();
	}

	if (bEnable)
		cout << "修改成功！" << endl;
	else
		cout << "原始密码不正确！" << endl;
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
		cout << "用户名：";
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
		cout << "密码：";
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
			cout << "登陆成功，即将进入系统..." << endl;
			Sleep(1000);
			break;
		}
		else
		{
			cout << endl;
			cout << "密码输入有误！" << endl;
			cout << "您还有" << j - 1 << "次登陆机会" << endl;
		}
	}
	if (j == 0)
	{
		cout << "密码输入错误次数过多，即将退出系统..." << endl;
		Sleep(1000);
		exit(-1);
	}
	system("cls");
}

#endif