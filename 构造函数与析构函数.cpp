#include"iostream"
using namespace std;

class time
{
	private:
		int hour;
		int minute;
		int second;
public:
	time(int h, int m, int s);
	~time();
};

time :: time(int h,int m,int s):hour(h),minute(m),second(s)
{
	cout << "time created at " << hour << ":" << minute << ":" << second << endl;
}

time :: ~time()
{
	cout << "time destruct at " << hour << ":" << minute << ":" << second << endl;
}

class date
{private:
	int year;
	int mon;
	int day;
public:
	date(int y, int m, int d);
	~date();
}yestaday(2016,4,23);

date :: date(int y,int m,int d):year(y),mon(m),day(d)
{
	time t(11, 11, 11); // ����date���캯���ж�����time�Ķ���
	static time t1(12, 12, 12);//����date���캯���ж���time�ľ�̬����
	cout << "date created " << year << "," << mon << "," << day << endl;
}

date :: ~date()
{
	cout << "date destruct " << year << "," << mon << "," << day << endl;
}

int  main(int argc,char * argv[])
{
	date today(2016, 4, 24);
	return 0;
}