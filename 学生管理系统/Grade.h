#pragma once
#ifndef GRADE_H
#define GRADE_H
#include "Server.h"

//函数接口
bool Setgress();
void Setsinglegre();
//

//函数定义
bool Setgress()
{
	bool YN = false;
	char CSch[Schstu][25];
	cout << "请输入您要登记成绩的班级号：";
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
	for (int sb = 0; sb < Length; sb++)
	{
		if (StrCompare(classId, CSch[sb]))
		{
			YN = true;
			ifstream infile;
			infile.open(classId, ios::in);
			//提取这个班级所有学生的信息
			struct Class claT;
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

			}
			infile.close();

			//设置成绩，覆盖原文件
			ofstream outfile;
			outfile.open(classId, ios::out);
			outfile << lenth;
			for (int j = 0; j < lenth; j++)
			{
				outfile << '\n' << claT.student[j].Id;
				outfile << '\0';

				outfile << claT.student[j].name;
				outfile << '\0';

				int i_sex;
				i_sex = claT.student[j].sex;
				outfile << i_sex;
				outfile << '\0';

				outfile << claT.student[j].age;
				outfile << '\0';

				outfile << claT.student[j].Tel;
				outfile << '\0';

				cout << "请输入ID为" << claT.student[j].Id << "学生的成绩：" << endl;
				cout << "数据结构：";
				cin >> claT.student[j].sub.SJ;
				cout << "离散数学：";
				cin >> claT.student[j].sub.LS;
				cout << "概率统计：";
				cin >> claT.student[j].sub.GL;
				cout << "英语：";
				cin >> claT.student[j].sub.YY;
				cout << "电路：";
				cin >> claT.student[j].sub.DL;
				outfile << claT.student[j].sub.SJ << '\0';
				outfile << claT.student[j].sub.LS << '\0';
				outfile << claT.student[j].sub.GL << '\0';
				outfile << claT.student[j].sub.DL << '\0';
				outfile << claT.student[j].sub.YY;

			}
			outfile.close();
			inSch.close();
			return YN;
		}//end if
	}//end for
	inSch.close();
	if (!YN)
		cout << "您输入的班级不存在，请核对后再试..." << endl;
	return YN;

}

void Setsinglegre()
{
	bool YD = false;
	char CSch[Schstu][25];
	cout << "请输入您要登记成绩的学生所在的班级号：";
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
			YD = true;
			cout << "请输入您要修改成绩的学生ID:";
			unsigned long long id;
			cin >> id;
			getchar();
			int i_sex;

			char csub = 'y';
			while (csub != 'n' && csub != 'N' && csub != '否')
			{//提取这个班级所有学生的信息
				ifstream infile;
				infile.open(classId, ios::in);
				struct Class claT;
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
				}
				infile.close();
				//修改学生成绩
				bool stuexit = false;
				ofstream outfile;
				outfile.open(classId, ios::out);
				outfile << lenth;
				for (int i = 0; i < lenth; i++)
				{
					if (id == claT.student[i].Id)
					{
						stuexit = true;
						cout << "======================================" << endl;
						cout << "  1.数据结构            2.离散数学" << endl;
						cout << "  3.概率统计            4.英语    " << endl;
						cout << "  5.电路               6.暂不修改         " << endl;
						cout << "======================================" << endl;
						cout << "请输入需要修改的科目序号：";
						char subject;
						cin >> subject;
						switch (subject)
						{
						case '1':
							cout << "数据结构：";
							cin >> claT.student[i].sub.SJ;
							outfile << '\n' << claT.student[i].Id;
							outfile << '\0';

							outfile << claT.student[i].name;
							outfile << '\0';

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
							break;
						case '2':
							cout << "离散数学：";
							cin >> claT.student[i].sub.LS;
							outfile << '\n' << claT.student[i].Id;
							outfile << '\0';

							outfile << claT.student[i].name;
							outfile << '\0';

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
							break;
						case '3':
							cout << "概率统计：";
							cin >> claT.student[i].sub.GL;
							outfile << '\n' << claT.student[i].Id;
							outfile << '\0';

							outfile << claT.student[i].name;
							outfile << '\0';

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
							break;
						case '4':
							cout << "英语：";
							cin >> claT.student[i].sub.YY;
							outfile << '\n' << claT.student[i].Id;
							outfile << '\0';

							outfile << claT.student[i].name;
							outfile << '\0';

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
							break;
						case '5':
							cout << "电路：";
							cin >> claT.student[i].sub.DL;
							outfile << '\n' << claT.student[i].Id;
							outfile << '\0';

							outfile << claT.student[i].name;
							outfile << '\0';

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
							break;
						case '6':
							outfile << '\n' << claT.student[i].Id;
							outfile << '\0';

							outfile << claT.student[i].name;
							outfile << '\0';

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
							break;
						default:
							cout << "您的输入有误！";
							break;

						}//end switch
						system("cls");
					}//if
					else
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
				}//end for
				outfile.close();
				if (stuexit)
				{
					cout << "继续修改该学生的成绩么？" << endl;
					cin >> csub;
				}
				else
				{
					cout << "该学生不存在..." << endl;
					break;
				}
			}//end while
			break;
		}
	}
	if (!YD)
		cout << "你输入的班级号不存在，请核对..." << endl;

}
//

#endif