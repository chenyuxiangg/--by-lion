#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Server.h"

//函数接口
bool Insertmag();
void Deletestu();
//

//函数定义
bool Insertmag()
{
	bool YN = false;
	char CSch[Schstu][25];
	cout << "您要学生插入的班级是：";
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
	for (int sb = 0; sb < Length; sb++)
	{
		if (StrCompare(classId, CSch[sb]))
		{
			YN = true;
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

				infile >> claT.student[i].name;
				infile.ignore();

				int i_sex;
				infile >> i_sex;
				claT.student[i].sex = (Sex)i_sex;
				infile.ignore();

				infile >> claT.student[i].age;
				infile.ignore();

				infile >> claT.student[i].Tel;
				infile.ignore();

				infile >> claT.student[i].sub.SJ;
				infile.ignore();

				infile >> claT.student[i].sub.LS;
				infile.ignore();

				infile >> claT.student[i].sub.GL;
				infile.ignore();

				infile >> claT.student[i].sub.DL;
				infile.ignore();

				infile >> claT.student[i].sub.YY;
				//getchar();

				i++;

			}
			infile.close();

			//插入学生
			int i_sex;
			ofstream outfile;
			outfile.open(classId, ios::out);
			outfile << lenth + 1;
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
			struct Student stu;
			cout << "请输入插入学生的ID：";
			cin >> stu.Id;
			outfile << '\n' << stu.Id;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的姓名：";
			cin >> stu.name;
			outfile << stu.name;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的性别(0代表男生，1代表女生)：";
			cin >> i_sex;
			while (i_sex != 0 && i_sex != 1)
			{
				cout << "没有这类人，请核对信息后再输入...";
				cin >> i_sex;
			}
			stu.sex = (Sex)i_sex;
			outfile << stu.sex;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的年龄：";
			cin >> stu.age;
			outfile << stu.age;
			outfile << '\0';
			//getchar();

			cout << "请输入学生的电话：";
			cin >> stu.Tel;
			outfile << stu.Tel;
			outfile << '\0';
			//getchar();

			stu.sub.DL = 0.0;
			stu.sub.SJ = 0.0;
			stu.sub.GL = 0.0;
			stu.sub.LS = 0.0;
			stu.sub.YY = 0.0;
			outfile << stu.sub.SJ << '\0';
			outfile << stu.sub.LS << '\0';
			outfile << stu.sub.GL << '\0';
			outfile << stu.sub.DL << '\0';
			outfile << stu.sub.YY;
			cout << endl;
			cout << "插入完成！" << endl;

			outfile.close();
			return YN;
		}
	}
	if (!YN)
	{
		cout << "您输入的班级不存在，请核对后再输入..." << endl;
	}
	return YN;
}

void Deletestu()
{
	cout << "您要删除的学生所在的班级是：";
	char classId[Id_num];
	cin >> classId;
	getchar();//取走回车 

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

		infile >> claT.student[i].name;
		infile.ignore();

		int i_sex;
		infile >> i_sex;
		claT.student[i].sex = (Sex)i_sex;
		infile.ignore();

		infile >> claT.student[i].age;
		infile.ignore();

		infile >> claT.student[i].Tel;
		infile.ignore();

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
	}//end while
	infile.close();
	//删除学生
	bool YD = true;
	ofstream outfile;
	outfile.open(classId, ios::out);
	outfile << lenth - 1;
	cout << "请输入您要删除的学生ID:";
	unsigned long long id;
	cin >> id;
	for (int i = 0; i < lenth; i++)
	{
		if (id != claT.student[i].Id)
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
		else
			YD = false;
	}
	outfile.close();
	if (YD)
		cout << "ID:" << id << "不存在..." << endl;
	else
		cout << "已删除ID为" << id << "的学生" << endl;
}
//

#endif