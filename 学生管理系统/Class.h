#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "Server.h"

//�����ӿ�
void Setclassmag();
bool DeleteAll();
void Traverse();
//

//��������
void Setclassmag()
{
	int i_Sch = 0;
	char CSch[Schstu][25];
	char Cch = 'y';
	while (Cch == 'y')
	{
		cout << "����������Ҫ�Ǽǵİ༶�ţ�";
		char classId[Id_num];
		cin >> classId;
		getchar();//ȡ�߻س�
				  //���༶�Ŵ����ļ���ʹ�༶����һ��������а༶�ŵ��ļ�Ϊ  all.txt
		inSch.open("all.txt", ios::in);
		//if(!Sch.is_open())
		//cout << "not Right" << endl;
		char wlen[25];
		int Length;
		inSch >> wlen;
		inSch.close();

		istringstream i_Len(wlen);
		i_Len >> Length;
		/*������Ҫע�⣺��ֱ����out��һ���ļ����������κβ���ֱ�ӹرյĻ������ܻὫ�ļ���ԭ�е�
		�����ÿ�.����ͬʱʹ��ios::out ��ios::in��������ļ�ʧ��.�����ļ�����������ʱ������Ҫ�ճ�
		��һ�У����س�֮ǰ���κ�����ʱ���س�ʧЧ.ios::ate�򿪵Ĳ����ļ�ĩβ������Ҫ��֤��������ô���£�
		*/
		if (Length == 0)
		{
			outSch.open("all.txt", ios::out);
			outSch << Length;//�����ȴ���ȥ
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
			//��ȡ���а༶��
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
			//�ж�����İ༶�Ƿ���ڣ����������½�һ��
			//�����µİ༶��ԭ���İ༶�����ļ�
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
			cerr << "�ļ���ʧ�ܣ�";
		outfile << 0;
		int i = 0;
		char ch = 'y';
		struct Class Cla;
		int i_sex;
		while (i != Student_num && ch == 'y')
		{
			i++;
			cout << "������Ǽ�ѧ����ID��";
			cin >> Cla.student[i].Id;
			outfile << '\n' << Cla.student[i].Id;
			outfile << '\0';
			//getchar();

			cout << "������ѧ����������";
			cin >> Cla.student[i].name;
			outfile << Cla.student[i].name;
			outfile << '\0';
			//getchar();

			//getchar();
			cout << "������ѧ�����Ա�(0����������1����Ů��)��";
			cin >> i_sex;
			while (i_sex != 0 && i_sex != 1)
			{
				cout << "û�������ˣ���˶���Ϣ��������..." << endl;
				cin >> i_sex;
			}
			Cla.student[i].sex = (Sex)i_sex;
			outfile << Cla.student[i].sex;
			outfile << '\0';
			//getchar();

			cout << "������ѧ�������䣺";
			cin >> Cla.student[i].age;
			outfile << Cla.student[i].age;
			outfile << '\0';
			//getchar();

			cout << "������ѧ���ĵ绰��";
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


			cout << "����ѧ����Ҫ�Ǽ�ô��";
			cin >> ch;
		}
		outfile.seekp(ios::beg);
		outfile << i;
		outfile.close();
		if (i == Student_num)
			cout << "�ð༶ѧ�������Ѵ����ޣ�" << endl;
		cout << "���Ƿ���Ҫ��������༶��";
		cin >> Cch;
		system("cls");
	}
}

bool DeleteAll()
{
	int i_Sch;
	bool YN = false;
	char CSch[20][25];
	cout << "����������ɾ���İ༶�ţ�";
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

	i_Sch = Length;
	outSch.open("all.txt", ios::out);
	outSch << i_Sch;
	for (int sb = 0; sb < Length; sb++)
	{
		if (StrCompare(classId, CSch[sb]))//�˴����ܵ��ڣ�Ӧд�����ж�
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
		cout << "������İ༶�Ų����ڣ���˶Ժ�����..." << endl;
	else
		cout << "��ɾ��IDΪ" << classId << "�İ༶" << endl;
	return YN;

}

void Traverse()
{
	cout << "��������Ҫ�鿴�İ༶�ţ�";
	char classId[Id_num];
	cin >> classId;
	getchar();//ȡ�߻س�

	//�򿪰༶���ļ������༶���Ƿ����
	char CSch[20][25];//��ȡ�༶�ŵ�����
	bool claexit = false;
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
	//
	for(int i = 0;i < sa;i++)
	{
		if(StrCompare(classId,CSch[i]))
		{
			claexit = true;
			cout << "|   ѧ��   |   ����   |   �Ա�   |   ����   |   �绰   |";
			cout << "   ����   |   ��ɢ   |   ����   |   ��·   |   Ӣ��   |" << endl;
			cout << "========================================================";
			cout << "========================================================" << endl;
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
				cout << claT.student[i].Id << " ";

				infile >> claT.student[i].name;
				infile.ignore();
				cout << "  "<< claT.student[i].name << " ";

				int i_sex;
				infile >> i_sex;
				claT.student[i].sex = (Sex)i_sex;
				infile.ignore();
				if (claT.student[i].sex == 0)
					cout << "      " << "��" << "     ";
				else
					cout << "      " << "Ů" << "     ";

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
		cout << "����İ༶������..." << endl;
}

#endif