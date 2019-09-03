/*掌握派生类的定义方法和派生类构造函数以及析构函数的定义方法

需求分析：定义一个person类，具有姓名、性别、年龄等属性，再由person类派生出教师类和学生类。
教师类增加工号、职称和工资信息等，学生类增加学号、班级和专业和入学成绩。*/

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
	cout << "调用person析构函数" << endl;
}

void person::getname() const  //定义常量函数时也需要将 const 写出
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

//派生类：students   teachers
class students : public person  //学生类增加学号、班级和专业和入学成绩
{
public:
	students(string n, string s, int a, long int N, string C, string M, float S);//需要将person成员也初始化
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
{}  //初始化派生类的数据成员时，要先初始化基类的数据成员

students :: ~students()
{
	cout << "调用students的析构函数" << endl;
}

void students::getNum() const
{
	cout << "学号：" << Num << endl;
}

void students::getMajor() const
{
	cout << "专业：" << Major << endl;
}

void students::getClass() const
{
	cout << "班级：" << Class << endl;
}

void students::getScore() const
{
	cout << "成绩：" << Score << endl;
}

void students :: setNum()
{
	cout << "请输入学生学号：";
	cin >> Num;
}

class teacher : public person //教师类增加工号、职称和工资信息等
{
public:
	teacher(string n, string s, int a, long int Tnum, string Title, int money);
	~teacher()
	{
		cout << "调用teacher的析构函数" << endl;
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
	cout << "工号：" << Tnum << endl;
}

void teacher::getTitle() const
{
	cout << "职称：" << Title << endl;
}

void teacher::getmoney() const
{
	cout << "工资：" << money << endl;
}

int main(int argc, int argv[])
{
	students A("李华", "男", 15, 16170210001, "高一", "化学", 95.5);

	A.getname();
	A.getsex();
	A.setNum();
	A.getNum();

	return 0;
}