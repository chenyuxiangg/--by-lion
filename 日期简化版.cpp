/*
����һ��struct Date�Ա������ڣ��ṩһЩ�������������Date�������дDate���Լ���һ������ȥ��ʼ��Date
*/
#include <iostream>
using namespace std;

//���ڽṹ��
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

//��������
void Input_date(Date& date)
{
	cin >> date.year >> date.month >> date.day >> date.hour
		>> date.minu >> date.sec;
}


//�������
void Output(const Date date)
{
	cout << date.year << "�� - ";
	if (date.month < 10)
		cout << "0" << date.month << "�� - ";
	else
		cout << date.month << "�� - ";
	if (date.day < 10)
		cout << "0" << date.day << "�� - ";
	else
		cout << date.day << "�� - ";
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

//��������
int main(int argc, char* argv[])
{
	Date date;
	Input_date(date);
	Output(date);

	system("pause");
	return 0;
}