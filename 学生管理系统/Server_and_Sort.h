#pragma once
#ifndef SERVER_AND_SORT_H
#define SERVER_AND_SORT_H
#include "Server.h"

//函数接口
bool Serchstu();
void Sort();
void Sort_Schl();
void Serch_Schl();
void StackQuicksort();
//

//函数定义
bool Serchstu()
{
	cout << "请输入您要查看的班级号：";
	char classId[Id_num];
	cin >> classId;
	getchar();//取走回车

	//打开班级号文件，检查班级号是否存在
	char CSch[20][25];//获取班级号的数组
	bool claexit = false;
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//提取所有班级号
	int sa = 0;
	while (!inSch.eof())
	{
		inSch >> CSch[sa];
		sa++;
	}
	inSch.close();
	//

	for(int j = 0;j < sa;j++)
	{
		if(StrCompare(classId,CSch[j]))
		{
			claexit = true;
			ifstream infile;
			infile.open(classId, ios::in);
			struct Class claT;
			//提取这个班级所有学生的信息
			int lenth;
			char len[20];
			infile >> len;
			istringstream in(len);
			in >> lenth;
			int i = 0;
			while (!infile.eof())
			{
				infile >> claT.student[i].Id;
				infile.ignore();
				//cout << claT.student[i].Id;

				infile >> claT.student[i].name;
				infile.ignore();
				//cout << claT.student[i].name;

				int i_sex;
				infile >> i_sex;
				claT.student[i].sex = (Sex)i_sex;
				infile.ignore();
				//cout << claT.student[i].sex;

				infile >> claT.student[i].age;
				infile.ignore();
				//cout << claT.student[i].age;

				infile >> claT.student[i].Tel;
				infile.ignore();
				//cout << claT.student[i].Tel;

				infile >> claT.student[i].sub.SJ;
				infile.ignore();

				infile >> claT.student[i].sub.LS;
				infile.ignore();

				infile >> claT.student[i].sub.GL;
				infile.ignore();

				infile >> claT.student[i].sub.DL;
				infile.ignore();

				infile >> claT.student[i].sub.YY;

				i++;

			}
			infile.close();

			//查找

			cout << "请输入您要查找的学生ID:";
			unsigned long long id;
			cin >> id;
			for (int i = 0; i < lenth; i++)
			{
				if (id == claT.student[i].Id)
				{
					cout << "学生姓名：" << claT.student[i].name << endl;
					cout << "学生ID：" << claT.student[i].Id << endl;
					if (claT.student[i].sex == 0)
					{
						cout << "学生性别：" << "男" << endl;
					}
					else
					{
						cout << "学生性别：" << "女" << endl;
					}
					cout << "学生年龄：" << claT.student[i].age << endl;
					cout << "学生电话：" << claT.student[i].Tel << endl;
					cout << "学生数据结构成绩：" << claT.student[i].sub.SJ << endl;
					cout << "学生离散数学成绩：" << claT.student[i].sub.LS << endl;
					cout << "学生概率统计成绩：" << claT.student[i].sub.GL << endl;
					cout << "学生英语成绩：" << claT.student[i].sub.YY << endl;
					cout << "学生电路成绩：" << claT.student[i].sub.DL << endl;
					return true;
				}

			}
			cout << "该学生不在" << classId << "班级" << endl;
			return false;
		}//if
	}//for
	if (!claexit)
		cout << "输入的班级不存在..." << endl;
	return claexit;
}

void Sort()
{
	bool enable = true;//表示已经排序
	cout << "请输入您要排序的班级号：";
	char classId[Id_num];
	cin >> classId;
	getchar();//取走回车

	//打开班级号文件，检查班级号是否存在
	char CSch[20][25];//获取班级号的数组
	bool claexit = false;
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//提取所有班级号
	int sa = 0;
	while (!inSch.eof())
	{
		inSch >> CSch[sa];
		sa++;
	}
	inSch.close();
	//
	for (int j = 0; j < sa; j++)
	{
		if(StrCompare(classId,CSch[j]))
		{
			claexit = true;
			ifstream infile;
			infile.open(classId, ios::in);
			struct Class claT;
			//提取这个班级所有学生的信息
			int lenth;
			char len[20];
			infile >> len;
			istringstream in(len);
			in >> lenth;
			int i = 0;
			while (!infile.eof())
			{
				infile >> claT.student[i].Id;
				infile.ignore();
				//cout << claT.student[i].Id;

				infile >> claT.student[i].name;
				infile.ignore();
				//cout << claT.student[i].name;

				int i_sex;
				infile >> i_sex;
				claT.student[i].sex = (Sex)i_sex;
				infile.ignore();
				//cout << claT.student[i].sex;

				infile >> claT.student[i].age;
				infile.ignore();
				//cout << claT.student[i].age;

				infile >> claT.student[i].Tel;
				infile.ignore();
				//cout << claT.student[i].Tel;

				infile >> claT.student[i].sub.SJ;
				infile.ignore();

				infile >> claT.student[i].sub.LS;
				infile.ignore();

				infile >> claT.student[i].sub.GL;
				infile.ignore();

				infile >> claT.student[i].sub.DL;
				infile.ignore();

				infile >> claT.student[i].sub.YY;
				//infile.ignore();

				i++;

			}
			infile.close();

			//排序
			char ch;
			cout << "您要按哪个成绩排序？" << endl;
			cout << "======================================" << endl;
			cout << "  1.概率统计成绩            2.英语成绩    " << endl;
			cout << "  3.电路成绩                4.数据结构成绩 " << endl;
			cout << "  5.离散数学成绩            6.不想排序了    " << endl;
			cout << "======================================" << endl;
			cin >> ch;
			switch (ch)
			{
			case '1':
				QuicksortGL(claT.student, lenth, 0, lenth - 1);
				break;
			case '2':
				QuicksortYY(claT.student, lenth, 0, lenth - 1);
				break;
			case '3':
				QuicksortDL(claT.student, lenth, 0, lenth - 1);
				break;
			case '4':
				QuicksortSJ(claT.student, lenth, 0, lenth - 1);
				break;
			case '5':
				QuicksortLS(claT.student, lenth, 0, lenth - 1);
				break;
			case '6':
				enable = false;
				break;
			default:
				cout << "您的输入有误！" << endl;
				break;
			}
			//将排序后的学生成绩写入文件
			ofstream outfile;
			outfile.open(classId, ios::out);
			outfile << lenth << endl;
			for (int i = 0; i < lenth; i++)
			{
				outfile << '\n' << claT.student[i].Id;
				outfile << '\0';

				outfile << claT.student[i].name;
				outfile << '\0';

				int i_sex;
				i_sex = claT.student[i].sex;
				outfile << i_sex;
				outfile << '\0';

				outfile << claT.student[i].age;
				outfile << '\0';

				outfile << claT.student[i].Tel;
				outfile << '\0';

				outfile << claT.student[i].sub.SJ << '\0';
				outfile << claT.student[i].sub.LS << '\0';
				outfile << claT.student[i].sub.GL << '\0';
				outfile << claT.student[i].sub.DL << '\0';
				outfile << claT.student[i].sub.YY;
			}
			outfile.close();
			if (enable)
			{
				cout << "排序成功！" << endl;
			}
		}
	}//for

	if (!claexit)
		cout << "输入的班级不存在..." << endl;
}

//年级上的排序不存入文件，排序后直接输出
void Sort_Schl()
{
	bool enable = true;//表示已经排序
	//直接使用char CSch[Schstu][25]会由于Schstu过大而导致栈溢出
	//一般来说，不应调用大于100的数组，若要如此，需申请堆
	char CSch[Class_num][25];//用于提取所有班级号

							 //打开班级号文件，提取所有班级信息
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//提取所有班级号
	int sa = 0;
	while (!inSch.eof())
	{
		inSch >> CSch[sa];
		sa++;
	}
	inSch.close();

	ifstream Cinfile;
	int i_stunum = 0;
	struct Student* Astu = new struct Student[Schstu];
	//将所有学生提取到数组Astu中
	for (int sb = 0; sb < sa; sb++)
	{
		Cinfile.open(CSch[sb], ios::in);
		char Slen[25];
		Cinfile >> Slen;//目的是将光标移到下一行

		while (!Cinfile.eof())
		{
			Cinfile >> Astu[i_stunum].Id;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].name;
			Cinfile.ignore();

			int Ssex;
			Cinfile >> Ssex;
			Astu[i_stunum].sex = (Sex)Ssex;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].age;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].Tel;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.SJ;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.LS;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.GL;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.YY;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.DL;

			i_stunum++;
		}//end while
		Cinfile.close();
	}//end for

	 //排序
	char ch;
	cout << "您要按哪个成绩排序？" << endl;
	cout << "======================================" << endl;
	cout << "  1.概率统计成绩            2.英语成绩    " << endl;
	cout << "  3.电路成绩                4.数据结构成绩 " << endl;
	cout << "  5.离散数学成绩            6.不想排序了    " << endl;
	cout << "======================================" << endl;
	cin >> ch;
	switch (ch)
	{
	case '1':
		QuicksortGL(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '2':
		QuicksortYY(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '3':
		QuicksortDL(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '4':
		QuicksortSJ(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '5':
		QuicksortLS(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '6':
		enable = false;
		break;
	default:
		enable = false;
		cout << "您的输入有误！" << endl;
		break;
	}

	//输出排序后的学生信息
	if(enable)
	{
		int stop = 0;
		cout << "===================================" << endl;
		for (int i_s = 0; i_s < i_stunum; i_s++)
		{
			stop++;
			cout << endl;
			cout << "学生ID：";
			cout << Astu[i_s].Id << endl;

			cout << "学生姓名：";
			cout << Astu[i_s].name << endl;

			cout << "学生性别：";
			if (Astu[i_s].sex == 0)
				cout << "男" << endl;
			else
				cout << "女" << endl;

			cout << "学生年龄：";
			cout << Astu[i_s].age << endl;

			cout << "学生电话：";
			cout << Astu[i_s].Tel << endl;

			cout << "*******成绩*******" << endl;
			cout << "数据结构：";
			cout << Astu[i_s].sub.SJ << endl;

			cout << "离散数学：";
			cout << Astu[i_s].sub.LS << endl;

			cout << "概率统计：";
			cout << Astu[i_s].sub.GL << endl;

			cout << "英语：";
			cout << Astu[i_s].sub.YY << endl;

			cout << "电路：";
			cout << Astu[i_s].sub.DL << endl;
			cout << "====================================" << endl;
			if (stop % 5 == 0)
			{
				cout << "还有" << i_stunum - stop << "条记录，按任意键继续查看" << endl;
				getchar();
				getchar();
				system("cls");
			}
	}

	}//for
	delete[] Astu;
}

void Serch_Schl()
{
	char CSch[Class_num][25];//用于提取所有班级号

							 //打开班级号文件，提取所有班级信息
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//提取所有班级号
	int sa = 0;
	while (!inSch.eof())
	{
		inSch >> CSch[sa];
		sa++;
	}
	inSch.close();

	ifstream Cinfile;
	int i_stunum = 0;
	struct Student* Astu = new struct Student[Schstu];
	//将所有学生提取到数组Astu中
	for (int sb = 0; sb < sa; sb++)
	{
		Cinfile.open(CSch[sb], ios::in);
		char Slen[25];
		Cinfile >> Slen;//目的是将光标移到下一行

		while (!Cinfile.eof())
		{
			Cinfile >> Astu[i_stunum].Id;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].name;
			Cinfile.ignore();

			int Ssex;
			Cinfile >> Ssex;
			Astu[i_stunum].sex = (Sex)Ssex;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].age;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].Tel;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.SJ;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.LS;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.GL;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.YY;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.DL;

			i_stunum++;
		}//end while
		Cinfile.close();
	}//end for

	 //查找学生
	cout << "请输入您要查找的学生的ID：";
	bool YD = false;
	unsigned long long StuID;
	cin >> StuID;

	for (int sa = 0; sa < i_stunum; sa++)
	{
		if (StuID == Astu[sa].Id)
		{
			YD = true;
			cout << endl;
			cout << "学生ID：";
			cout << Astu[sa].Id << endl;

			cout << "学生姓名：";
			cout << Astu[sa].name << endl;

			cout << "学生性别：";
			if (Astu[sa].sex == 0)
				cout << "男" << endl;
			else
				cout << "女" << endl;

			cout << "学生年龄：";
			cout << Astu[sa].age << endl;

			cout << "学生电话：";
			cout << Astu[sa].Tel << endl;

			cout << "*******成绩*******" << endl;
			cout << "数据结构：";
			cout << Astu[sa].sub.SJ << endl;

			cout << "离散数学：";
			cout << Astu[sa].sub.LS << endl;

			cout << "概率统计：";
			cout << Astu[sa].sub.GL << endl;

			cout << "英语：";
			cout << Astu[sa].sub.YY << endl;

			cout << "电路：";
			cout << Astu[sa].sub.DL << endl;
			break;
		}
	}
	delete[] Astu;
	Astu = NULL;
	if (!YD)
		cout << "您查找的ID：" << StuID << "不存在于本年级，请核对..." << endl;

}

void StackQuicksort()
{
	bool enable = true;//表示已经排好序
	char CSch[Class_num][25];//用于提取所有班级号

							 //打开班级号文件，提取所有班级信息
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//提取所有班级号
	int sa = 0;
	while (!inSch.eof())
	{
		inSch >> CSch[sa];
		sa++;
	}
	inSch.close();

	ifstream Cinfile;
	int i_stunum = 0;
	struct Student* Astu = new struct Student[Schstu];
	//将所有学生提取到数组Astu中
	for (int sb = 0; sb < sa; sb++)
	{
		Cinfile.open(CSch[sb], ios::in);
		char Slen[25];
		Cinfile >> Slen;//目的是将光标移到下一行

		while (!Cinfile.eof())
		{
			Cinfile >> Astu[i_stunum].Id;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].name;
			Cinfile.ignore();

			int Ssex;
			Cinfile >> Ssex;
			Astu[i_stunum].sex = (Sex)Ssex;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].age;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].Tel;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.SJ;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.LS;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.GL;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.YY;
			Cinfile.ignore();

			Cinfile >> Astu[i_stunum].sub.DL;

			i_stunum++;
		}//end while
		Cinfile.close();
	}//end for

	 //排序
	char ch;
	cout << "您要按哪个成绩排序？" << endl;
	cout << "======================================" << endl;
	cout << "  1.概率统计成绩            2.英语成绩    " << endl;
	cout << "  3.电路成绩                4.数据结构成绩 " << endl;
	cout << "  5.离散数学成绩            6.不想排序了    " << endl;
	cout << "======================================" << endl;
	cin >> ch;
	switch (ch)
	{
	case '1':
		QuicksortGL(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '2':
		QuicksortYY(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '3':
		QuicksortDL(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '4':
		QuicksortSJ(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '5':
		QuicksortLS(Astu, i_stunum, 0, i_stunum - 1);
		break;
	case '6':
		enable = false;
		break;
	default:
		enable = false;
		cout << "您的输入有误！" << endl;
		break;
	}

	//将升序排序后的学生信息入栈
	Mystack<Student> stack(Schstu);
	for (int Si = 0; Si < i_stunum; Si++)
		stack.input(Astu[Si]);

	if(enable)
	{
		//输出学生信息
		while (!stack.stackempty())
		{
			Student elem;
			stack.outstack(elem);

			cout << endl;
			cout << "学生ID：";
			cout << elem.Id << endl;

			cout << "学生姓名：";
			cout << elem.name << endl;

			cout << "学生性别：";
			if (elem.sex == 0)
				cout << "男" << endl;
			else
				cout << "女" << endl;

			cout << "学生年龄：";
			cout << elem.age << endl;

			cout << "学生电话：";
			cout << elem.Tel << endl;

			cout << "*******成绩*******" << endl;
			cout << "数据结构：";
			cout << elem.sub.SJ << endl;

			cout << "离散数学：";
			cout << elem.sub.LS << endl;

			cout << "概率统计：";
			cout << elem.sub.GL << endl;

			cout << "英语：";
			cout << elem.sub.YY << endl;

			cout << "电路：";
			cout << elem.sub.DL << endl;
			cout << "====================================" << endl;
		}
	}
	
	delete[] Astu;
	Astu = NULL;
}

#endif