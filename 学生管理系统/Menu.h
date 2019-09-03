#pragma once
#ifndef MENU_H
#define MENU_H
#include "Class.h"
#include "Grade.h"
#include "Server_and_Sort.h"
#include "Student.h"
#include "Login.h"
using namespace std;

//enum User{root,user};//�û�����

void menu()
{
	char Us;
	cout << "����ʲô���͵��û���0��ʾ��ʦ��1��ʾѧ������";
	cin >> Us;
	getchar();
	login();
	if(Us == '0')
	{
		cout << "*****************��ʦ���ã���ӭ����ѧ������ϵͳ***************" << endl;
		char ch;
		while (1)
		{
			cout << "======================================================" << endl;
			cout << "  1.�Ǽǰ༶��Ϣ                   2.���ӵ���ѧ��    " << endl;
			cout << "  3.ɾ������ѧ��                   4.ɾ�������༶    " << endl;
			cout << "  5.�Ǽ�����ѧ���ɼ�               6.�޸ĵ���ѧ���ɼ�" << endl;
			cout << "  7.�鿴�༶ѧ����Ϣ               8.�༶��ѧ������  " << endl;
			cout << "  9.�༶�ɼ���������               a.�꼶��ѧ������  " << endl;
			cout << "  b.ȫУ�ɼ���������               d.�޸�����        " << endl;
			cout << "  c.ȫУ�ɼ���������               0.�˳�ϵͳ        " << endl;
			cout << "======================================================" << endl;
			cout << endl;
			cout << "����������Ҫִ�еĲ�����";
			cin >> ch;
			switch (ch)
			{
			case '1':
				system("cls");
				Setclassmag();
				cout << "�Ǽǽ����������������..." << endl;
				getchar();
				getchar();
				break;
			case '2':
				system("cls");
				Insertmag();
				cout << "����ѧ���ɹ��������������..." << endl;
				getchar();
				getchar();
				break;
			case '3':
				system("cls");
				Deletestu();
				break;
			case '4':
				system("cls");
				DeleteAll();
				break;
			case '5':
				system("cls");
				Setgress();
				cout << "���ѽ����޸ģ������������..." << endl;
				getchar();
				getchar();
				break;
			case '6':
				system("cls");
				Setsinglegre();
				cout << "���ѽ����޸ģ������������..." << endl;
				getchar();
				getchar();
				break;
			case '7':
				system("cls");
				Traverse();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case '8':
				system("cls");
				Serchstu();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case '9':
				system("cls");
				Sort();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case 'a':
				system("cls");
				Serch_Schl();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case 'b':
				system("cls");
				Sort_Schl();
				cout << "��������������������..." << endl;
				getchar();
				getchar();
				break;
			case 'c':
				system("cls");
				StackQuicksort();
				cout << "��������������������..." << endl;
				getchar();
				getchar();
				break;
			case 'd':
				system("cls");
				Setpass();
				break;
			case '0':
				exit(-1);
			default:
				cout << "��������" << endl;
				break;
			}
			cout << "�����������˵�..." << endl;
			Sleep(1000);
			system("cls");
		}

		system("cls");
		cout << "**************��л����ʹ�ã�****************" << endl;
		cout << "��������˳�..." << endl;
		getchar();
		getchar();
	}//if

	if(Us == '1')
	{
		cout << "*****************ͬѧ���ã���ӭ����ѧ������ϵͳ***************" << endl;
		char ch;
		while(1)
		{
			cout << "======================================================" << endl;
			cout << "  1.�鿴�༶ѧ����Ϣ               2.�༶��ѧ������  " << endl;
			cout << "  3.���ڳɼ���������               4.�꼶��ѧ������  " << endl;
			cout << "  5.ȫУ�ɼ���������               6.�޸�����        " << endl;
			cout << "  7.ȫУ�ɼ���������               0.�˳�ϵͳ        " << endl;
			cout << "======================================================" << endl;
			cout << endl;
			cout << "����������Ҫִ�еĲ�����";
			cin >> ch;
			switch(ch)
			{ 
			case '1':
				system("cls");
				Traverse();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case '2':
				system("cls");
				Serchstu();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case '3':
				system("cls");
				Sort();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case '4':
				system("cls");
				Serch_Schl();
				cout << "�����������..." << endl;
				getchar();
				getchar();
				break;
			case '5':
				system("cls");
				Sort_Schl();
				cout << "��������������������..." << endl;
				getchar();
				getchar();
				break;
			case '7':
				system("cls");
				StackQuicksort();
				cout << "��������������������..." << endl;
				getchar();
				getchar();
				break;
			case '6':
				system("cls");
				Setpass();
				break;
			case '0':
				exit(-1);
			default:
				cout << "��������" << endl;
				break;
			}
			cout << "�����������˵�..." << endl;
			Sleep(1000);
			system("cls");

			}
		}

		system("cls");
		cout << "*****************��л����ʹ�ã�*********************" << endl;
		cout << "��������˳�..." << endl;
		getchar();
		getchar();
	}


	/*cout << "*****************��ӭ����ѧ������ϵͳ***************" << endl;
	char ch;
	while (1)
	{
		cout << "======================================================" << endl;
		cout << "  1.�Ǽǰ༶��Ϣ                   2.����һ��ѧ��    " << endl;
		cout << "  3.ɾ������ѧ��                   4.ɾ��һ���༶    " << endl;
		cout << "  5.�Ǽ�����ѧ���ɼ�               6.�޸ĵ���ѧ���ɼ�" << endl;
		cout << "  7.�鿴�༶ѧ����Ϣ               8.�༶��ѧ������  " << endl;
		cout << "  9.���ڹؼ�����������             a.�꼶��ѧ������  " << endl;
		cout << "  b.ȫУ�ؼ�����������             d.�޸�����        " << endl;
		cout << "  c.ȫУ�ؼ��ֽ�������             0.�˳�ϵͳ        " << endl;
		cout << "======================================================" << endl;
		cout << endl;
		cout << "����������Ҫִ�еĲ�����";
		cin >> ch;
		switch (ch)
		{
		case '1':
			system("cls");
			Setclassmag();
			cout << "�Ǽǽ����������������..." << endl;
			getchar();
			getchar();
			break;
		case '2':
			system("cls");
			Insertmag();
			cout << "����ѧ���ɹ��������������..." << endl;
			getchar();
			getchar();
			break;
		case '3':
			system("cls");
			Deletestu();
			break;
		case '4':
			system("cls");
			DeleteAll();
			break;
		case '5':
			system("cls");
			Setgress();
			cout << "���ѽ����޸ģ������������..." << endl;
			getchar();
			getchar();
			break;
		case '6':
			system("cls");
			Setsinglegre();
			cout << "���ѽ����޸ģ������������..." << endl;
			getchar();
			getchar();
			break;
		case '7':
			system("cls");
			Traverse();
			cout << "�����������..." << endl;
			getchar();
			getchar();
			break;
		case '8':
			system("cls");
			Serchstu();
			cout << "�����������..." << endl;
			getchar();
			getchar();
			break;
		case '9':
			system("cls");
			Sort();
			cout << "�����������..." << endl;
			getchar();
			getchar();
			break;
		case 'a':
			system("cls");
			Serch_Schl();
			cout << "�����������..." << endl;
			getchar();
			getchar();
			break;
		case 'b':
			system("cls");
			Sort_Schl();
			cout << "����ɹ��������������..." << endl;
			getchar();
			getchar();
			break;
		case 'c':
			system("cls");
			StackQuicksort();
			cout << "����ɹ��������������..." << endl;
			getchar();
			getchar();
			break;
		case 'd':
			system("cls");
			Setpass();
			break;
		case '0':
			exit(-1);
		default:
			cout << "��������" << endl;
			break;
		}
		cout << "�����������˵�..." << endl;
		Sleep(1000);
		system("cls");
	}

	system("cls");
	cout << "**************��л����ʹ�ã�****************" << endl;
	cout << "��������˳�..." << endl;
	getchar();
	getchar();*/


#endif