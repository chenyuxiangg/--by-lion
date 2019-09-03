/*����������Ķ��巽���������๹�캯���Լ����������Ķ��巽��

�������������һ��person�࣬�����������Ա���������ԣ�����person����������ʦ���ѧ���ࡣ
��ʦ�����ӹ��š�ְ�ƺ͹�����Ϣ�ȣ�ѧ��������ѧ�š��༶��רҵ����ѧ�ɼ���*/

#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	person(string n, string s, int a);
	~person();
	void getname() const;
	void getsex() const;
	void getage() const;

private:
	string name;
	string sex;
	int age;
};

person::person(string n, string s, int a) :name(n), sex(s), age(a)
{}

person :: ~person()
{
	cout << "����person��������" << endl;
}

void person::getname() const  //���峣������ʱҲ��Ҫ�� const д��
{
	cout << "name:" << name << endl;
}

void person::getsex() const
{
	cout << "sex:" << sex << endl;
}

void person::getage() const
{
	cout << "age:" << age << endl;
}

//�����ࣺstudents   teachers
class students : public person  //ѧ��������ѧ�š��༶��רҵ����ѧ�ɼ�
{
public:
	students(string n, string s, int a, long int N, string C, string M, float S);//��Ҫ��person��ԱҲ��ʼ��
	~students();
	void getNum() const;
	void getClass() const;
	void getMajor() const;
	void getScore() const;
	void setNum();
private:
	long int Num;
	string Class;
	string Major;
	float Score;

};

students::students(string n, string s, int a, long int N, string C, string M, float S) :person(n, s, a), Num(N), Class(C), Major(M), Score(S)
{}  //��ʼ������������ݳ�Աʱ��Ҫ�ȳ�ʼ����������ݳ�Ա

students :: ~students()
{
	cout << "����students����������" << endl;
}

void students::getNum() const
{
	cout << "ѧ�ţ�" << Num << endl;
}

void students::getMajor() const
{
	cout << "רҵ��" << Major << endl;
}

void students::getClass() const
{
	cout << "�༶��" << Class << endl;
}

void students::getScore() const
{
	cout << "�ɼ���" << Score << endl;
}

void students :: setNum()
{
	cout << "������ѧ��ѧ�ţ�";
	cin >> Num;
}

class teacher : public person //��ʦ�����ӹ��š�ְ�ƺ͹�����Ϣ��
{
public:
	teacher(string n, string s, int a, long int Tnum, string Title, int money);
	~teacher()
	{
		cout << "����teacher����������" << endl;
	}
	void getTnum() const;
	void getTitle() const;
	void getmoney() const;

private:
	long int Tnum;
	string Title;
	int money;
};

teacher::teacher(string n, string s, int a, long int Tnum, string Title, int money) :person(n, s, a), Tnum(Tnum), Title(Title), money(money)
{}

void teacher::getTnum() const
{
	cout << "���ţ�" << Tnum << endl;
}

void teacher::getTitle() const
{
	cout << "ְ�ƣ�" << Title << endl;
}

void teacher::getmoney() const
{
	cout << "���ʣ�" << money << endl;
}

int main(int argc, int argv[])
{
	students A("�", "��", 15, 16170210001, "��һ", "��ѧ", 95.5);

	A.getname();
	A.getsex();
	A.setNum();
	A.getNum();

	return 0;
}