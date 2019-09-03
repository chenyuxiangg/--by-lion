#include "iostream"
#include "string"
using namespace std;

class Date
{
	int month;
	int day;
	int year;

public:
	Date(int m, int d, int y);
	Date(Date& date);
	void display();
	friend void modifydate(Date& date, int m, int y, int d);//声明非成员函数友元
};

//类外定义非成员函数友元
void modifydate(Date& date,int y,int m,int d)
{
	date.month = m;
	date.day = d;
	date.year = y;
}

Date :: Date(int y,int m,int d):month(m),year(y),day(d)
{}

Date :: Date(Date& date)
{
	month = date.month;
	year = date.year;
	day = date.day;
}

void Date :: display()
{
	cout << year << "-" << month << "-" << day << endl;
}

int main(int argc,int argv[])
{
	Date date1(2012, 10, 12);
	Date date2 = date1;
	date1.display();
	date2.display();
	modifydate(date1, 2013, 10, 12);
	modifydate(date2, 2013, 10, 12);
	date1.display();
	date2.display();

	return 0;
}