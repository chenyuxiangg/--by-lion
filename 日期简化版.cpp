/*
定义一个struct Date以保存日期，提供一些函数，从输入读Date，向输出写Date，以及用一个日期去初始化Date
*/
#include <iostream>
using namespace std;

//日期结构体
struct Date {
	int year;
	int month;
	int day;
	int hour;
	int minu;
	double sec;

	Date() :
		year(2018), month(4), day(2), hour(18), minu(14), sec(0.0) {}
};

//读入日期
void Input_date(Date& date)
{
	cin >> date.year >> date.month >> date.day >> date.hour
		>> date.minu >> date.sec;
}


//输出日期
void Output(const Date date)
{
	cout << date.year << "年 - ";
	if (date.month < 10)
		cout << "0" << date.month << "月 - ";
	else
		cout << date.month << "月 - ";
	if (date.day < 10)
		cout << "0" << date.day << "日 - ";
	else
		cout << date.day << "日 - ";
	if (date.hour < 10)
		cout << "0" << date.hour << " : ";
	else
		cout << date.hour << " : ";
	if (date.minu < 10)
		cout << "0" << date.minu << " : ";
	else
		cout << date.minu << " : ";
	cout << date.sec << endl;

}

//驱动程序
int main(int argc, char* argv[])
{
	Date date;
	Input_date(date);
	Output(date);

	system("pause");
	return 0;
}