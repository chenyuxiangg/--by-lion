#pragma once
#ifndef GRADE_H
#define GRADE_H
#include "Server.h"

//�����ӿ�
bool Setgress();
void Setsinglegre();
//

//��������
bool Setgress()
{
	bool YN = false;
	char CSch[Schstu][25];
	cout << "��������Ҫ�Ǽǳɼ��İ༶�ţ�";
	char classId[Id_num];
	cin >> classId;
	getchar();//ȡ�߻س�
			  //�򿪰༶���ļ������༶���Ƿ����
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//��ȡ���а༶��
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
			//��ȡ����༶����ѧ������Ϣ
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

			//���óɼ�������ԭ�ļ�
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

				cout << "������IDΪ" << claT.student[j].Id << "ѧ���ĳɼ���" << endl;
				cout << "���ݽṹ��";
				cin >> claT.student[j].sub.SJ;
				cout << "��ɢ��ѧ��";
				cin >> claT.student[j].sub.LS;
				cout << "����ͳ�ƣ�";
				cin >> claT.student[j].sub.GL;
				cout << "Ӣ�";
				cin >> claT.student[j].sub.YY;
				cout << "��·��";
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
		cout << "������İ༶�����ڣ���˶Ժ�����..." << endl;
	return YN;

}

void Setsinglegre()
{
	bool YD = false;
	char CSch[Schstu][25];
	cout << "��������Ҫ�Ǽǳɼ���ѧ�����ڵİ༶�ţ�";
	char classId[Id_num];
	cin >> classId;
	getchar();//ȡ�߻س�

			  //�򿪰༶���ļ������༶���Ƿ����
	inSch.open("all.txt", ios::in);
	char wlen[25];
	int Length;
	inSch >> wlen;
	istringstream i_Len(wlen);
	i_Len >> Length;
	//��ȡ���а༶��
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
			cout << "��������Ҫ�޸ĳɼ���ѧ��ID:";
			unsigned long long id;
			cin >> id;
			getchar();
			int i_sex;

			char csub = 'y';
			while (csub != 'n' && csub != 'N' && csub != '��')
			{//��ȡ����༶����ѧ������Ϣ
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
				//�޸�ѧ���ɼ�
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
						cout << "  1.���ݽṹ            2.��ɢ��ѧ" << endl;
						cout << "  3.����ͳ��            4.Ӣ��    " << endl;
						cout << "  5.��·               6.�ݲ��޸�         " << endl;
						cout << "======================================" << endl;
						cout << "��������Ҫ�޸ĵĿ�Ŀ��ţ�";
						char subject;
						cin >> subject;
						switch (subject)
						{
						case '1':
							cout << "���ݽṹ��";
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
							cout << "��ɢ��ѧ��";
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
							cout << "����ͳ�ƣ�";
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
							cout << "Ӣ�";
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
							cout << "��·��";
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
							cout << "������������";
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
					cout << "�����޸ĸ�ѧ���ĳɼ�ô��" << endl;
					cin >> csub;
				}
				else
				{
					cout << "��ѧ��������..." << endl;
					break;
				}
			}//end while
			break;
		}
	}
	if (!YD)
		cout << "������İ༶�Ų����ڣ���˶�..." << endl;

}
//

#endif