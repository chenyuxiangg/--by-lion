#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "Server.h"

//函数接口
void Setclassmag();
bool DeleteAll();
void Traverse();
//

//函数定义
void Setclassmag()
{
	int i_Sch = 0;
	char CSch[Schstu][25];
	char Cch = 'y';
	while (Cch == 'y')
	{
		cout << "请输入您想要登记的班级号：";
		char classId[Id_num];
		cin >> classId;
		getchar();//取走回车
				  //将班级号存入文件并使班级数加一，存放所有班级号的文件为  all.txt
		inSch.open("all.txt", ios::in);
		//if(!Sch.is_open())
		//cout << "not Right" << endl;
		char wlen[25];
		int Length;
		inSch >> wlen;
		inSch.close();

		istringstream i_Len(wlen);
		i_Len >> Length;
		/*这里需要注意：若直接用out打开一个文件而不进行任何操作直接关闭的话，可能会将文件里原有的
		内容置空.不能同时使用ios::out 与ios::in，否则打开文件失败.在向文件中输入内容时，若想要空出
		第一行，当回车之前无任何内容时，回车失效.ios::ate打开的不是文件末尾（还需要验证到底是怎么回事）
		*/
		if (Length == 0)
		{
			outSch.open("all.txt", ios::out);
			outSch << Length;//将长度传进去
			outSch << '\n' << classId;
			i_Sch++;
			outSch.seekp(ios::beg);
			outSch << i_Sch;
			outSch.close();
		}
		else
		{
			inSch.open("all.txt", ios::in);
			char t[25];
			inSch >> t;
			//提取所有班级号
			int i_c = 0;
			while (!inSch.eof())
			{
				inSch >> CSch[i_c];
				i_c++;
			}
			inSch.close();

			bool simile = false;
			outSch.open("all.txt", ios::out);
			outSch << i_c;
			//判断输入的班级是否存在，不存在则新建一个
			//加入新的班级后将原来的班级放入文件
			for (int sc = 0; sc < i_c; sc++)
			{
				if (!StrCompare(classId, CSch[sc]))
					outSch << '\n' << CSch[sc];
				else
					simile = true;
			}
			if (simile)
			{
				outSch << '\n' << classId;
				i_c = Length;
			}
			else
				i_c++;
			outSch.seekp(ios::beg);
			outSch << i_c;
		}
		outSch.close();

		ofstream outfile;
		outfile.open(classId, ios::out);
		if (!outfile.is_open())
			cerr << "文件打开失败！";
		outfile << 0;
		int i = 0;
		char ch = 'y';
		struct Class Cla;
		int i_sex;
		while (i != Student_num && ch == 'y')
		{
			i++;
			cout << "请输入登记学生的ID：";
			cin >> Cla.student[i].Id;
			outfile << '\n' << Cla.student[i].Id;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的姓名：";
			cin >> Cla.student[i].name;
			outfile << Cla.student[i].name;
			outfile << '\0';
			//getchar();

			//getchar();
			cout << "请输入学生的性别(0代表男生，1代表女生)：";
			cin >> i_sex;
			while (i_sex != 0 && i_sex != 1)
			{
				cout << "没有这类人，请核对信息后再输入..." << endl;
				cin >> i_sex;
			}
			Cla.student[i].sex = (Sex)i_sex;
			outfile << Cla.student[i].sex;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的年龄：";
			cin >> Cla.student[i].age;
			outfile << Cla.student[i].age;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的电话：";
			cin >> Cla.student[i].Tel;
			outfile << Cla.student[i].Tel;
			outfile << '\0';
			//getchar();

			Cla.student[i].sub.DL = 0.0;
			Cla.student[i].sub.SJ = 0.0;
			Cla.student[i].sub.GL = 0.0;
			Cla.student[i].sub.LS = 0.0;
			Cla.student[i].sub.YY = 0.0;
			outfile << Cla.student[i].sub.SJ << '\0';
			outfile << Cla.student[i].sub.LS << '\0';
			outfile << Cla.student[i].sub.GL << '\0';
			outfile << Cla.student[i].sub.DL << '\0';
			outfile << Cla.student[i].sub.YY;


			cout << "还有学生需要登记么？";
			cin >> ch;
		}
		outfile.seekp(ios::beg);
		outfile << i;
		outfile.close();
		if (i == Student_num)
			cout << "该班级学生人数已达上限！" << endl;
		cout << "您是否想要继续管理班级？";
		cin >> Cch;
		system("cls");
	}
}

bool DeleteAll()
{
	int i_Sch;
	bool YN = false;
	char CSch[20][25];
	cout << "请输入您想删除的班级号：";
	char classId[Id_num];
	cin >> classId;
	getchar();//取走回车
	//打开班级号文件，检查班级号是否存在
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

	i_Sch = Length;
	outSch.open("all.txt", ios::out);
	outSch << i_Sch;
	for (int sb = 0; sb < Length; sb++)
	{
		if (StrCompare(classId, CSch[sb]))//此处不能等于，应写函数判断
		{
			YN = true;
			i_Sch--;

			ofstream outfile;
			outfile.open(classId, ios::out);
			outfile << ' ';
			outfile.close();
		}
		else
		{
			outSch << '\n' << CSch[sb];
		}
	}
	outSch.seekp(ios::beg);
	outSch << i_Sch;
	outSch.close();
	if (!YN)
		cout << "您输入的班级号不存在，请核对后再试..." << endl;
	else
		cout << "已删除ID为" << classId << "的班级" << endl;
	return YN;

}

void Traverse()
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
	for(int i = 0;i < sa;i++)
	{
		if(StrCompare(classId,CSch[i]))
		{
			claexit = true;
			cout << "|   学号   |   姓名   |   性别   |   年龄   |   电话   |";
			cout << "   数据   |   离散   |   概论   |   电路   |   英语   |" << endl;
			cout << "========================================================";
			cout << "========================================================" << endl;
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
				cout << claT.student[i].Id << " ";

				infile >> claT.student[i].name;
				infile.ignore();
				cout << "  "<< claT.student[i].name << " ";

				int i_sex;
				infile >> i_sex;
				claT.student[i].sex = (Sex)i_sex;
				infile.ignore();
				if (claT.student[i].sex == 0)
					cout << "      " << "男" << "     ";
				else
					cout << "      " << "女" << "     ";

				infile >> claT.student[i].age;
				infile.ignore();
				cout << "    " << claT.student[i].age << " ";

				infile >> claT.student[i].Tel;
				infile.ignore();
				cout << "    " << claT.student[i].Tel << " ";

				infile >> claT.student[i].sub.SJ;
				infile.ignore();
				cout << "   " << claT.student[i].sub.SJ << " ";

				infile >> claT.student[i].sub.LS;
				infile.ignore();
				cout << "       " << claT.student[i].sub.LS << " ";

				infile >> claT.student[i].sub.GL;
				infile.ignore();
				cout << "         " << claT.student[i].sub.GL << " ";

				infile >> claT.student[i].sub.DL;
				infile.ignore();
				cout << "       " << claT.student[i].sub.DL << " ";

				infile >> claT.student[i].sub.YY;
				//infile.ignore();
				cout << "        " << claT.student[i].sub.YY << endl;
				//getchar();

				i++;

			}//while
			infile.close();
			cout << "========================================================";
			cout << "========================================================" << endl;
			break;
		}//if
	}//for
	if (!claexit)
		cout << "输入的班级不存在..." << endl;
}

#endif