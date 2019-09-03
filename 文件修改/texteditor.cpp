#include <iostream>
#include <string>
#include <cctype>

using namespace std;
#include "texteditor.h"

void eatblanks()
{
	char blank;
	while (cin.peek() == ' ')
		cin.get(blank);
}

texteditor :: texteditor(string infile,string outfile)
{
	myinfile.open(infile.data());
	myoutfile.open(outfile.data());
	if(!myinfile.is_open() || !myoutfile.is_open())
	{
		cerr << "Error opening in files";
		exit(-1);
	}
}

void texteditor :: run()
{
	showmenu();
	cout << "������¾����������" << endl;
	getline(myinfile, mystring);
	cout << "text:" << mystring << endl;
	char command;
	string str1, str2;
	for (;;)
	{
		if (myinfile.eof())
			break;
		cout << "���������";
		cin >> command;
		cin.ignore(1, '\n');
		switch(toupper(command))
		{
		case 'I':
			eatblanks();
			cout << "��������Ҫ��������ݣ�" << endl;
			getline(cin, str1);
			cout << "����Ҫ�����ģ�" << endl;
			getline(cin, str2);
			insert(str1, str2);
			break;
		case 'D' :
			eatblanks();
			cout << "��������Ҫɾ�������ݣ�" << endl;
			getline(cin, str1);
			erase(str1);
			break;
		case 'R' :
			eatblanks();
			cout << "��������Ҫ�滻�����ݣ�" << endl;
			getline(cin, str1);
			cout << "�������뽫�滻��";
			getline(cin, str2);
			replace(str1, str2);
			break;
		case 'N' :
			next();
			break;
		case 'Q' :
			quit();
			break;
		default :
			cout << "��������������������������룡" << endl;
			showmenu();
			cout << "text:" << mystring << endl;
		}

		if (!myinfile.eof())
			cout << "text:" << mystring << endl;
	}

	cout << "\n\n--------editing complete--------\n\n";

}

void texteditor :: showmenu()
{
	cout << "����ѡ���������" << endl;
	cout << "I/i :    ����" << "        " << "R/r :    ��д\n"
		<< "D/d :    ɾ��" << "        " << "N/n :    ��һ��\n"
		<< "Q/q :    �˳�\n";
}

void texteditor :: insert(string str1,string str2)
{
	int pos = mystring.find(str2);
	if (pos != string::npos)
		mystring.insert(pos, str1);
	else
		cout << "not found!" << endl;
}

void texteditor :: erase(string str)
{
	int pos = mystring.find(str);
	if (pos != string::npos)
		mystring.erase(pos, str.length());
	else
		cout << "not found!" << endl;
}

void texteditor :: replace(string str1,string str2)
{
	int pos = mystring.find(str2);
	if (pos != string::npos)
		mystring.replace(pos, str2.length(), str1);
	else
		cout << "not found!" << endl;
}

void texteditor :: next()
{
	myoutfile << mystring << endl;
	getline(myinfile, mystring);
	cout << "next text:";

}

void texteditor :: quit()
{
	myoutfile << mystring << endl;
	for(;;)
	{
		getline(myinfile, mystring);
		if (myinfile.eof())
			break;
		myoutfile << mystring << endl;
	}
}