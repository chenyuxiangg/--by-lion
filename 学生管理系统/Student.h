#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Server.h"

//�����ӿ�
bool Insertmag();
void Deletestu();
//

//��������
bool Insertmag()
{
	bool YN = false;
	char CSch[Schstu][25];
	cout << "��Ҫѧ������İ༶�ǣ�";
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
			YN = true;
			ifstream infile;
			infile.open(classId, ios::in);
			struct Class claT;
			//��ȡ����༶����ѧ������Ϣ
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

			//����ѧ��
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
			cout << "���������ѧ����ID��";
			cin >> stu.Id;
			outfile << '\n' << stu.Id;
			outfile << '\0';
			//getchar();

			cout << "������ѧ����������";
			cin >> stu.name;
			outfile << stu.name;
			outfile << '\0';
			//getchar();

			cout << "������ѧ�����Ա�(0����������1����Ů��)��";
			cin >> i_sex;
			while (i_sex != 0 && i_sex != 1)
			{
				cout << "û�������ˣ���˶���Ϣ��������...";
				cin >> i_sex;
			}
			stu.sex = (Sex)i_sex;
			outfile << stu.sex;
			outfile << '\0';
			//getchar();

			cout << "������ѧ�������䣺";
			cin >> stu.age;
			outfile << stu.age;
			outfile << '\0';
			//getchar();

			cout << "������ѧ���ĵ绰��";
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
			cout << "������ɣ�" << endl;

			outfile.close();
			return YN;
		}
	}
	if (!YN)
	{
		cout << "������İ༶�����ڣ���˶Ժ�������..." << endl;
	}
	return YN;
}

void Deletestu()
{
	cout << "��Ҫɾ����ѧ�����ڵİ༶�ǣ�";
	char classId[Id_num];
	cin >> classId;
	getchar();//ȡ�߻س� 

	ifstream infile;
	infile.open(classId, ios::in);
	struct Class claT;
	//��ȡ����༶����ѧ������Ϣ
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
	//ɾ��ѧ��
	bool YD = true;
	ofstream outfile;
	outfile.open(classId, ios::out);
	outfile << lenth - 1;
	cout << "��������Ҫɾ����ѧ��ID:";
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
		cout << "ID:" << id << "������..." << endl;
	else
		cout << "��ɾ��IDΪ" << id << "��ѧ��" << endl;
}
//

#endif