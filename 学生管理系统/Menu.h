#pragma once
#ifndef MENU_H
#define MENU_H
#include "Class.h"
#include "Grade.h"
#include "Server_and_Sort.h"
#include "Student.h"
#include "Login.h"
using namespace std;

//enum User{root,user};//用户类型

void menu()
{
	char Us;
	cout << "您是什么类型的用户（0表示老师，1表示学生）：";
	cin >> Us;
	getchar();
	login();
	if(Us == '0')
	{
		cout << "*****************老师您好，欢迎进入学生管理系统***************" << endl;
		char ch;
		while (1)
		{
			cout << "======================================================" << endl;
			cout << "  1.登记班级信息                   2.增加单个学生    " << endl;
			cout << "  3.删除单个学生                   4.删除整个班级    " << endl;
			cout << "  5.登记所有学生成绩               6.修改单个学生成绩" << endl;
			cout << "  7.查看班级学生信息               8.班级内学生查找  " << endl;
			cout << "  9.班级成绩升序排序               a.年级内学生查找  " << endl;
			cout << "  b.全校成绩升序排序               d.修改密码        " << endl;
			cout << "  c.全校成绩降序排序               0.退出系统        " << endl;
			cout << "======================================================" << endl;
			cout << endl;
			cout << "请输入您想要执行的操作：";
			cin >> ch;
			switch (ch)
			{
			case '1':
				system("cls");
				Setclassmag();
				cout << "登记结束，按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '2':
				system("cls");
				Insertmag();
				cout << "增加学生成功，按任意键继续..." << endl;
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
				cout << "您已结束修改，按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '6':
				system("cls");
				Setsinglegre();
				cout << "您已结束修改，按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '7':
				system("cls");
				Traverse();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '8':
				system("cls");
				Serchstu();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '9':
				system("cls");
				Sort();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case 'a':
				system("cls");
				Serch_Schl();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case 'b':
				system("cls");
				Sort_Schl();
				cout << "排序结束，按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case 'c':
				system("cls");
				StackQuicksort();
				cout << "排序结束，按任意键继续..." << endl;
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
				cout << "输入有误！" << endl;
				break;
			}
			cout << "即将返回主菜单..." << endl;
			Sleep(1000);
			system("cls");
		}

		system("cls");
		cout << "**************感谢您的使用！****************" << endl;
		cout << "按任意键退出..." << endl;
		getchar();
		getchar();
	}//if

	if(Us == '1')
	{
		cout << "*****************同学您好，欢迎进入学生管理系统***************" << endl;
		char ch;
		while(1)
		{
			cout << "======================================================" << endl;
			cout << "  1.查看班级学生信息               2.班级内学生查找  " << endl;
			cout << "  3.班内成绩升序排序               4.年级内学生查找  " << endl;
			cout << "  5.全校成绩升序排序               6.修改密码        " << endl;
			cout << "  7.全校成绩降序排序               0.退出系统        " << endl;
			cout << "======================================================" << endl;
			cout << endl;
			cout << "请输入您想要执行的操作：";
			cin >> ch;
			switch(ch)
			{ 
			case '1':
				system("cls");
				Traverse();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '2':
				system("cls");
				Serchstu();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '3':
				system("cls");
				Sort();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '4':
				system("cls");
				Serch_Schl();
				cout << "按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '5':
				system("cls");
				Sort_Schl();
				cout << "排序结束，按任意键继续..." << endl;
				getchar();
				getchar();
				break;
			case '7':
				system("cls");
				StackQuicksort();
				cout << "排序结束，按任意键继续..." << endl;
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
				cout << "输入有误！" << endl;
				break;
			}
			cout << "即将返回主菜单..." << endl;
			Sleep(1000);
			system("cls");

			}
		}

		system("cls");
		cout << "*****************感谢您的使用！*********************" << endl;
		cout << "按任意键退出..." << endl;
		getchar();
		getchar();
	}


	/*cout << "*****************欢迎进入学生管理系统***************" << endl;
	char ch;
	while (1)
	{
		cout << "======================================================" << endl;
		cout << "  1.登记班级信息                   2.增加一个学生    " << endl;
		cout << "  3.删除单个学生                   4.删除一个班级    " << endl;
		cout << "  5.登记所有学生成绩               6.修改单个学生成绩" << endl;
		cout << "  7.查看班级学生信息               8.班级内学生查找  " << endl;
		cout << "  9.班内关键字升序排序             a.年级内学生查找  " << endl;
		cout << "  b.全校关键字升序排序             d.修改密码        " << endl;
		cout << "  c.全校关键字降序排序             0.退出系统        " << endl;
		cout << "======================================================" << endl;
		cout << endl;
		cout << "请输入您想要执行的操作：";
		cin >> ch;
		switch (ch)
		{
		case '1':
			system("cls");
			Setclassmag();
			cout << "登记结束，按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case '2':
			system("cls");
			Insertmag();
			cout << "增加学生成功，按任意键继续..." << endl;
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
			cout << "您已结束修改，按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case '6':
			system("cls");
			Setsinglegre();
			cout << "您已结束修改，按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case '7':
			system("cls");
			Traverse();
			cout << "按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case '8':
			system("cls");
			Serchstu();
			cout << "按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case '9':
			system("cls");
			Sort();
			cout << "按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case 'a':
			system("cls");
			Serch_Schl();
			cout << "按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case 'b':
			system("cls");
			Sort_Schl();
			cout << "排序成功，按任意键继续..." << endl;
			getchar();
			getchar();
			break;
		case 'c':
			system("cls");
			StackQuicksort();
			cout << "排序成功，按任意键继续..." << endl;
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
			cout << "输入有误！" << endl;
			break;
		}
		cout << "即将返回主菜单..." << endl;
		Sleep(1000);
		system("cls");
	}

	system("cls");
	cout << "**************感谢您的使用！****************" << endl;
	cout << "按任意键退出..." << endl;
	getchar();
	getchar();*/


#endif