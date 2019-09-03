#pragma once
#ifndef SERVER_AND_SORT_H
#define SERVER_AND_SORT_H
#include "Server.h"

//�����ӿ�
bool Serchstu();
void Sort();
void Sort_Schl();
void Serch_Schl();
void StackQuicksort();
//

//��������
bool Serchstu()
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

	for(int j = 0;j < sa;j++)
	{
		if(StrCompare(classId,CSch[j]))
		{
			claexit = true;
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

			//����

			cout << "��������Ҫ���ҵ�ѧ��ID:";
			unsigned long long id;
			cin >> id;
			for (int i = 0; i < lenth; i++)
			{
				if (id == claT.student[i].Id)
				{
					cout << "ѧ��������" << claT.student[i].name << endl;
					cout << "ѧ��ID��" << claT.student[i].Id << endl;
					if (claT.student[i].sex == 0)
					{
						cout << "ѧ���Ա�" << "��" << endl;
					}
					else
					{
						cout << "ѧ���Ա�" << "Ů" << endl;
					}
					cout << "ѧ�����䣺" << claT.student[i].age << endl;
					cout << "ѧ���绰��" << claT.student[i].Tel << endl;
					cout << "ѧ�����ݽṹ�ɼ���" << claT.student[i].sub.SJ << endl;
					cout << "ѧ����ɢ��ѧ�ɼ���" << claT.student[i].sub.LS << endl;
					cout << "ѧ������ͳ�Ƴɼ���" << claT.student[i].sub.GL << endl;
					cout << "ѧ��Ӣ��ɼ���" << claT.student[i].sub.YY << endl;
					cout << "ѧ����·�ɼ���" << claT.student[i].sub.DL << endl;
					return true;
				}

			}
			cout << "��ѧ������" << classId << "�༶" << endl;
			return false;
		}//if
	}//for
	if (!claexit)
		cout << "����İ༶������..." << endl;
	return claexit;
}

void Sort()
{
	bool enable = true;//��ʾ�Ѿ�����
	cout << "��������Ҫ����İ༶�ţ�";
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
	for (int j = 0; j < sa; j++)
	{
		if(StrCompare(classId,CSch[j]))
		{
			claexit = true;
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

			//����
			char ch;
			cout << "��Ҫ���ĸ��ɼ�����" << endl;
			cout << "======================================" << endl;
			cout << "  1.����ͳ�Ƴɼ�            2.Ӣ��ɼ�    " << endl;
			cout << "  3.��·�ɼ�                4.���ݽṹ�ɼ� " << endl;
			cout << "  5.��ɢ��ѧ�ɼ�            6.����������    " << endl;
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
				cout << "������������" << endl;
				break;
			}
			//��������ѧ���ɼ�д���ļ�
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
				cout << "����ɹ���" << endl;
			}
		}
	}//for

	if (!claexit)
		cout << "����İ༶������..." << endl;
}

//�꼶�ϵ����򲻴����ļ��������ֱ�����
void Sort_Schl()
{
	bool enable = true;//��ʾ�Ѿ�����
	//ֱ��ʹ��char CSch[Schstu][25]������Schstu���������ջ���
	//һ����˵����Ӧ���ô���100�����飬��Ҫ��ˣ��������
	char CSch[Class_num][25];//������ȡ���а༶��

							 //�򿪰༶���ļ�����ȡ���а༶��Ϣ
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

	ifstream Cinfile;
	int i_stunum = 0;
	struct Student* Astu = new struct Student[Schstu];
	//������ѧ����ȡ������Astu��
	for (int sb = 0; sb < sa; sb++)
	{
		Cinfile.open(CSch[sb], ios::in);
		char Slen[25];
		Cinfile >> Slen;//Ŀ���ǽ�����Ƶ���һ��

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

	 //����
	char ch;
	cout << "��Ҫ���ĸ��ɼ�����" << endl;
	cout << "======================================" << endl;
	cout << "  1.����ͳ�Ƴɼ�            2.Ӣ��ɼ�    " << endl;
	cout << "  3.��·�ɼ�                4.���ݽṹ�ɼ� " << endl;
	cout << "  5.��ɢ��ѧ�ɼ�            6.����������    " << endl;
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
		cout << "������������" << endl;
		break;
	}

	//���������ѧ����Ϣ
	if(enable)
	{
		int stop = 0;
		cout << "===================================" << endl;
		for (int i_s = 0; i_s < i_stunum; i_s++)
		{
			stop++;
			cout << endl;
			cout << "ѧ��ID��";
			cout << Astu[i_s].Id << endl;

			cout << "ѧ��������";
			cout << Astu[i_s].name << endl;

			cout << "ѧ���Ա�";
			if (Astu[i_s].sex == 0)
				cout << "��" << endl;
			else
				cout << "Ů" << endl;

			cout << "ѧ�����䣺";
			cout << Astu[i_s].age << endl;

			cout << "ѧ���绰��";
			cout << Astu[i_s].Tel << endl;

			cout << "*******�ɼ�*******" << endl;
			cout << "���ݽṹ��";
			cout << Astu[i_s].sub.SJ << endl;

			cout << "��ɢ��ѧ��";
			cout << Astu[i_s].sub.LS << endl;

			cout << "����ͳ�ƣ�";
			cout << Astu[i_s].sub.GL << endl;

			cout << "Ӣ�";
			cout << Astu[i_s].sub.YY << endl;

			cout << "��·��";
			cout << Astu[i_s].sub.DL << endl;
			cout << "====================================" << endl;
			if (stop % 5 == 0)
			{
				cout << "����" << i_stunum - stop << "����¼��������������鿴" << endl;
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
	char CSch[Class_num][25];//������ȡ���а༶��

							 //�򿪰༶���ļ�����ȡ���а༶��Ϣ
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

	ifstream Cinfile;
	int i_stunum = 0;
	struct Student* Astu = new struct Student[Schstu];
	//������ѧ����ȡ������Astu��
	for (int sb = 0; sb < sa; sb++)
	{
		Cinfile.open(CSch[sb], ios::in);
		char Slen[25];
		Cinfile >> Slen;//Ŀ���ǽ�����Ƶ���һ��

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

	 //����ѧ��
	cout << "��������Ҫ���ҵ�ѧ����ID��";
	bool YD = false;
	unsigned long long StuID;
	cin >> StuID;

	for (int sa = 0; sa < i_stunum; sa++)
	{
		if (StuID == Astu[sa].Id)
		{
			YD = true;
			cout << endl;
			cout << "ѧ��ID��";
			cout << Astu[sa].Id << endl;

			cout << "ѧ��������";
			cout << Astu[sa].name << endl;

			cout << "ѧ���Ա�";
			if (Astu[sa].sex == 0)
				cout << "��" << endl;
			else
				cout << "Ů" << endl;

			cout << "ѧ�����䣺";
			cout << Astu[sa].age << endl;

			cout << "ѧ���绰��";
			cout << Astu[sa].Tel << endl;

			cout << "*******�ɼ�*******" << endl;
			cout << "���ݽṹ��";
			cout << Astu[sa].sub.SJ << endl;

			cout << "��ɢ��ѧ��";
			cout << Astu[sa].sub.LS << endl;

			cout << "����ͳ�ƣ�";
			cout << Astu[sa].sub.GL << endl;

			cout << "Ӣ�";
			cout << Astu[sa].sub.YY << endl;

			cout << "��·��";
			cout << Astu[sa].sub.DL << endl;
			break;
		}
	}
	delete[] Astu;
	Astu = NULL;
	if (!YD)
		cout << "�����ҵ�ID��" << StuID << "�������ڱ��꼶����˶�..." << endl;

}

void StackQuicksort()
{
	bool enable = true;//��ʾ�Ѿ��ź���
	char CSch[Class_num][25];//������ȡ���а༶��

							 //�򿪰༶���ļ�����ȡ���а༶��Ϣ
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

	ifstream Cinfile;
	int i_stunum = 0;
	struct Student* Astu = new struct Student[Schstu];
	//������ѧ����ȡ������Astu��
	for (int sb = 0; sb < sa; sb++)
	{
		Cinfile.open(CSch[sb], ios::in);
		char Slen[25];
		Cinfile >> Slen;//Ŀ���ǽ�����Ƶ���һ��

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

	 //����
	char ch;
	cout << "��Ҫ���ĸ��ɼ�����" << endl;
	cout << "======================================" << endl;
	cout << "  1.����ͳ�Ƴɼ�            2.Ӣ��ɼ�    " << endl;
	cout << "  3.��·�ɼ�                4.���ݽṹ�ɼ� " << endl;
	cout << "  5.��ɢ��ѧ�ɼ�            6.����������    " << endl;
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
		cout << "������������" << endl;
		break;
	}

	//������������ѧ����Ϣ��ջ
	Mystack<Student> stack(Schstu);
	for (int Si = 0; Si < i_stunum; Si++)
		stack.input(Astu[Si]);

	if(enable)
	{
		//���ѧ����Ϣ
		while (!stack.stackempty())
		{
			Student elem;
			stack.outstack(elem);

			cout << endl;
			cout << "ѧ��ID��";
			cout << elem.Id << endl;

			cout << "ѧ��������";
			cout << elem.name << endl;

			cout << "ѧ���Ա�";
			if (elem.sex == 0)
				cout << "��" << endl;
			else
				cout << "Ů" << endl;

			cout << "ѧ�����䣺";
			cout << elem.age << endl;

			cout << "ѧ���绰��";
			cout << elem.Tel << endl;

			cout << "*******�ɼ�*******" << endl;
			cout << "���ݽṹ��";
			cout << elem.sub.SJ << endl;

			cout << "��ɢ��ѧ��";
			cout << elem.sub.LS << endl;

			cout << "����ͳ�ƣ�";
			cout << elem.sub.GL << endl;

			cout << "Ӣ�";
			cout << elem.sub.YY << endl;

			cout << "��·��";
			cout << elem.sub.DL << endl;
			cout << "====================================" << endl;
		}
	}
	
	delete[] Astu;
	Astu = NULL;
}

#endif